/* C code produced by gperf version 2.7.2 */
/* Command-line: gperf -aCDGptr -Kentity -k'1,2,3,4,5,$' -Nxhtml_ent_gperf xhtml_ent.gperf  */
struct xhtml_ent_s { const char *entity; int encoded_symbol; const char *descr;};

#define TOTAL_KEYWORDS 253
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 8
#define MIN_HASH_VALUE 141
#define MAX_HASH_VALUE 1198
/* maximum key range = 1058, duplicates = 8 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (str, len)
     register const char *str;
     register unsigned int len;
{
  static const unsigned short asso_values[] =
    {
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,  145,
        17,  208,   27, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199,  113,  135,  156,  177,   18,
      1199,  141,   78,   60, 1199,  159,   53,   11,   46,  166,
       162, 1199,   20,  184,   16,  195, 1199, 1199,   53,  137,
        14, 1199, 1199, 1199, 1199, 1199, 1199,  101,   59,  158,
       224,  198,   44,  163,  177,   73,   61,    6,   85,  107,
       146,  237,  170,  118,  160,  187,   27,  192,  255,  120,
        68,   64,   78, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199, 1199,
      1199, 1199, 1199, 1199, 1199, 1199
    };
  register int hval = len;

  switch (hval)
    {
      default:
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

static const struct xhtml_ent_s wordlist[] =
  {
    {"lt",      	60	, DESCR(" less-than sign; UNICODE(003C) TABLE(ISOnum)")},
    {"ETH",      	208	, DESCR("latin capital letter ETH; UNICODE(00D0) TABLE(ISOlat1)")},
    {"Xi",      	926	, DESCR("greek capital letter xi; UNICODE(039E) ISOgrk3")},
    {"xi",      	958	, DESCR("greek small letter xi; UNICODE(03BE) ISOgrk3")},
    {"gt",      	62	, DESCR(" greater-than sign; UNICODE(003E) TABLE(ISOnum)")},
    {"Eta",      	919	, DESCR("greek capital letter eta; UNICODE(0397)")},
    {"int",      	8747	, DESCR("integral; UNICODE(222B) TABLE(ISOtech)")},
    {"ni",      	8715	, DESCR("contains as member; UNICODE(220B) TABLE(ISOtech)")},
    {"Pi",      	928	, DESCR("greek capital letter pi; UNICODE(03A0) ISOgrk3")},
    {"pi",      	960	, DESCR("greek small letter pi; UNICODE(03C0) ISOgrk3")},
    {"zwj",      	8205	, DESCR("zero width joiner; UNICODE(200D) NEW TABLE(RFC2070)")},
    {"THORN",      	222	, DESCR("latin capital letter THORN; UNICODE(00DE) TABLE(ISOlat1)")},
    {"Mu",      	924	, DESCR("greek capital letter mu; UNICODE(039C)")},
    {"eta",      	951	, DESCR("greek small letter eta; UNICODE(03B7) ISOgrk3")},
    {"Nu",      	925	, DESCR("greek capital letter nu; UNICODE(039D)")},
    {"not",      	172	, DESCR("not sign = discretionary hyphen; UNICODE(00AC) TABLE(ISOnum)")},
    {"Zeta",      	918	, DESCR("greek capital letter zeta; UNICODE(0396)")},
    {"lrm",      	8206	, DESCR("left-to-right mark; UNICODE(200E) NEW TABLE(RFC2070)")},
    {"rlm",      	8207	, DESCR("right-to-left mark; UNICODE(200F) NEW TABLE(RFC2070)")},
    {"zwnj",      	8204	, DESCR("zero width non-joiner; UNICODE(200C) NEW TABLE(RFC2070)")},
    {"uml",      	168	, DESCR("diaeresis = spacing diaeresis; UNICODE(00A8) TABLE(ISOdia)")},
    {"sim",      	8764	, DESCR("tilde operator = varies with = similar to; UNICODE(223C) TABLE(ISOtech)")},
    {"loz",      	9674	, DESCR("lozenge; UNICODE(25CA) TABLE(ISOpub)")},
    {"Chi",      	935	, DESCR("greek capital letter chi; UNICODE(03A7)")},
    {"le",      	8804	, DESCR("less-than or equal to; UNICODE(2264) TABLE(ISOtech)")},
    {"chi",      	967	, DESCR("greek small letter chi; UNICODE(03C7) ISOgrk3")},
    {"Phi",      	934	, DESCR("greek capital letter phi; UNICODE(03A6) ISOgrk3")},
    {"part",      	8706	, DESCR("partial differential; UNICODE(2202) TABLE(ISOtech)")},
    {"beta",      	946	, DESCR("greek small letter beta; UNICODE(03B2) ISOgrk3")},
    {"Euml",      	203	, DESCR("latin capital letter E with diaeresis; UNICODE(00CB) TABLE(ISOlat1)")},
    {"mu",      	956	, DESCR("greek small letter mu; UNICODE(03BC) ISOgrk3")},
    {"shy",      	173	, DESCR("soft hyphen = discretionary hyphen; UNICODE(00AD) TABLE(ISOnum)")},
    {"phi",      	966	, DESCR("greek small letter phi; UNICODE(03C6) ISOgrk3")},
    {"Psi",      	936	, DESCR("greek capital letter psi; UNICODE(03A8) ISOgrk3")},
    {"sub",      	8834	, DESCR("subset of; UNICODE(2282) TABLE(ISOtech)")},
    {"Tau",      	932	, DESCR("greek capital letter tau; UNICODE(03A4)")},
    {"psi",      	968	, DESCR("greek small letter psi; UNICODE(03C8) ISOgrk3")},
    {"zeta",      	950	, DESCR("greek small letter zeta; UNICODE(03B6) ISOgrk3")},
    {"bull",      	8226	, DESCR("bullet = black small circle; UNICODE(2022) TABLE(ISOpub)")},
    {"tau",      	964	, DESCR("greek small letter tau; UNICODE(03C4) ISOgrk3")},
    {"fnof",      	402	, DESCR("latin small f with hook = function = florin; UNICODE(0192) TABLE(ISOtech)")},
    {"Iota",      	921	, DESCR("greek capital letter iota; UNICODE(0399)")},
    {"nu",      	957	, DESCR("greek small letter nu; UNICODE(03BD) ISOgrk3")},
    {"Iuml",      	207	, DESCR("latin capital letter I with diaeresis; UNICODE(00CF) TABLE(ISOlat1)")},
    {"yuml",      	255	, DESCR("latin small letter y with diaeresis; UNICODE(00FF) TABLE(ISOlat1)")},
    {"iota",      	953	, DESCR("greek small letter iota; UNICODE(03B9) ISOgrk3")},
    {"ne",      	8800	, DESCR("not equal to; UNICODE(2260) TABLE(ISOtech)")},
    {"iuml",      	239	, DESCR("latin small letter i with diaeresis; UNICODE(00EF) TABLE(ISOlat1)")},
    {"amp",      	38	, DESCR(" ampersand; UNICODE(0026) TABLE(ISOnum)")},
    {"yen",      	165	, DESCR("yen sign = yuan sign; UNICODE(00A5) TABLE(ISOnum)")},
    {"or",      	8744	, DESCR("logical or = vee; UNICODE(2228) TABLE(ISOtech)")},
    {"cent",      	162	, DESCR("cent sign; UNICODE(00A2) TABLE(ISOnum)")},
    {"ge",      	8805	, DESCR("greater-than or equal to; UNICODE(2265) TABLE(ISOtech)")},
    {"Beta",      	914	, DESCR("greek capital letter beta; UNICODE(0392)")},
    {"auml",      	228	, DESCR("latin small letter a with diaeresis; UNICODE(00E4) TABLE(ISOlat1)")},
    {"ang",      	8736	, DESCR("angle; UNICODE(2220) TABLE(ISOamso)")},
    {"eth",      	240	, DESCR("latin small letter eth; UNICODE(00F0) TABLE(ISOlat1)")},
    {"exist",      	8707	, DESCR("there exists; UNICODE(2203) TABLE(ISOtech)")},
    {"Auml",      	196	, DESCR("latin capital letter A with diaeresis; UNICODE(00C4) TABLE(ISOlat1)")},
    {"sup2",      	178	, DESCR("superscript two = superscript digit two = squared; UNICODE(00B2) TABLE(ISOnum)")},
    {"sum",      	8721	, DESCR("n-ary sumation; UNICODE(2211) TABLE(ISOamsb)")},
    {"nabla",      	8711	, DESCR("nabla = backward difference; UNICODE(2207) TABLE(ISOtech)")},
    {"sect",      	167	, DESCR("section sign; UNICODE(00A7) TABLE(ISOnum)")},
    {"cap",      	8745	, DESCR("intersection = cap; UNICODE(2229) TABLE(ISOtech)")},
    {"quot",      	34	, DESCR(" quotation mark = APL quote; UNICODE(0022) TABLE(ISOnum)")},
    {"Yuml",      	376	, DESCR(" latin capital letter Y with diaeresis; UNICODE(0178) TABLE(ISOlat2)")},
    {"AElig",      	198	, DESCR("latin capital letter AE = latin capital ligature AE; UNICODE(00C6) TABLE(ISOlat1)")},
    {"Theta",      	920	, DESCR("greek capital letter theta; UNICODE(0398) ISOgrk3")},
    {"isin",      	8712	, DESCR("element of; UNICODE(2208) TABLE(ISOtech)")},
    {"frac12",      	189	, DESCR("vulgar fraction one half = fraction one half; UNICODE(00BD) TABLE(ISOnum)")},
    {"infin",      	8734	, DESCR("infinity; UNICODE(221E) TABLE(ISOtech)")},
    {"real",      	8476	, DESCR("blackletter capital R = real part symbol; UNICODE(211C) TABLE(ISOamso)")},
    {"empty",      	8709	, DESCR("empty set = null set = diameter; UNICODE(2205) TABLE(ISOamso)")},
    {"theta",      	952	, DESCR("greek small letter theta; UNICODE(03B8) ISOgrk3")},
    {"para",      	182	, DESCR("pilcrow sign = paragraph sign; UNICODE(00B6) TABLE(ISOnum)")},
    {"Ouml",      	214	, DESCR("latin capital letter O with diaeresis; UNICODE(00D6) TABLE(ISOlat1)")},
    {"frac14",      	188	, DESCR("vulgar fraction one quarter = fraction one quarter; UNICODE(00BC) TABLE(ISOnum)")},
    {"thetasym",      	977	, DESCR("greek small letter theta symbol; UNICODE(03D1) NEW")},
    {"nsub",      	8836	, DESCR("not a subset of; UNICODE(2284) ISOamsn")},
    {"Lambda",      	923	, DESCR("greek capital letter lambda; UNICODE(039B) ISOgrk3")},
    {"kappa",      	954	, DESCR("greek small letter kappa; UNICODE(03BA) ISOgrk3")},
    {"Ntilde",      	209	, DESCR("latin capital letter N with tilde; UNICODE(00D1) TABLE(ISOlat1)")},
    {"lang",      	9001	, DESCR("left-pointing angle bracket = bra; UNICODE(2329) TABLE(ISOtech)")},
    {"Gamma",      	915	, DESCR("greek capital letter gamma; UNICODE(0393) ISOgrk3")},
    {"uuml",      	252	, DESCR("latin small letter u with diaeresis; UNICODE(00FC) TABLE(ISOlat1)")},
    {"frasl",      	8260	, DESCR("fraction slash; UNICODE(2044) NEW")},
    {"Uuml",      	220	, DESCR("latin capital letter U with diaeresis; UNICODE(00DC) TABLE(ISOlat1)")},
    {"larr",      	8592	, DESCR("leftwards arrow; UNICODE(2190) TABLE(ISOnum)")},
    {"euml",      	235	, DESCR("latin small letter e with diaeresis; UNICODE(00EB) TABLE(ISOlat1)")},
    {"iexcl",      	161	, DESCR("inverted exclamation mark; UNICODE(00A1) TABLE(ISOnum)")},
    {"OElig",      	338	, DESCR(" latin capital ligature OE; UNICODE(0152) TABLE(ISOlat2)")},
    {"Rho",      	929	, DESCR("greek capital letter rho; UNICODE(03A1)")},
    {"sigmaf",      	962	, DESCR("greek small letter final sigma; UNICODE(03C2) ISOgrk3")},
    {"lArr",      	8656	, DESCR("leftwards double arrow; UNICODE(21D0) TABLE(ISOtech)")},
    {"lambda",      	955	, DESCR("greek small letter lambda; UNICODE(03BB) ISOgrk3")},
    {"gamma",      	947	, DESCR("greek small letter gamma; UNICODE(03B3) ISOgrk3")},
    {"Epsilon",      	917	, DESCR("greek capital letter epsilon; UNICODE(0395)")},
    {"reg",      	174	, DESCR("registered sign = registered trade mark sign; UNICODE(00AE) TABLE(ISOnum)")},
    {"lceil",      	8968	, DESCR("left ceiling = apl upstile; UNICODE(2308) TABLE(ISOamsc)")},
    {"macr",      	175	, DESCR("macron = spacing macron = overline = APL overbar; UNICODE(00AF) TABLE(ISOdia)")},
    {"cup",      	8746	, DESCR("union = cup; UNICODE(222A) TABLE(ISOtech)")},
    {"Delta",      	916	, DESCR("greek capital letter delta; UNICODE(0394) ISOgrk3")},
    {"copy",      	169	, DESCR("copyright sign; UNICODE(00A9) TABLE(ISOnum)")},
    {"and",      	8743	, DESCR("logical and = wedge; UNICODE(2227) TABLE(ISOtech)")},
    {"Eacute",      	201	, DESCR("latin capital letter E with acute; UNICODE(00C9) TABLE(ISOlat1)")},
    {"frac34",      	190	, DESCR("vulgar fraction three quarters = fraction three quarters; UNICODE(00BE) TABLE(ISOnum)")},
    {"sdot",      	8901	, DESCR("dot operator; UNICODE(22C5) TABLE(ISOamsb)")},
    {"ouml",      	246	, DESCR("latin small letter o with diaeresis; UNICODE(00F6) TABLE(ISOlat1)")},
    {"circ",      	710	, DESCR(" modifier letter circumflex accent; UNICODE(02C6) TABLE(ISOpub)")},
    {"ordf",      	170	, DESCR("feminine ordinal indicator; UNICODE(00AA) TABLE(ISOnum)")},
    {"atilde",      	227	, DESCR("latin small letter a with tilde; UNICODE(00E3) TABLE(ISOlat1)")},
    {"forall",      	8704	, DESCR("for all; UNICODE(2200) TABLE(ISOtech)")},
    {"sup",      	8835	, DESCR("superset of; UNICODE(2283) TABLE(ISOtech)")},
    {"Atilde",      	195	, DESCR("latin capital letter A with tilde; UNICODE(00C3) TABLE(ISOlat1)")},
    {"alefsym",      	8501	, DESCR("alef symbol = first transfinite cardinal; UNICODE(2135) NEW")},
    {"Ecirc",      	202	, DESCR("latin capital letter E with circumflex; UNICODE(00CA) TABLE(ISOlat1)")},
    {"Sigma",      	931	, DESCR("greek capital letter sigma; UNICODE(03A3) ISOgrk3")},
    {"nbsp",      	160	, DESCR("no-break space = non-breaking space; UNICODE(00A0) TABLE(ISOnum)")},
    {"sigma",      	963	, DESCR("greek small letter sigma; UNICODE(03C3) ISOgrk3")},
    {"rang",      	9002	, DESCR("right-pointing angle bracket = ket; UNICODE(232A) TABLE(ISOtech)")},
    {"alpha",      	945	, DESCR("greek small letter alpha; UNICODE(03B1) ISOgrk3")},
    {"delta",      	948	, DESCR("greek small letter delta; UNICODE(03B4) ISOgrk3")},
    {"Iacute",      	205	, DESCR("latin capital letter I with acute; UNICODE(00CD) TABLE(ISOlat1)")},
    {"rarr",      	8594	, DESCR("rightwards arrow; UNICODE(2192) TABLE(ISOnum)")},
    {"yacute",      	253	, DESCR("latin small letter y with acute; UNICODE(00FD) TABLE(ISOlat1)")},
    {"deg",      	176	, DESCR("degree sign; UNICODE(00B0) TABLE(ISOnum)")},
    {"Alpha",      	913	, DESCR("greek capital letter alpha; UNICODE(0391)")},
    {"szlig",      	223	, DESCR("latin small letter sharp s = ess-zed; UNICODE(00DF) TABLE(ISOlat1)")},
    {"iacute",      	237	, DESCR("latin small letter i with acute; UNICODE(00ED) TABLE(ISOlat1)")},
    {"piv",      	982	, DESCR("greek pi symbol; UNICODE(03D6) ISOgrk3")},
    {"rArr",      	8658	, DESCR("rightwards double arrow; UNICODE(21D2) TABLE(ISOtech)")},
    {"ntilde",      	241	, DESCR("latin small letter n with tilde; UNICODE(00F1) TABLE(ISOlat1)")},
    {"harr",      	8596	, DESCR("left right arrow; UNICODE(2194) TABLE(ISOamsa)")},
    {"lowast",      	8727	, DESCR("asterisk operator; UNICODE(2217) TABLE(ISOtech)")},
    {"rceil",      	8969	, DESCR("right ceiling; UNICODE(2309) TABLE(ISOamsc)")},
    {"Icirc",      	206	, DESCR("latin capital letter I with circumflex; UNICODE(00CE) TABLE(ISOlat1)")},
    {"hArr",      	8660	, DESCR("left right double arrow; UNICODE(21D4) TABLE(ISOamsa)")},
    {"uarr",      	8593	, DESCR("upwards arrow; UNICODE(2191) TABLE(ISOnum)")},
    {"Otilde",      	213	, DESCR("latin capital letter O with tilde; UNICODE(00D5) TABLE(ISOlat1)")},
    {"notin",      	8713	, DESCR("not an element of; UNICODE(2209) TABLE(ISOtech)")},
    {"aacute",      	225	, DESCR("latin small letter a with acute; UNICODE(00E1) TABLE(ISOlat1)")},
    {"times",      	215	, DESCR("multiplication sign; UNICODE(00D7) TABLE(ISOnum)")},
    {"icirc",      	238	, DESCR("latin small letter i with circumflex; UNICODE(00EE) TABLE(ISOlat1)")},
    {"thinsp",      	8201	, DESCR("thin space; UNICODE(2009) TABLE(ISOpub)")},
    {"aelig",      	230	, DESCR("latin small letter ae = latin small ligature ae; UNICODE(00E6) TABLE(ISOlat1)")},
    {"uArr",      	8657	, DESCR("upwards double arrow; UNICODE(21D1) TABLE(ISOamsa)")},
    {"there4",      	8756	, DESCR("therefore; UNICODE(2234) TABLE(ISOtech)")},
    {"hellip",      	8230	, DESCR("horizontal ellipsis = three dot leader; UNICODE(2026) TABLE(ISOpub)")},
    {"Aacute",      	193	, DESCR("latin capital letter A with acute; UNICODE(00C1) TABLE(ISOlat1)")},
    {"permil",      	8240	, DESCR("per mille sign; UNICODE(2030) TABLE(ISOtech)")},
    {"brvbar",      	166	, DESCR("broken bar = broken vertical bar; UNICODE(00A6) TABLE(ISOnum)")},
    {"iquest",      	191	, DESCR("inverted question mark = turned question mark; UNICODE(00BF) TABLE(ISOnum)")},
    {"asymp",      	8776	, DESCR("almost equal to = asymptotic to; UNICODE(2248) ISOamsr")},
    {"Kappa",      	922	, DESCR("greek capital letter kappa; UNICODE(039A)")},
    {"darr",      	8595	, DESCR("downwards arrow; UNICODE(2193) TABLE(ISOnum)")},
    {"tilde",      	732	, DESCR(" small tilde; UNICODE(02DC) TABLE(ISOdia)")},
    {"aring",      	229	, DESCR("latin small letter a with ring above = latin small letter a ring; UNICODE(00E5) TABLE(ISOlat1)")},
    {"acirc",      	226	, DESCR("latin small letter a with circumflex; UNICODE(00E2) TABLE(ISOlat1)")},
    {"rho",      	961	, DESCR("greek small letter rho; UNICODE(03C1) ISOgrk3")},
    {"Omicron",      	927	, DESCR("greek capital letter omicron; UNICODE(039F)")},
    {"Yacute",      	221	, DESCR("latin capital letter Y with acute; UNICODE(00DD) TABLE(ISOlat1)")},
    {"dArr",      	8659	, DESCR("downwards double arrow; UNICODE(21D3) TABLE(ISOamsa)")},
    {"Aring",      	197	, DESCR("latin capital letter A with ring above = latin capital letter A ring; UNICODE(00C5) TABLE(ISOlat1)")},
    {"Acirc",      	194	, DESCR("latin capital letter A with circumflex; UNICODE(00C2) TABLE(ISOlat1)")},
    {"cedil",      	184	, DESCR("cedilla = spacing cedilla; UNICODE(00B8) TABLE(ISOdia)")},
    {"otimes",      	8855	, DESCR("circled times = vector product; UNICODE(2297) TABLE(ISOamsb)")},
    {"emsp",      	8195	, DESCR("em space; UNICODE(2003) TABLE(ISOpub)")},
    {"sube",      	8838	, DESCR("subset of or equal to; UNICODE(2286) TABLE(ISOtech)")},
    {"ordm",      	186	, DESCR("masculine ordinal indicator; UNICODE(00BA) TABLE(ISOnum)")},
    {"Omega",      	937	, DESCR("greek capital letter omega; UNICODE(03A9) ISOgrk3")},
    {"sup1",      	185	, DESCR("superscript one = superscript digit one; UNICODE(00B9) TABLE(ISOnum)")},
    {"image",      	8465	, DESCR("blackletter capital I = imaginary part; UNICODE(2111) TABLE(ISOamso)")},
    {"Oacute",      	211	, DESCR("latin capital letter O with acute; UNICODE(00D3) TABLE(ISOlat1)")},
    {"otilde",      	245	, DESCR("latin small letter o with tilde; UNICODE(00F5) TABLE(ISOlat1)")},
    {"lfloor",      	8970	, DESCR("left floor = apl downstile; UNICODE(230A) TABLE(ISOamsc)")},
    {"hearts",      	9829	, DESCR("black heart suit = valentine; UNICODE(2665) TABLE(ISOpub)")},
    {"upsilon",      	965	, DESCR("greek small letter upsilon; UNICODE(03C5) ISOgrk3")},
    {"Upsilon",      	933	, DESCR("greek capital letter upsilon; UNICODE(03A5) ISOgrk3")},
    {"epsilon",      	949	, DESCR("greek small letter epsilon; UNICODE(03B5) ISOgrk3")},
    {"cong",      	8773	, DESCR("approximately equal to; UNICODE(2245) TABLE(ISOtech)")},
    {"perp",      	8869	, DESCR("up tack = orthogonal to = perpendicular; UNICODE(22A5) TABLE(ISOtech)")},
    {"clubs",      	9827	, DESCR("black club suit = shamrock; UNICODE(2663) TABLE(ISOpub)")},
    {"uacute",      	250	, DESCR("latin small letter u with acute; UNICODE(00FA) TABLE(ISOlat1)")},
    {"ensp",      	8194	, DESCR("en space; UNICODE(2002) TABLE(ISOpub)")},
    {"Uacute",      	218	, DESCR("latin capital letter U with acute; UNICODE(00DA) TABLE(ISOlat1)")},
    {"Ocirc",      	212	, DESCR("latin capital letter O with circumflex; UNICODE(00D4) TABLE(ISOlat1)")},
    {"acute",      	180	, DESCR("acute accent = spacing acute; UNICODE(00B4) TABLE(ISOdia)")},
    {"radic",      	8730	, DESCR("square root = radical sign; UNICODE(221A) TABLE(ISOtech)")},
    {"eacute",      	233	, DESCR("latin small letter e with acute; UNICODE(00E9) TABLE(ISOlat1)")},
    {"diams",      	9830	, DESCR("black diamond suit; UNICODE(2666) TABLE(ISOpub)")},
    {"apos",      	39	, DESCR(" apostrophe mark; UNICODE(0027) TABLE(ISOnum)")},
    {"omicron",      	959	, DESCR("greek small letter omicron; UNICODE(03BF) NEW")},
    {"plusmn",      	177	, DESCR("plus-minus sign = plus-or-minus sign; UNICODE(00B1) TABLE(ISOnum)")},
    {"minus",      	8722	, DESCR("minus sign; UNICODE(2212) TABLE(ISOtech)")},
    {"middot",      	183	, DESCR("middle dot = Georgian comma = Greek middle dot; UNICODE(00B7) TABLE(ISOnum)")},
    {"thorn",      	254	, DESCR("latin small letter thorn with; UNICODE(00FE) TABLE(ISOlat1)")},
    {"Ccedil",      	199	, DESCR("latin capital letter C with cedilla; UNICODE(00C7) TABLE(ISOlat1)")},
    {"Egrave",      	200	, DESCR("latin capital letter E with grave; UNICODE(00C8) TABLE(ISOlat1)")},
    {"ccedil",      	231	, DESCR("latin small letter c with cedilla; UNICODE(00E7) TABLE(ISOlat1)")},
    {"Prime",      	8243	, DESCR("double prime = seconds = inches; UNICODE(2033) TABLE(ISOtech)")},
    {"crarr",      	8629	, DESCR("downwards arrow with corner leftwards  = carriage return; UNICODE(21B5) NEW")},
    {"ucirc",      	251	, DESCR("latin small letter u with circumflex; UNICODE(00FB) TABLE(ISOlat1)")},
    {"Ucirc",      	219	, DESCR("latin capital letter U with circumflex; UNICODE(00DB) TABLE(ISOlat1)")},
    {"Oslash",      	216	, DESCR("latin capital letter O with stroke = latin capital letter O slash; UNICODE(00D8) TABLE(ISOlat1)")},
    {"ecirc",      	234	, DESCR("latin small letter e with circumflex; UNICODE(00EA) TABLE(ISOlat1)")},
    {"prop",      	8733	, DESCR("proportional to; UNICODE(221D) TABLE(ISOtech)")},
    {"prime",      	8242	, DESCR("prime = minutes = feet; UNICODE(2032) TABLE(ISOtech)")},
    {"omega",      	969	, DESCR("greek small letter omega; UNICODE(03C9) ISOgrk3")},
    {"trade",      	8482	, DESCR("trade mark sign; UNICODE(2122) TABLE(ISOnum)")},
    {"oacute",      	243	, DESCR("latin small letter o with acute; UNICODE(00F3) TABLE(ISOlat1)")},
    {"oelig",      	339	, DESCR(" latin small ligature oe; UNICODE(0153) TABLE(ISOlat2)")},
    {"weierp",      	8472	, DESCR("script capital P = power set  = Weierstrass p; UNICODE(2118) TABLE(ISOamso)")},
    {"lsaquo",      	8249	, DESCR("single left-pointing angle quotation mark; UNICODE(2039) ISO proposed")},
    {"rfloor",      	8971	, DESCR("right floor; UNICODE(230B) TABLE(ISOamsc)")},
    {"oline",      	8254	, DESCR("overline = spacing overscore; UNICODE(203E) NEW")},
    {"Igrave",      	204	, DESCR("latin capital letter I with grave; UNICODE(00CC) TABLE(ISOlat1)")},
    {"ocirc",      	244	, DESCR("latin small letter o with circumflex; UNICODE(00F4) TABLE(ISOlat1)")},
    {"supe",      	8839	, DESCR("superset of or equal to; UNICODE(2287) TABLE(ISOtech)")},
    {"igrave",      	236	, DESCR("latin small letter i with grave; UNICODE(00EC) TABLE(ISOlat1)")},
    {"Dagger",      	8225	, DESCR("double dagger; UNICODE(2021) TABLE(ISOpub)")},
    {"sup3",      	179	, DESCR("superscript three = superscript digit three = cubed; UNICODE(00B3) TABLE(ISOnum)")},
    {"laquo",      	171	, DESCR("left-pointing double angle quotation mark = left pointing guillemet; UNICODE(00AB) TABLE(ISOnum)")},
    {"micro",      	181	, DESCR("micro sign; UNICODE(00B5) TABLE(ISOnum)")},
    {"mdash",      	8212	, DESCR("em dash; UNICODE(2014) TABLE(ISOpub)")},
    {"oslash",      	248	, DESCR("latin small letter o with stroke; = latin small letter o slash; UNICODE(00F8) TABLE(ISOlat1)")},
    {"upsih",      	978	, DESCR("greek upsilon with hook symbol; UNICODE(03D2) NEW")},
    {"agrave",      	224	, DESCR("latin small letter a with grave = latin small letter a grave; UNICODE(00E0) TABLE(ISOlat1)")},
    {"Scaron",      	352	, DESCR(" latin capital letter S with caron; UNICODE(0160) TABLE(ISOlat2)")},
    {"scaron",      	353	, DESCR(" latin small letter s with caron; UNICODE(0161) TABLE(ISOlat2)")},
    {"Agrave",      	192	, DESCR("latin capital letter A with grave = latin capital letter A grave; UNICODE(00C0) TABLE(ISOlat1)")},
    {"rsaquo",      	8250	, DESCR("single right-pointing angle quotation mark; UNICODE(203A) ISO proposed")},
    {"dagger",      	8224	, DESCR("dagger; UNICODE(2020) TABLE(ISOpub)")},
    {"ndash",      	8211	, DESCR("en dash; UNICODE(2013) TABLE(ISOpub)")},
    {"prod",      	8719	, DESCR("n-ary product = product sign; UNICODE(220F) TABLE(ISOamsb)")},
    {"curren",      	164	, DESCR("currency sign; UNICODE(00A4) TABLE(ISOnum)")},
    {"euro",      	8364	, DESCR(" euro sign; UNICODE(20AC) NEW")},
    {"sbquo",      	8218	, DESCR("single low-9 quotation mark; UNICODE(201A) NEW")},
    {"Ograve",      	210	, DESCR("latin capital letter O with grave; UNICODE(00D2) TABLE(ISOlat1)")},
    {"raquo",      	187	, DESCR("right-pointing double angle quotation mark = right pointing guillemet; UNICODE(00BB) TABLE(ISOnum)")},
    {"divide",      	247	, DESCR("division sign; UNICODE(00F7) TABLE(ISOnum)")},
    {"lsquo",      	8216	, DESCR("left single quotation mark; UNICODE(2018) TABLE(ISOnum)")},
    {"oplus",      	8853	, DESCR("circled plus = direct sum; UNICODE(2295) TABLE(ISOamsb)")},
    {"bdquo",      	8222	, DESCR("double low-9 quotation mark; UNICODE(201E) NEW")},
    {"spades",      	9824	, DESCR("black spade suit; UNICODE(2660) TABLE(ISOpub)")},
    {"ugrave",      	249	, DESCR("latin small letter u with grave; UNICODE(00F9) TABLE(ISOlat1)")},
    {"Ugrave",      	217	, DESCR("latin capital letter U with grave; UNICODE(00D9) TABLE(ISOlat1)")},
    {"egrave",      	232	, DESCR("latin small letter e with grave; UNICODE(00E8) TABLE(ISOlat1)")},
    {"equiv",      	8801	, DESCR("identical to; UNICODE(2261) TABLE(ISOtech)")},
    {"ldquo",      	8220	, DESCR("left double quotation mark; UNICODE(201C) TABLE(ISOnum)")},
    {"ograve",      	242	, DESCR("latin small letter o with grave; UNICODE(00F2) TABLE(ISOlat1)")},
    {"rsquo",      	8217	, DESCR("right single quotation mark; UNICODE(2019) TABLE(ISOnum)")},
    {"rdquo",      	8221	, DESCR("right double quotation mark; UNICODE(201D) TABLE(ISOnum)")},
    {"pound",      	163	, DESCR("pound sign; UNICODE(00A3) TABLE(ISOnum)")}
  };

static const short lookup[] =
  {
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,     0,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,     1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,     2,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,     3,
       -1,    -1,     4,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,     5,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,     6,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
        7,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,     8,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,     9,    -1,    -1,    -1,
       -1,    10,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    11,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    12,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    13,    -1,    14,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    15,
       -1,    -1,    -1,    -1,    16,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
     -717,  -236,    -2,    -1,    -1,    -1,    -1,
       -1,    19,    -1,    20,    -1,    -1,    -1,
       -1,    21,    -1,    -1,    -1,    22,    23,
       24,    25,    -1,    -1,    -1,    26,    27,
       28,    29,    -1,    30,    -1,    31,    32,
       -1,    33,    -1,    34,    -1,    -1,    -1,
       35,    -1,    36,    -1,    -1,    37,    38,
       -1,    -1,    -1,    -1,    39,    -1,    -1,
       -1,    40,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    41,    -1,
       42,    43,    -1,    -1,    -1,    44,    -1,
       -1,    -1,    -1,    -1,    45,    46,    -1,
       47,    -1,    -1,    -1,    -1,    48,    -1,
       -1,    -1,    -1,    -1,    49,    -1,    50,
       51,    52,    -1,    -1,    -1,    -1,    53,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       54,    -1,    55,    -1,    -1,    -1,    -1,
       -1,    56,    -1,    -1,    57,    58,    59,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    60,    -1,    61,    -1,    -1,    62,
       63,    -1,    -1,    64,    -1,    -1,    -1,
       -1,    65,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    66,    -1,    -1,
       -1,    -1,    67,    -1,    -1,    -1,    68,
       -1,    69,    -1,  -896,    -1,    72,    73,
       74,    -1,    75,    -1,    76,  -183,    -2,
       -1,    77,    -1,    78,    -1,    -1,    -1,
       79,    -1,    -1,    80,    -1,    -1,    -1,
       -1,    81,    -1,    -1,    82,    83,    -1,
       84,    -1,    85,    86,    -1,    87,    88,
       89,    90,    91,    -1,    -1,    -1,    -1,
       -1,    -1,    92,    93,    94,    -1,    95,
       96,    97,    -1,    98,    99,    -1,    -1,
      100,   101,    -1,    -1,   102,   103,    -1,
      104,    -1,    -1,    -1,   105,    -1,   106,
       -1,    -1,    -1,   107,   108,    -1,   109,
      110,    -1,    -1,    -1,   111,    -1,    -1,
       -1,   112,    -1,    -1,    -1,   113,    -1,
       -1,   114,   115,    -1,    -1,    -1,   116,
       -1,   117,  -992,  -135,    -2,   120,   121,
      122,    -1,    -1,   123,   124,    -1,    -1,
       -1,    -1,   125,   126,    -1,   127,   128,
      129,   130,    -1,   131,    -1,    -1,   132,
      133,   134,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,   135,    -1,   136,    -1,    -1,
      137,    -1,   138,   139,    -1,    -1,   140,
      141,   142,   143,    -1,   144,   145,    -1,
       -1,    -1,   146,   147,   148,    -1,    -1,
       -1,   149,   150,   151,    -1,    -1,   152,
       -1,    -1,   153,    -1,   154,   155,   156,
       -1,   157,   158,    -1,    -1,   159,    -1,
      160,    -1,   161,    -1,   162,    -1,   163,
       -1,    -1,   164,    -1,    -1,    -1,    -1,
       -1,    -1,   165,   166,    -1,   167,   168,
       -1,   169,    -1,   170,    -1,   171,    -1,
       -1,   172,    -1,   173,    -1,    -1,    -1,
      174,    -1,   175,    -1,    -1,    -1,   176,
       -1,    -1,   177,    -1,    -1,   178,    -1,
       -1,    -1,    -1,   179,   180,   181,   182,
      183,    -1,   184,   185, -1135,   188,   -67,
       -2,    -1,   189,    -1,   190,    -1,   191,
       -1,    -1,    -1,    -1,   192,    -1,    -1,
       -1,   193, -1170,    -1,   196,   197,   198,
      199, -1159,   -53,    -2,   202,    -1,   203,
      204, -1168,   207,   208,   -48,    -2,   -59,
       -2,    -1,   209,    -1,    -1,    -1,    -1,
      210,   211,   212,    -1,    -1,   213,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,   214,   215,    -1,
       -1,    -1,    -1,    -1, -1204,   -37,    -2,
       -1,    -1,    -1,    -1,   218,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,   219,   220,    -1,    -1,    -1,
       -1,    -1,   221,    -1,   222,   223,    -1,
      224,   225,    -1,    -1,   226,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,   227,    -1,
       -1,   228,   229,    -1,    -1,    -1,    -1,
      230,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
      231,    -1,   232,    -1,   233,   234,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,   235,
       -1,    -1,    -1,    -1,    -1,    -1,   236,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,   237,
      238,    -1,    -1,   239,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,   240,    -1,   241,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,   242,   243,    -1,   244,    -1,    -1,
      245,    -1,    -1,   246,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,   247,    -1,   248,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
      249,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,   250,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,   251,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,
       -1,   252
  };

#ifdef __GNUC__
__inline
#endif
const struct xhtml_ent_s *
xhtml_ent_gperf (str, len)
     register const char *str;
     register unsigned int len;
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = wordlist[index].entity;

              if (*str == *s && !strcmp (str + 1, s + 1))
                return &wordlist[index];
            }
          else if (index < -TOTAL_KEYWORDS)
            {
              register int offset = - 1 - TOTAL_KEYWORDS - index;
              register const struct xhtml_ent_s *wordptr = &wordlist[TOTAL_KEYWORDS + lookup[offset]];
              register const struct xhtml_ent_s *wordendptr = wordptr + -lookup[offset + 1];

              while (wordptr < wordendptr)
                {
                  register const char *s = wordptr->entity;

                  if (*str == *s && !strcmp (str + 1, s + 1))
                    return wordptr;
                  wordptr++;
                }
            }
        }
    }
  return 0;
}
