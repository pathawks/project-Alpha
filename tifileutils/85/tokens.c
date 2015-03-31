#include <stdlib.h>
#include "../tokens.h"
#include "tokens.h"

const char* const tifileutils_tokens_85_3D[0x03D + 2] = {
    /* Highest token in list */ (const char *const) 0x03D,
    /* 00 */ "zxScl",
    /* 01 */ "zyScl",
    /* 02 */ "xScl",
    /* 03 */ "yScl",
    /* 04 */ "xMin",
    /* 05 */ "xMax",
    /* 06 */ "yMin",
    /* 07 */ "yMax",
    /* 08 */ "tMin",
    /* 09 */ "tMax",
    /* 0A */ "tStep",
    /* 0B */ TITOKEN_THETA "Step",
    /* 0C */ "ztStep",
    /* 0D */ "z" TITOKEN_THETA "Step",
    /* 0E */ "tPlot",
    /* 0F */ TITOKEN_THETA "Min",
    /* 10 */ TITOKEN_THETA "Max",
    /* 11 */ "zxMin",
    /* 12 */ "zxMax",
    /* 13 */ "zyMin",
    /* 14 */ "zyMax",
    /* 15 */ "ztPlot",
    /* 16 */ "z" TITOKEN_THETA "Min",
    /* 17 */ "z" TITOKEN_THETA "Max",
    /* 18 */ "ztMin",
    /* 19 */ "ztMax",
    /* 1A */ "lower",
    /* 1B */ "upper",
    /* 1C */ TITOKEN_DELTA "x",
    /* 1D */ TITOKEN_DELTA "y",
    /* 1E */ "xFact",
    /* 1F */ "yFact",
    /* 20 */ "difTol",
    /* 21 */ "tol",
    /* 22 */ TITOKEN_delta,
    /* 23 */ "Na",
    /* 24 */ "k",
    /* 25 */ "Cc",
    /* 26 */ "ec",
    /* 27 */ "Rc",
    /* 28 */ "Gc",
    /* 29 */ "g",
    /* 2A */ "Me",
    /* 2B */ "Mp",
    /* 2C */ "Mn",
    /* 2D */ TITOKEN_MICRO "0",
    /* 2E */ TITOKEN_epsilon "0",
    /* 2F */ "h",
    /* 30 */ "c",
    /* 31 */ "u",
    /* 32 */ "e",
    /* 33 */ "xStat",
    /* 34 */ "yStat",
    /* 35 */ "fStat",
    /* 36 */ "TblStart",
    /* 37 */ TITOKEN_DELTA "Tbl",
    /* 38 */ "fldRes",
    /* 39 */ "EStep",
    /* 3A */ "dTime",
    /* 3B */ "xRes",
    /* 3C */ "zxRes",
    /* 3D */ "FldPic",
};

const char* const tifileutils_tokens_85_8E[0x031 + 2] = {
    /* Highest token in list */ (const char *const) 0x031,
    /* 00 */ "PxOn",
    /* 01 */ "PxOff",
    /* 02 */ "PxChg",
    /* 03 */ "Get",
    /* 04 */ "Send",
    /* 05 */ "SinR",
    /* 06 */ "LgstR",
    /* 07 */ "TwoVar",
    /* 08 */ "GrStl",
    /* 09 */ "DrEqu",
    /* 0A */ "LCust",
    /* 0B */ "Form",
    /* 0C */ "Select",
    /* 0D */ "PlOn",
    /* 0E */ "PlOff",
    /* 0F */ "ClrEnt",
    /* 10 */ "StReg",
    /* 11 */ "IAsk",
    /* 12 */ "IAuto",
    /* 13 */ "Text",
    /* 14 */ "Horiz",
    /* 15 */ "DispT",
    /* 16 */ "ClTbl",
    /* 17 */ "DelVar",
    /* 18 */ "Box",
    /* 19 */ "MBox",
    /* 1A */ "ClrLsts",
    /* 1B */ "FldOff",
    /* 1C */ "DirFld",
    /* 1D */ "SlpFld",
    /* 1E */ "SetLEdit",
    /* 1F */ "Plot1",
    /* 20 */ "Plot2",
    /* 21 */ "Plot3",
    /* 22 */ "RK",
    /* 23 */ "Euler",
    /* 24 */ "ZData",
    /* 25 */ "Asm",
    /* 26 */ "AsmComp",
    /* 27 */ NULL,
    /* 28 */ NULL,
    /* 29 */ NULL,
    /* 2A */ "PxTest",
    /* 2B */ "randInt",
    /* 2C */ "randBin",
    /* 2D */ "randNorm",
    /* 2E */ "median",
    /* 2F */ "cSum",
    /* 30 */ "cSum",
    /* 31 */ "Deltalst",
};

const char* const tifileutils_tokens_85[0x0100] = {
    /* 00 */ NULL,
    /* 01 */ TITOKEN_TRIANGLE "Rec",
    /* 02 */ TITOKEN_TRIANGLE "Pol",
    /* 03 */ TITOKEN_TRIANGLE "Cyl",
    /* 04 */ TITOKEN_TRIANGLE "Sph",
    /* 05 */ TITOKEN_TRIANGLE "DMS",
    /* 06 */ TITOKEN_TRIANGLE "Bin",
    /* 07 */ TITOKEN_TRIANGLE "Hex",
    /* 08 */ TITOKEN_TRIANGLE "Oct",
    /* 09 */ TITOKEN_TRIANGLE "Dec",
    /* 0A */ TITOKEN_TRIANGLE "Frac",
    /* 0B */ TITOKEN_ARROW,
    /* 0C */ "[",
    /* 0D */ "]",
    /* 0E */ "{",
    /* 0F */ "}",
    /* 10 */ "(",
    /* 11 */ ")",
    /* 12 */ "round(",
    /* 13 */ "max",
    /* 14 */ "min",
    /* 15 */ "mod",
    /* 16 */ "cross",
    /* 17 */ "dot",
    /* 18 */ "aug",
    /* 19 */ "rSwap",
    /* 1A */ "rAdd",
    /* 1B */ "multR",
    /* 1C */ "mRAdd",
    /* 1D */ "sub",
    /* 1E */ "lcm",
    /* 1F */ "gcd",
    /* 20 */ "simult",
    /* 21 */ "inter",
    /* 22 */ "pEval",
    /* 23 */ "randM",
    /* 24 */ "seq",
    /* 25 */ "evalF",
    /* 26 */ "fnInt",
    /* 27 */ "arc",
    /* 28 */ "fMin",
    /* 29 */ "fMax",
    /* 2A */ "der1",
    /* 2B */ "der2",
    /* 2C */ "nDer",
    /* 2D */ NULL,
    /* 2E */ TITOKEN_ANGLE,
    /* 2F */ ",",
    /* 30 */ "or",
    /* 31 */ "xor",
    /* 32 */ NULL,
    /* 33 */ NULL,
    /* 34 */ NULL,
    /* 35 */ NULL,
    /* 36 */ NULL,
    /* 37 */ NULL,
    /* 38 */ NULL,
    /* 39 */ NULL,
    /* 3A */ NULL,
    /* 3B */ NULL,
    /* 3C */ NULL,
    /* 3D */ (const char *const) tifileutils_tokens_85_3D,
    /* 3E */ NULL,
    /* 3F */ "=",
    /* 40 */ "and",
    /* 41 */ "rand",
    /* 42 */ TITOKEN_PI,
    /* 43 */ "getKy",
    /* 44 */ NULL,
    /* 45 */ "%",
    /* 46 */ "!",
    /* 47 */ TITOKEN_SUB_r,
    /* 48 */ TITOKEN_DEGREE,
    /* 49 */ TITOKEN_SUP_N_ONE,
    /* 4A */ TITOKEN_SUP_TWO,
    /* 4B */ TITOKEN_SUP_T,
    /* 4C */ "Menu",
    /* 4D */ "P2Reg",
    /* 4E */ "P3Reg",
    /* 4F */ "P4Reg",
    /* 50 */ "==",
    /* 51 */ "<",
    /* 52 */ ">",
    /* 53 */ TITOKEN_LTE,
    /* 54 */ TITOKEN_GTE,
    /* 55 */ TITOKEN_NOT_EQUAL,
    /* 56 */ "Radian",
    /* 57 */ "Degree",
    /* 58 */ "Normal",
    /* 59 */ "Sci",
    /* 5A */ "Eng",
    /* 5B */ "Float",
    /* 5C */ "Fix",
    /* 5D */ "RectV",
    /* 5E */ "CylV",
    /* 5F */ "SphereV",
    /* 60 */ "+",
    /* 61 */ "-",
    /* 62 */ "Func",
    /* 63 */ "Param",
    /* 64 */ "Pol",
    /* 65 */ "DifEq",
    /* 66 */ "Bin",
    /* 67 */ "Oct",
    /* 68 */ "Hex",
    /* 69 */ "Dec",
    /* 6A */ "RectC",
    /* 6B */ "PolarC",
    /* 6C */ "dxDer1",
    /* 6D */ "dxNDer",
    /* 6E */ ":",
    /* 6F */ "",
    /* 70 */ "*",
    /* 71 */ "/",
    /* 72 */ "SeqG",
    /* 73 */ "SimulG",
    /* 74 */ "PolarGC",
    /* 75 */ "RectGC",
    /* 76 */ "CoordOn",
    /* 77 */ "CoordOff",
    /* 78 */ "DrawLine",
    /* 79 */ "DrawDot",
    /* 7A */ "AxesOn",
    /* 7B */ "AxesOff",
    /* 7C */ "GridOn",
    /* 7D */ "GridOff",
    /* 7E */ "LabelOn",
    /* 7F */ "LabelOff",
    /* 80 */ "nPr",
    /* 81 */ "nCr",
    /* 82 */ "Trace",
    /* 83 */ "ClDrw",
    /* 84 */ "ZStd",
    /* 85 */ "ZTrig",
    /* 86 */ "ZFit",
    /* 87 */ "ZIn",
    /* 88 */ "ZOut",
    /* 89 */ "ZSqr",
    /* 8A */ "ZInt",
    /* 8B */ "ZPrev",
    /* 8C */ "ZDecm",
    /* 8D */ "ZRcl",
    /* 8E */ (const char *const) tifileutils_tokens_85_8E,
    /* 8F */ "DrawF",
    /* 90 */ "FnOn",
    /* 91 */ "FnOff",
    /* 92 */ "StPic",
    /* 93 */ "RcPic",
    /* 94 */ "StGDB",
    /* 95 */ "RcGDB",
    /* 96 */ "Line",
    /* 97 */ "Vert",
    /* 98 */ "PtOn",
    /* 99 */ "PtOff",
    /* 9A */ "PtChg",
    /* 9B */ "Shade",
    /* 9C */ "Circl",
    /* 9D */ "Axes",
    /* 9E */ "TanLn",
    /* 9F */ "DrInv",
    /* A0 */ TITOKEN_SQRT,
    /* A1 */ "-",
    /* A2 */ "abs",
    /* A3 */ "iPart",
    /* A4 */ "fPart",
    /* A5 */ "int",
    /* A6 */ "ln",
    /* A7 */ TITOKEN_e "^",
    /* A8 */ "log",
    /* A9 */ TITOKEN_SUB_TEN "^",
    /* AA */ "sin",
    /* AB */ "sin" TITOKEN_SUP_N_ONE,
    /* AC */ "cos",
    /* AD */ "cos" TITOKEN_SUP_N_ONE,
    /* AE */ "tan",
    /* AF */ "tan" TITOKEN_SUP_N_ONE,
    /* B0 */ "sinh",
    /* B1 */ "sinh" TITOKEN_SUP_N_ONE,
    /* B2 */ "cosh",
    /* B3 */ "cosh" TITOKEN_SUP_N_ONE,
    /* B4 */ "tanh",
    /* B5 */ "tanh" TITOKEN_SUP_N_ONE,
    /* B6 */ "sign",
    /* B7 */ "det",
    /* B8 */ "ident",
    /* B9 */ "unitV",
    /* BA */ "norm",
    /* BB */ "rnorm",
    /* BC */ "cnorm",
    /* BD */ "ref",
    /* BE */ "rref",
    /* BF */ "dim",
    /* C0 */ "dimL",
    /* C1 */ "sum",
    /* C2 */ "prod",
    /* C3 */ "sortA",
    /* C4 */ "sortD",
    /* C5 */ "li" TITOKEN_TRIANGLE "vc",
    /* C6 */ "vc" TITOKEN_TRIANGLE "li",
    /* C7 */ "lngth",
    /* C8 */ "conj",
    /* C9 */ "real",
    /* CA */ "imag",
    /* CB */ "angle",
    /* CC */ "not",
    /* CD */ "rotR",
    /* CE */ "rotL",
    /* CF */ "shftR",
    /* D0 */ "shftL",
    /* D1 */ "eigVl",
    /* D2 */ "eigVc",
    /* D3 */ "cond",
    /* D4 */ "poly",
    /* D5 */ "fcstx",
    /* D6 */ "fcsty",
    /* D7 */ "eval",
    /* D8 */ "If",
    /* D9 */ "Then",
    /* DA */ "Else",
    /* DB */ "While",
    /* DC */ "Repeat",
    /* DD */ "For",
    /* DE */ "End",
    /* DF */ "Return",
    /* E0 */ NULL,
    /* E1 */ NULL,
    /* E2 */ "Pause",
    /* E3 */ "Stop",
    /* E4 */ "IS>",
    /* E5 */ "DS<",
    /* E6 */ "Input",
    /* E7 */ "Prompt",
    /* E8 */ "InpSt",
    /* E9 */ "Disp",
    /* EA */ "DispG",
    /* EB */ "Outpt",
    /* EC */ "ClLCD",
    /* ED */ "Eq" TITOKEN_TRIANGLE "St",
    /* EE */ "St" TITOKEN_TRIANGLE "Eq",
    /* EF */ "Fill",
    /* F0 */ "^",
    /* F1 */ TITOKEN_XRT,
    /* F2 */ "Solver",
    /* F3 */ "OneVar",
    /* F4 */ "LinR",
    /* F5 */ "ExpR",
    /* F6 */ "LnR",
    /* F7 */ "PwrR",
    /* F8 */ "ShwSt",
    /* F9 */ "Hist",
    /* FA */ "xyLine",
    /* FB */ "Scatter",
    /* FC */ "SortX",
    /* FD */ "SortY",
    /* FE */ "LU",
    /* FF */ NULL,
};

const char *const *const TIFILEUTILS_TOKENS_85 = tifileutils_tokens_85;