/*
 * Built-in font tables
 */

#include <fitz.h>
#include <mupdf.h>

#define _notdef 0

void pdf_loadencoding(char **estrings, char *encoding)
{
	char **bstrings = nil;
	int i;

	if (!strcmp(encoding, "MacRomanEncoding"))
		bstrings = pdf_macroman;
	if (!strcmp(encoding, "MacExpertEncoding"))
		bstrings = pdf_macexpert;
	if (!strcmp(encoding, "WinAnsiEncoding"))
		bstrings = pdf_winansi;

	if (bstrings)
		for (i = 0; i < 256; i++)
			estrings[i] = bstrings[i];
}

unsigned short pdf_docencoding[256] =
{
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x02d8, 0x02c7, 0x02c6, 0x02d9, 0x02dd, 0x02db, 0x02da, 0x02dc,
	0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
	0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
	0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
	0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
	0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
	0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
	0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
	0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
	0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
	0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
	0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
	0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x0000,
	0x2022, 0x2020, 0x2021, 0x2026, 0x2014, 0x2013, 0x0192, 0x2044,
	0x2039, 0x203a, 0x2212, 0x2030, 0x201e, 0x201c, 0x201d, 0x2018,
	0x2019, 0x201a, 0x2122, 0xfb01, 0xfb02, 0x0141, 0x0152, 0x0160,
	0x0178, 0x017d, 0x0131, 0x0142, 0x0153, 0x0161, 0x017e, 0x0000,
	0x20ac, 0x00a1, 0x00a2, 0x00a3, 0x00a4, 0x00a5, 0x00a6, 0x00a7,
	0x00a8, 0x00a9, 0x00aa, 0x00ab, 0x00ac, 0x0000, 0x00ae, 0x00af,
	0x00b0, 0x00b1, 0x00b2, 0x00b3, 0x00b4, 0x00b5, 0x00b6, 0x00b7,
	0x00b8, 0x00b9, 0x00ba, 0x00bb, 0x00bc, 0x00bd, 0x00be, 0x00bf,
	0x00c0, 0x00c1, 0x00c2, 0x00c3, 0x00c4, 0x00c5, 0x00c6, 0x00c7,
	0x00c8, 0x00c9, 0x00ca, 0x00cb, 0x00cc, 0x00cd, 0x00ce, 0x00cf,
	0x00d0, 0x00d1, 0x00d2, 0x00d3, 0x00d4, 0x00d5, 0x00d6, 0x00d7,
	0x00d8, 0x00d9, 0x00da, 0x00db, 0x00dc, 0x00dd, 0x00de, 0x00df,
	0x00e0, 0x00e1, 0x00e2, 0x00e3, 0x00e4, 0x00e5, 0x00e6, 0x00e7,
	0x00e8, 0x00e9, 0x00ea, 0x00eb, 0x00ec, 0x00ed, 0x00ee, 0x00ef,
	0x00f0, 0x00f1, 0x00f2, 0x00f3, 0x00f4, 0x00f5, 0x00f6, 0x00f7,
	0x00f8, 0x00f9, 0x00fa, 0x00fb, 0x00fc, 0x00fd, 0x00fe, 0x00ff
};

char *pdf_macroman[256] = { _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	"space", "exclam", "quotedbl", "numbersign", "dollar", "percent",
	"ampersand", "quotesingle", "parenleft", "parenright", "asterisk",
	"plus", "comma", "hyphen", "period", "slash", "zero", "one", "two",
	"three", "four", "five", "six", "seven", "eight", "nine", "colon",
	"semicolon", "less", "equal", "greater", "question", "at", "A",
	"B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
	"O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
	"bracketleft", "backslash", "bracketright", "asciicircum", "underscore",
	"grave", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
	"l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x",
	"y", "z", "braceleft", "bar", "braceright", "asciitilde", _notdef,
	"Adieresis", "Aring", "Ccedilla", "Eacute", "Ntilde", "Odieresis",
	"Udieresis", "aacute", "agrave", "acircumflex", "adieresis", "atilde",
	"aring", "ccedilla", "eacute", "egrave", "ecircumflex", "edieresis",
	"iacute", "igrave", "icircumflex", "idieresis", "ntilde", "oacute",
	"ograve", "ocircumflex", "odieresis", "otilde", "uacute", "ugrave",
	"ucircumflex", "udieresis", "dagger", "degree", "cent", "sterling",
	"section", "bullet", "paragraph", "germandbls", "registered",
	"copyright", "trademark", "acute", "dieresis", _notdef, "AE",
	"Oslash", _notdef, "plusminus", _notdef, _notdef, "yen", "mu",
	_notdef, _notdef, _notdef, _notdef, _notdef, "ordfeminine",
	"ordmasculine", _notdef, "ae", "oslash", "questiondown", "exclamdown",
	"logicalnot", _notdef, "florin", _notdef, _notdef, "guillemotleft",
	"guillemotright", "ellipsis", "space", "Agrave", "Atilde", "Otilde",
	"OE", "oe", "endash", "emdash", "quotedblleft", "quotedblright",
	"quoteleft", "quoteright", "divide", _notdef, "ydieresis",
	"Ydieresis", "fraction", "currency", "guilsinglleft", "guilsinglright",
	"fi", "fl", "daggerdbl", "periodcentered", "quotesinglbase",
	"quotedblbase", "perthousand", "Acircumflex", "Ecircumflex", "Aacute",
	"Edieresis", "Egrave", "Iacute", "Icircumflex", "Idieresis", "Igrave",
	"Oacute", "Ocircumflex", _notdef, "Ograve", "Uacute", "Ucircumflex",
	"Ugrave", "dotlessi", "circumflex", "tilde", "macron", "breve",
	"dotaccent", "ring", "cedilla", "hungarumlaut", "ogonek", "caron" };

char *pdf_macexpert[256] = { _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	"space", "exclamsmall", "Hungarumlautsmall", "centoldstyle",
	"dollaroldstyle", "dollarsuperior", "ampersandsmall", "Acutesmall",
	"parenleftsuperior", "parenrightsuperior", "twodotenleader",
	"onedotenleader", "comma", "hyphen", "period", "fraction",
	"zerooldstyle", "oneoldstyle", "twooldstyle", "threeoldstyle",
	"fouroldstyle", "fiveoldstyle", "sixoldstyle", "sevenoldstyle",
	"eightoldstyle", "nineoldstyle", "colon", "semicolon", _notdef,
	"threequartersemdash", _notdef, "questionsmall", _notdef,
	_notdef, _notdef, _notdef, "Ethsmall", _notdef, _notdef,
	"onequarter", "onehalf", "threequarters", "oneeighth", "threeeighths",
	"fiveeighths", "seveneighths", "onethird", "twothirds", _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, "ff", "fi",
	"fl", "ffi", "ffl", "parenleftinferior", _notdef, "parenrightinferior",
	"Circumflexsmall", "hypheninferior", "Gravesmall", "Asmall", "Bsmall",
	"Csmall", "Dsmall", "Esmall", "Fsmall", "Gsmall", "Hsmall", "Ismall",
	"Jsmall", "Ksmall", "Lsmall", "Msmall", "Nsmall", "Osmall", "Psmall",
	"Qsmall", "Rsmall", "Ssmall", "Tsmall", "Usmall", "Vsmall", "Wsmall",
	"Xsmall", "Ysmall", "Zsmall", "colonmonetary", "onefitted", "rupiah",
	"Tildesmall", _notdef, _notdef, "asuperior", "centsuperior",
	_notdef, _notdef, _notdef, _notdef, "Aacutesmall",
	"Agravesmall", "Acircumflexsmall", "Adieresissmall", "Atildesmall",
	"Aringsmall", "Ccedillasmall", "Eacutesmall", "Egravesmall",
	"Ecircumflexsmall", "Edieresissmall", "Iacutesmall", "Igravesmall",
	"Icircumflexsmall", "Idieresissmall", "Ntildesmall", "Oacutesmall",
	"Ogravesmall", "Ocircumflexsmall", "Odieresissmall", "Otildesmall",
	"Uacutesmall", "Ugravesmall", "Ucircumflexsmall", "Udieresissmall",
	_notdef, "eightsuperior", "fourinferior", "threeinferior",
	"sixinferior", "eightinferior", "seveninferior", "Scaronsmall",
	_notdef, "centinferior", "twoinferior", _notdef, "Dieresissmall",
	_notdef, "Caronsmall", "osuperior", "fiveinferior", _notdef,
	"commainferior", "periodinferior", "Yacutesmall", _notdef,
	"dollarinferior", _notdef, _notdef, "Thornsmall", _notdef,
	"nineinferior", "zeroinferior", "Zcaronsmall", "AEsmall", "Oslashsmall",
	"questiondownsmall", "oneinferior", "Lslashsmall", _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, "Cedillasmall",
	_notdef, _notdef, _notdef, _notdef, _notdef, "OEsmall",
	"figuredash", "hyphensuperior", _notdef, _notdef, _notdef,
	_notdef, "exclamdownsmall", _notdef, "Ydieresissmall", _notdef,
	"onesuperior", "twosuperior", "threesuperior", "foursuperior",
	"fivesuperior", "sixsuperior", "sevensuperior", "ninesuperior",
	"zerosuperior", _notdef, "esuperior", "rsuperior", "tsuperior",
	_notdef, _notdef, "isuperior", "ssuperior", "dsuperior",
	_notdef, _notdef, _notdef, _notdef, _notdef, "lsuperior",
	"Ogoneksmall", "Brevesmall", "Macronsmall", "bsuperior", "nsuperior",
	"msuperior", "commasuperior", "periodsuperior", "Dotaccentsmall",
	"Ringsmall", _notdef, _notdef, _notdef, _notdef };

char *pdf_winansi[256] = { _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, "space",
	"exclam", "quotedbl", "numbersign", "dollar", "percent", "ampersand",
	"quotesingle", "parenleft", "parenright", "asterisk", "plus",
	"comma", "hyphen", "period", "slash", "zero", "one", "two", "three",
	"four", "five", "six", "seven", "eight", "nine", "colon", "semicolon",
	"less", "equal", "greater", "question", "at", "A", "B", "C", "D",
	"E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q",
	"R", "S", "T", "U", "V", "W", "X", "Y", "Z", "bracketleft",
	"backslash", "bracketright", "asciicircum", "underscore", "grave",
	"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
	"n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
	"braceleft", "bar", "braceright", "asciitilde", "bullet", "Euro",
	"bullet", "quotesinglbase", "florin", "quotedblbase", "ellipsis",
	"dagger", "daggerdbl", "circumflex", "perthousand", "Scaron",
	"guilsinglleft", "OE", "bullet", "Zcaron", "bullet", "bullet",
	"quoteleft", "quoteright", "quotedblleft", "quotedblright", "bullet",
	"endash", "emdash", "tilde", "trademark", "scaron", "guilsinglright",
	"oe", "bullet", "zcaron", "Ydieresis", "space", "exclamdown", "cent",
	"sterling", "currency", "yen", "brokenbar", "section", "dieresis",
	"copyright", "ordfeminine", "guillemotleft", "logicalnot", "hyphen",
	"registered", "macron", "degree", "plusminus", "twosuperior",
	"threesuperior", "acute", "mu", "paragraph", "periodcentered",
	"cedilla", "onesuperior", "ordmasculine", "guillemotright",
	"onequarter", "onehalf", "threequarters", "questiondown", "Agrave",
	"Aacute", "Acircumflex", "Atilde", "Adieresis", "Aring", "AE",
	"Ccedilla", "Egrave", "Eacute", "Ecircumflex", "Edieresis", "Igrave",
	"Iacute", "Icircumflex", "Idieresis", "Eth", "Ntilde", "Ograve",
	"Oacute", "Ocircumflex", "Otilde", "Odieresis", "multiply", "Oslash",
	"Ugrave", "Uacute", "Ucircumflex", "Udieresis", "Yacute", "Thorn",
	"germandbls", "agrave", "aacute", "acircumflex", "atilde", "adieresis",
	"aring", "ae", "ccedilla", "egrave", "eacute", "ecircumflex",
	"edieresis", "igrave", "iacute", "icircumflex", "idieresis", "eth",
	"ntilde", "ograve", "oacute", "ocircumflex", "otilde", "odieresis",
	"divide", "oslash", "ugrave", "uacute", "ucircumflex", "udieresis",
	"yacute", "thorn", "ydieresis" };

#if 0

char *pdf_standard[256] = { _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	"space", "exclam", "quotedbl", "numbersign", "dollar", "percent",
	"ampersand", "quoteright", "parenleft", "parenright", "asterisk",
	"plus", "comma", "hyphen", "period", "slash", "zero", "one", "two",
	"three", "four", "five", "six", "seven", "eight", "nine", "colon",
	"semicolon", "less", "equal", "greater", "question", "at", "A",
	"B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
	"O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
	"bracketleft", "backslash", "bracketright", "asciicircum", "underscore",
	"quoteleft", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
	"l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x",
	"y", "z", "braceleft", "bar", "braceright", "asciitilde", _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, "exclamdown", "cent", "sterling",
	"fraction", "yen", "florin", "section", "currency", "quotesingle",
	"quotedblleft", "guillemotleft", "guilsinglleft", "guilsinglright",
	"fi", "fl", _notdef, "endash", "dagger", "daggerdbl", "periodcentered",
	_notdef, "paragraph", "bullet", "quotesinglbase", "quotedblbase",
	"quotedblright", "guillemotright", "ellipsis", "perthousand",
	_notdef, "questiondown", _notdef, "grave", "acute", "circumflex",
	"tilde", "macron", "breve", "dotaccent", "dieresis", _notdef,
	"ring", "cedilla", _notdef, "hungarumlaut", "ogonek", "caron",
	"emdash", _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, "AE",
	_notdef, "ordfeminine", _notdef, _notdef, _notdef, _notdef,
	"Lslash", "Oslash", "OE", "ordmasculine", _notdef, _notdef,
	_notdef, _notdef, _notdef, "ae", _notdef, _notdef,
	_notdef, "dotlessi", _notdef, _notdef, "lslash", "oslash",
	"oe", "germandbls", _notdef, _notdef, _notdef, _notdef };

char *pdf_expert[256] = { _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, "space",
	"exclamsmall", "Hungarumlautsmall", _notdef, "dollaroldstyle",
	"dollarsuperior", "ampersandsmall", "Acutesmall", "parenleftsuperior",
	"parenrightsuperior", "twodotenleader", "onedotenleader", "comma",
	"hyphen", "period", "fraction", "zerooldstyle", "oneoldstyle",
	"twooldstyle", "threeoldstyle", "fouroldstyle", "fiveoldstyle",
	"sixoldstyle", "sevenoldstyle", "eightoldstyle", "nineoldstyle",
	"colon", "semicolon", "commasuperior", "threequartersemdash",
	"periodsuperior", "questionsmall", _notdef, "asuperior", "bsuperior",
	"centsuperior", "dsuperior", "esuperior", _notdef, _notdef,
	_notdef, "isuperior", _notdef, _notdef, "lsuperior", "msuperior",
	"nsuperior", "osuperior", _notdef, _notdef, "rsuperior",
	"ssuperior", "tsuperior", _notdef, "ff", "fi", "fl", "ffi", "ffl",
	"parenleftinferior", _notdef, "parenrightinferior", "Circumflexsmall",
	"hyphensuperior", "Gravesmall", "Asmall", "Bsmall", "Csmall",
	"Dsmall", "Esmall", "Fsmall", "Gsmall", "Hsmall", "Ismall", "Jsmall",
	"Ksmall", "Lsmall", "Msmall", "Nsmall", "Osmall", "Psmall", "Qsmall",
	"Rsmall", "Ssmall", "Tsmall", "Usmall", "Vsmall", "Wsmall", "Xsmall",
	"Ysmall", "Zsmall", "colonmonetary", "onefitted", "rupiah",
	"Tildesmall", _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, "exclamdownsmall",
	"centoldstyle", "Lslashsmall", _notdef, _notdef, "Scaronsmall",
	"Zcaronsmall", "Dieresissmall", "Brevesmall", "Caronsmall", _notdef,
	"Dotaccentsmall", _notdef, _notdef, "Macronsmall", _notdef,
	_notdef, "figuredash", "hypheninferior", _notdef, _notdef,
	"Ogoneksmall", "Ringsmall", "Cedillasmall", _notdef, _notdef,
	_notdef, "onequarter", "onehalf", "threequarters", "questiondownsmall",
	"oneeighth", "threeeighths", "fiveeighths", "seveneighths", "onethird",
	"twothirds", _notdef, _notdef, "zerosuperior", "onesuperior",
	"twosuperior", "threesuperior", "foursuperior", "fivesuperior",
	"sixsuperior", "sevensuperior", "eightsuperior", "ninesuperior",
	"zeroinferior", "oneinferior", "twoinferior", "threeinferior",
	"fourinferior", "fiveinferior", "sixinferior", "seveninferior",
	"eightinferior", "nineinferior", "centinferior", "dollarinferior",
	"periodinferior", "commainferior", "Agravesmall", "Aacutesmall",
	"Acircumflexsmall", "Atildesmall", "Adieresissmall", "Aringsmall",
	"AEsmall", "Ccedillasmall", "Egravesmall", "Eacutesmall",
	"Ecircumflexsmall", "Edieresissmall", "Igravesmall", "Iacutesmall",
	"Icircumflexsmall", "Idieresissmall", "Ethsmall", "Ntildesmall",
	"Ogravesmall", "Oacutesmall", "Ocircumflexsmall", "Otildesmall",
	"Odieresissmall", "OEsmall", "Oslashsmall", "Ugravesmall",
	"Uacutesmall", "Ucircumflexsmall", "Udieresissmall", "Yacutesmall",
	"Thornsmall", "Ydieresissmall" };

char *pdf_symbol[256] = { _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, "space",
	"exclam", "universal", "numbersign", "existential", "percent",
	"ampersand", "suchthat", "parenleft", "parenright", "asteriskmath",
	"plus", "comma", "minus", "period", "slash", "zero", "one", "two",
	"three", "four", "five", "six", "seven", "eight", "nine", "colon",
	"semicolon", "less", "equal", "greater", "question", "congruent",
	"Alpha", "Beta", "Chi", "Delta", "Epsilon", "Phi", "Gamma", "Eta",
	"Iota", "theta1", "Kappa", "Lambda", "Mu", "Nu", "Omicron", "Pi",
	"Theta", "Rho", "Sigma", "Tau", "Upsilon", "sigma1", "Omega", "Xi",
	"Psi", "Zeta", "bracketleft", "therefore", "bracketright",
	"perpendicular", "underscore", "radicalex", "alpha", "beta", "chi",
	"delta", "epsilon", "phi", "gamma", "eta", "iota", "phi1", "kappa",
	"lambda", "mu", "nu", "omicron", "pi", "theta", "rho", "sigma",
	"tau", "upsilon", "omega1", "omega", "xi", "psi", "zeta", "braceleft",
	"bar", "braceright", "similar", _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, "Upsilon1", "minute", "lessequal", "fraction", "infinity",
	"florin", "club", "diamond", "heart", "spade", "arrowboth",
	"arrowleft", "arrowup", "arrowright", "arrowdown", "degree",
	"plusminus", "second", "greaterequal", "multiply", "proportional",
	"partialdiff", "bullet", "divide", "notequal", "equivalence",
	"approxequal", "ellipsis", "arrowvertex", "arrowhorizex",
	"carriagereturn", "aleph", "Ifraktur", "Rfraktur", "weierstrass",
	"circlemultiply", "circleplus", "emptyset", "intersection", "union",
	"propersuperset", "reflexsuperset", "notsubset", "propersubset",
	"reflexsubset", "element", "notelement", "angle", "gradient",
	"registerserif", "copyrightserif", "trademarkserif", "product",
	"radical", "dotmath", "logicalnot", "logicaland", "logicalor",
	"arrowdblboth", "arrowdblleft", "arrowdblup", "arrowdblright",
	"arrowdbldown", "lozenge", "angleleft", "registersans", "copyrightsans",
	"trademarksans", "summation", "parenlefttp", "parenleftex",
	"parenleftbt", "bracketlefttp", "bracketleftex", "bracketleftbt",
	"bracelefttp", "braceleftmid", "braceleftbt", "braceex", _notdef,
	"angleright", "integral", "integraltp", "integralex", "integralbt",
	"parenrighttp", "parenrightex", "parenrightbt", "bracketrighttp",
	"bracketrightex", "bracketrightbt", "bracerighttp", "bracerightmid",
	"bracerightbt", _notdef };

char *pdf_zapfdingbats[256] = { _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	"space", "a1", "a2", "a202", "a3", "a4", "a5", "a119", "a118",
	"a117", "a11", "a12", "a13", "a14", "a15", "a16", "a105", "a17",
	"a18", "a19", "a20", "a21", "a22", "a23", "a24", "a25", "a26",
	"a27", "a28", "a6", "a7", "a8", "a9", "a10", "a29", "a30", "a31",
	"a32", "a33", "a34", "a35", "a36", "a37", "a38", "a39", "a40",
	"a41", "a42", "a43", "a44", "a45", "a46", "a47", "a48", "a49",
	"a50", "a51", "a52", "a53", "a54", "a55", "a56", "a57", "a58",
	"a59", "a60", "a61", "a62", "a63", "a64", "a65", "a66", "a67",
	"a68", "a69", "a70", "a71", "a72", "a73", "a74", "a203", "a75",
	"a204", "a76", "a77", "a78", "a79", "a81", "a82", "a83", "a84",
	"a97", "a98", "a99", "a100", _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, _notdef, _notdef, _notdef, _notdef, _notdef,
	_notdef, "a101", "a102", "a103", "a104", "a106", "a107", "a108",
	"a112", "a111", "a110", "a109", "a120", "a121", "a122", "a123",
	"a124", "a125", "a126", "a127", "a128", "a129", "a130", "a131",
	"a132", "a133", "a134", "a135", "a136", "a137", "a138", "a139",
	"a140", "a141", "a142", "a143", "a144", "a145", "a146", "a147",
	"a148", "a149", "a150", "a151", "a152", "a153", "a154", "a155",
	"a156", "a157", "a158", "a159", "a160", "a161", "a163", "a164",
	"a196", "a165", "a192", "a166", "a167", "a168", "a169", "a170",
	"a171", "a172", "a173", "a162", "a174", "a175", "a176", "a177",
	"a178", "a179", "a193", "a180", "a199", "a181", "a200", "a182",
	_notdef, "a201", "a183", "a184", "a197", "a185", "a194", "a198",
	"a186", "a195", "a187", "a188", "a189", "a190", "a191", _notdef };

#endif

