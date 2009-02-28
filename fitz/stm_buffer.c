#include "fitz_base.h"
#include "fitz_stream.h"

fz_error *
fz_newbuffer(fz_buffer **bp, int size)
{
	fz_buffer *b;

	b = *bp = fz_malloc(sizeof(fz_buffer));
	if (!b)
		return fz_throw("outofmem: buffer struct");

	b->refs = 1;
	b->ownsdata = 1;
	b->bp = fz_malloc(size);
	if (!b->bp)
	{
		fz_free(b);
		return fz_throw("outofmem: buffer memory");
	}

	b->rp = b->bp;
	b->wp = b->bp;
	b->ep = b->bp + size;
	b->eof = 0;

	return fz_okay;
}

fz_error *
fz_newbufferwithmemory(fz_buffer **bp, unsigned char *data, int size)
{
	fz_buffer *b;

	b = *bp = fz_malloc(sizeof(fz_buffer));
	if (!b)
		return fz_throw("outofmem: buffer struct");

	b->refs = 1;
	b->ownsdata = 0;
	b->bp = data;

	b->rp = b->bp;
	b->wp = b->bp + size;
	b->ep = b->bp + size;
	b->eof = 0;

	return fz_okay;
}

fz_buffer *
fz_keepbuffer(fz_buffer *buf)
{
	buf->refs ++;
	return buf;
}

void
fz_dropbuffer(fz_buffer *buf)
{
	if (--buf->refs == 0)
	{
		if (buf->ownsdata)
			fz_free(buf->bp);
		fz_free(buf);
	}
}

fz_error *
fz_growbuffer(fz_buffer *buf)
{
	unsigned char *newbp;

	int rp = buf->rp - buf->bp;
	int wp = buf->wp - buf->bp;
	int ep = buf->ep - buf->bp;

	if (!buf->ownsdata)
		return fz_throw("assert: grow borrowed memory");

	newbp = fz_realloc(buf->bp, ep * 2);
	if (!newbp)
		return fz_throw("outofmem: resize buffer memory");

	buf->bp = newbp;
	buf->rp = buf->bp + rp;
	buf->wp = buf->bp + wp;
	buf->ep = buf->bp + ep * 2;

	return fz_okay;
}

fz_error *
fz_rewindbuffer(fz_buffer *buf)
{
	if (!buf->ownsdata)
		return fz_throw("assert: rewind borrowed memory");

	memmove(buf->bp, buf->rp, buf->wp - buf->rp);
	buf->wp = buf->bp + (buf->wp - buf->rp);
	buf->rp = buf->bp;

	return fz_okay;
}

