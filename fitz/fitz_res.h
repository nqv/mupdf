/*
 *
 */
 
typedef struct fz_path_s fz_path;
typedef struct fz_text_s fz_text;
typedef struct fz_font_s fz_font;
typedef struct fz_image_s fz_image;
typedef struct fz_shade_s fz_shade;
typedef struct fz_colorspace_s fz_colorspace;

typedef enum fz_blendkind_e
{
	/* PDF 1.4 -- standard separable */
	FZ_BNORMAL,
	FZ_BMULTIPLY,
	FZ_BSCREEN,
	FZ_BOVERLAY,
	FZ_BDARKEN,
	FZ_BLIGHTEN,
	FZ_BCOLORDODGE,
	FZ_BCOLORBURN,
	FZ_BHARDLIGHT,
	FZ_BSOFTLIGHT,
	FZ_BDIFFERENCE,
	FZ_BEXCLUSION,

	/* PDF 1.4 -- standard non-separable */
	FZ_BHUE,
	FZ_BSATURATION,
	FZ_BCOLOR,
	FZ_BLUMINOSITY,

	FZ_BOVERPRINT,
	FZ_BRASTEROP
} fz_blendkind;

/*
 * Vector paths.
 * They can be stroked and dashed, or be filled.
 * They have a fill rule (nonzero or evenodd).
 *
 * When rendering, they are flattened, stroked and dashed straight
 * into the Global Edge List.
 */

typedef struct fz_stroke_s fz_stroke;
typedef struct fz_dash_s fz_dash;
typedef union fz_pathel_s fz_pathel;

typedef enum fz_pathkind_e
{
	FZ_STROKE,
	FZ_FILL,
	FZ_EOFILL
} fz_pathkind;

typedef enum fz_pathelkind_e
{
	FZ_MOVETO,
	FZ_LINETO,
	FZ_CURVETO,
	FZ_CLOSEPATH
} fz_pathelkind;

struct fz_stroke_s
{
	int linecap;
	int linejoin;
	float linewidth;
	float miterlimit;
};

struct fz_dash_s
{
	int len;
	float phase;
	float array[FZ_FLEX];
};

union fz_pathel_s
{
	fz_pathelkind k;
	float v;
};

struct fz_path_s
{
	fz_pathkind paint;
	fz_dash *dash;
	int linecap;
	int linejoin;
	float linewidth;
	float miterlimit;
	int len, cap;
	fz_pathel *els;
};

fz_path *fz_newpath(void);
void fz_moveto(fz_path*, float x, float y);
void fz_lineto(fz_path*, float x, float y);
void fz_curveto(fz_path*, float, float, float, float, float, float);
void fz_curvetov(fz_path*, float, float, float, float);
void fz_curvetoy(fz_path*, float, float, float, float);
void fz_closepath(fz_path*);
void fz_setpathstate(fz_path*, fz_pathkind paint, fz_stroke *stroke, fz_dash *dash);
void fz_resetpath(fz_path *path);
void fz_freepath(fz_path *path);

fz_rect fz_boundpath(fz_path *, fz_matrix ctm);
void fz_debugpath(fz_path *, int indent);
void fz_printpath(fz_path *, int indent);

fz_dash *fz_newdash(float phase, int len, float *array);
void fz_freedash(fz_dash *dash);

/*
 * Text buffer.
 *
 * The trm field contains the a, b, c and d coefficients.
 * The e and f coefficients come from the individual elements,
 * together they form the transform matrix for the glyph.
 *
 * Glyphs are referenced by glyph ID.
 * The Unicode text equivalent is kept in a separate array
 * with indexes into the glyph array.
 */

typedef struct fz_textel_s fz_textel;

struct fz_textel_s
{
	float x, y;
	int gid;
	int ucs;
};

struct fz_text_s
{
	fz_font *font;
	fz_matrix trm;
	int len, cap;
	fz_textel *els;
};

fz_text * fz_newtextnode(fz_font *face);
void fz_addtext(fz_text *text, int gid, int ucs, float x, float y);
void fz_endtext(fz_text *text);
void fz_resettext(fz_text *text);
void fz_freetext(fz_text *text);

/*
 * Colorspace resources.
 *
 * TODO: use lcms
 */

enum { FZ_MAXCOLORS = 32 };

struct fz_colorspace_s
{
	int refs;
	char name[16];
	int n;
	void (*convpixmap)(fz_colorspace *ss, fz_pixmap *sp, fz_colorspace *ds, fz_pixmap *dp);
	void (*convcolor)(fz_colorspace *ss, float *sv, fz_colorspace *ds, float *dv);
	void (*toxyz)(fz_colorspace *, float *src, float *xyz);
	void (*fromxyz)(fz_colorspace *, float *xyz, float *dst);
	void (*freefunc)(fz_colorspace *);
};

fz_colorspace *fz_keepcolorspace(fz_colorspace *cs);
void fz_dropcolorspace(fz_colorspace *cs);

void fz_convertcolor(fz_colorspace *srcs, float *srcv, fz_colorspace *dsts, float *dstv);
void fz_convertpixmap(fz_colorspace *srcs, fz_pixmap *srcv, fz_colorspace *dsts, fz_pixmap *dstv);

void fz_stdconvcolor(fz_colorspace *srcs, float *srcv, fz_colorspace *dsts, float *dstv);
void fz_stdconvpixmap(fz_colorspace *srcs, fz_pixmap *srcv, fz_colorspace *dsts, fz_pixmap *dstv);

/*
 * Fonts.
 *
 * Fonts come in three variants:
 *	Regular fonts are handled by FreeType.
 *	Type 3 fonts have callbacks to the interpreter.
 *	Substitute fonts are a thin wrapper over a regular font that adjusts metrics.
 */

char *ft_errorstring(int err);

struct fz_font_s
{
	int refs;
	char name[32];

	void *ftface; /* has an FT_Face if used */
	int ftsubstitute; /* ... substitute metrics */
	int fthint; /* ... force hinting for DynaLab fonts */

	fz_matrix t3matrix;
	fz_obj *t3resources;
	fz_buffer **t3procs; /* has 256 entries if used */
	float *t3widths; /* has 256 entries if used */

	fz_irect bbox;
};

struct fz_glyph_s
{
	int x, y, w, h;
	unsigned char *samples;
};

fz_error fz_newfreetypefont(fz_font **fontp, char *name, int substitute);
fz_error fz_loadfreetypefontfile(fz_font *font, char *path, int index);
fz_error fz_loadfreetypefontbuffer(fz_font *font, unsigned char *data, int len, int index);
fz_font * fz_newtype3font(char *name, fz_matrix matrix);

fz_error fz_newfontfrombuffer(fz_font **fontp, unsigned char *data, int len, int index);
fz_error fz_newfontfromfile(fz_font **fontp, char *path, int index);

fz_font * fz_keepfont(fz_font *font);
void fz_dropfont(fz_font *font);

void fz_debugfont(fz_font *font);
void fz_setfontbbox(fz_font *font, int xmin, int ymin, int xmax, int ymax);

/*
 * Images are a right mess now. Most of the code is in the pdf interpreter.
 */

/* loadtile will fill a pixmap with the pixel samples. non-premultiplied alpha. */

struct fz_image_s
{
	int refs;
	fz_error (*loadtile)(fz_image*,fz_pixmap*);
	void (*freefunc)(fz_image*);
	fz_colorspace *cs;
	int w, h, n, a;
};

fz_image *fz_keepimage(fz_image *img);
void fz_dropimage(fz_image *img);

/*
 * The shading code is in rough shape but the general architecture is sound.
 */

struct fz_shade_s
{
	int refs;

	fz_rect bbox;		/* can be fz_infiniterect */
	fz_colorspace *cs;

	/* used by build.c -- not used in drawshade.c */
	fz_matrix matrix;	/* matrix from pattern dict */
	int usebackground;	/* background color for fills but not 'sh' */
	float background[FZ_MAXCOLORS];

	int usefunction;
	float function[256][FZ_MAXCOLORS];

	int meshlen;
	int meshcap;
	float *mesh; /* [x y t] or [x y c1 ... cn] * 3 * meshlen */
};


fz_shade *fz_keepshade(fz_shade *shade);
void fz_dropshade(fz_shade *shade);

fz_rect fz_boundshade(fz_shade *shade, fz_matrix ctm);
fz_error fz_rendershade(fz_shade *shade, fz_matrix ctm, fz_colorspace *dsts, fz_pixmap *dstp);

