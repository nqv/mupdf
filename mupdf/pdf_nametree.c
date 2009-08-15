#include "fitz.h"
#include "mupdf.h"

static int
pdf_lookupdestimp(fz_obj *node, fz_obj *nameddest, fz_obj **destp)
{
	fz_obj *kids, *names, *limits;

	kids = fz_dictgets(node, "Kids");
	names = fz_dictgets(node, "Names");
	limits = fz_dictgets(node, "Limits");

	*destp = nil;

	if (fz_isarray(limits))
	{
		fz_obj *first = fz_arrayget(limits, 0);
		fz_obj *last = fz_arrayget(limits, 1);

		if (fz_objcmp(first, nameddest) > 0)
			return 1;
		if (fz_objcmp(last, nameddest) < 0)
			return -1;
	}

	if (fz_isarray(kids))
	{
		int l = 0;
		int r = fz_arraylen(kids) - 1;

		while (l <= r)
		{
			int m = (l + r) >> 1;
			int c;
			fz_obj *kid = fz_arrayget(kids, m);

			c = -pdf_lookupdestimp(kid, nameddest, destp);
			if (c < 0)
				r = m - 1;
			else if (c > 0)
				l = m + 1;
			else
				return 0;
		}
	}

	if (fz_isarray(names))
	{
		int l = 0;
		int r = (fz_arraylen(names) / 2) - 1;

		while (l <= r)
		{
			int m = (l + r) >> 1;
			int c;
			fz_obj *key = fz_arrayget(names, m * 2);
			fz_obj *val = fz_arrayget(names, m * 2 + 1);

			c = -fz_objcmp(key, nameddest);
			if (c < 0)
				r = m - 1;
			else if (c > 0)
				l = m + 1;
			else
			{
				*destp = val;
				return 0;
			}
		}
	}

	return -1;
}

fz_obj *
pdf_lookupdest(pdf_xref *xref, fz_obj *nameddest)
{
	fz_obj *dests = fz_dictgets(xref->root, "Dests");
	fz_obj *names = fz_dictgets(xref->root, "Names");
	fz_obj *dest = nil;

	/* PDF 1.1 has destinations in a dictionary */
	if (dests)
	{
		if (fz_isname(nameddest))
			dest = fz_dictget(dests, nameddest);
		else
			dest = fz_dictgets(dests, fz_tostrbuf(nameddest));
	}

	/* PDF 1.2 has destinations in a name tree */
	if (names && !dest)
	{
		fz_obj *desttree = fz_dictgets(names, "Dests");
		if (desttree)
			pdf_lookupdestimp(desttree, nameddest, &dest);
	}

	if (fz_isdict(dest))
		return dest;
	if (fz_isarray(dest))
		return dest;

	return nil;
}
