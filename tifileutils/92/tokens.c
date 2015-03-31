#include <stdlib.h>
#include "../tokens.h"
#include "tokens.h"

const char* const tifileutils_tokens_92[0x0100] = {
    /* 00 */ NULL,
    /* 01 */ NULL,
    /* 02 */ "r",
    /* 03 */ "s",
    /* 04 */ "t",
    /* 05 */ "u",
    /* 06 */ "v",
    /* 07 */ "w",
    /* 08 */ "x",
    /* 09 */ "y",
    /* 0A */ "z",
    /* 0B */ "a",
    /* 0C */ "b",
    /* 0D */ "c",
    /* 0E */ "d",
    /* 0F */ "e",
    /* 10 */ "f",
    /* 11 */ "g",
    /* 12 */ "h",
    /* 13 */ "i",
    /* 14 */ "j",
    /* 15 */ "k",
    /* 16 */ "l",
    /* 17 */ "m",
    /* 18 */ "n",
    /* 19 */ "o",
    /* 1A */ "p",
    /* 1B */ "q",
    /* 1C */ "link",
    /* 1D */ NULL,
    /* 1E */ NULL,
    /* 1F */ NULL,
    /* 20 */ NULL,
    /* 21 */ NULL,
    /* 22 */ NULL,
    /* 23 */ NULL,
    /* 24 */ TITOKEN_PI,
    /* 25 */ TITOKEN_e,
    /* 26 */ TITOKEN_i,
    /* 27 */ TITOKEN_INFIN,
    /* 28 */ TITOKEN_INFIN,
    /* 29 */ NULL,
    /* 2A */ "undef",
    /* 2B */ "false",
    /* 2C */ "true",
    /* 2D */ NULL,
    /* 2E */ NULL,
    /* 2F */ "acosh(",
    /* 30 */ "asinh(",
    /* 31 */ "atanh(",
    /* 32 */ NULL,
    /* 33 */ NULL,
    /* 34 */ NULL,
    /* 35 */ "cosh(",
    /* 36 */ "sinh(",
    /* 37 */ "tanh(",
    /* 38 */ NULL,
    /* 39 */ NULL,
    /* 3A */ NULL,
    /* 3B */ "acos(",
    /* 3C */ "asin(",
    /* 3D */ "atan(",
    /* 3E */ NULL,
    /* 3F */ NULL,
    /* 40 */ NULL,
    /* 41 */ NULL,
    /* 42 */ NULL,
    /* 43 */ NULL,
    /* 44 */ "cos(",
    /* 45 */ "sin(",
    /* 46 */ "tan(",
    /* 47 */ NULL,
    /* 48 */ NULL,
    /* 49 */ NULL,
    /* 4A */ NULL,
    /* 4B */ "abs(",
    /* 4C */ "angle(",
    /* 4D */ "ceiling(",
    /* 4E */ "floor(",
    /* 4F */ "int(",
    /* 50 */ "sign(",
    /* 51 */ TITOKEN_SQRT "(",
    /* 52 */ TITOKEN_e "^(",
    /* 53 */ "ln(",
    /* 54 */ "log(",
    /* 55 */ "fPart(",
    /* 56 */ "iPart(",
    /* 57 */ "conj(",
    /* 58 */ "imag(",
    /* 59 */ "real(",
    /* 5A */ "approx(",
    /* 5B */ "tExpand(",
    /* 5C */ "tCollect(",
    /* 5D */ "getDenom(",
    /* 5E */ "getNum(",
    /* 5F */ NULL,
    /* 60 */ "cumSum(",
    /* 61 */ "det(",
    /* 62 */ "colNorm(",
    /* 63 */ "rowNorm(",
    /* 64 */ "norm(",
    /* 65 */ "mean(",
    /* 66 */ "median(",
    /* 67 */ "product(",
    /* 68 */ "stdDev(",
    /* 69 */ "sum(",
    /* 6A */ "variance(",
    /* 6B */ "unitV(",
    /* 6C */ "dim(",
    /* 6D */ "mat" TITOKEN_TRIANGLE "list(",
    /* 6E */ "newList(",
    /* 6F */ "rref(",
    /* 70 */ "ref(",
    /* 71 */ "identity(",
    /* 72 */ "diag(",
    /* 73 */ "colDim(",
    /* 74 */ "rowDim(",
    /* 75 */ TITOKEN_SUP_T,
    /* 76 */ "!",
    /* 77 */ "%",
    /* 78 */ TITOKEN_SUP_r,
    /* 79 */ "not(",
    /* 7A */ "-",
    /* 7B */ NULL,
    /* 7C */ NULL,
    /* 7D */ NULL,
    /* 7E */ NULL,
    /* 7F */ NULL,
    /* 80 */ TITOKEN_ARROW,
    /* 81 */ "|",
    /* 82 */ " xor ",
    /* 83 */ " or ",
    /* 84 */ " and ",
    /* 85 */ "<",
    /* 86 */ TITOKEN_LTE,
    /* 87 */ "=",
    /* 88 */ TITOKEN_GTE,
    /* 89 */ ">",
    /* 8A */ TITOKEN_NOT_EQUAL,
    /* 8B */ "+",
    /* 8C */ ".+",
    /* 8D */ "-",
    /* 8E */ ".-",
    /* 8F */ "*",
    /* 90 */ ".*",
    /* 91 */ "/",
    /* 92 */ "./",
    /* 93 */ "^",
    /* 94 */ ".^",
    /* 95 */ NULL,
    /* 96 */ "solve(",
    /* 97 */ "cSolve(",
    /* 98 */ "nSolve(",
    /* 99 */ "zeros(",
    /* 9A */ "cZeros(",
    /* 9B */ "fMin(",
    /* 9C */ "fMax(",
    /* 9D */ NULL,
    /* 9E */ "polyEval(",
    /* 9F */ "randPoly(",
    /* A0 */ "crossP(",
    /* A1 */ "dotP(",
    /* A2 */ "gcd(",
    /* A3 */ "lcm(",
    /* A4 */ "mod(",
    /* A5 */ "intDiv(",
    /* A6 */ "remain(",
    /* A7 */ "nCr(",
    /* A8 */ "nPr(",
    /* A9 */ "P" TITOKEN_TRIANGLE "Rx(",
    /* AA */ "P" TITOKEN_TRIANGLE "Rx(",
    /* AB */ "R" TITOKEN_TRIANGLE "P" TITOKEN_THETA "(",
    /* AC */ "R" TITOKEN_TRIANGLE "Pr(",
    /* AD */ "augment(",
    /* AE */ "newMat(",
    /* AF */ "randMat(",
    /* B0 */ "simult(",
    /* B1 */ NULL,
    /* B2 */ "exp" TITOKEN_TRIANGLE "list(",
    /* B3 */ "randNorm(",
    /* B4 */ "mRow(",
    /* B5 */ "rowAdd(",
    /* B6 */ "rowSwap(",
    /* B7 */ "arcLen(",
    /* B8 */ "nInt(",
    /* B9 */ TITOKEN_PI "(",
    /* BA */ TITOKEN_SUMMATION "(",
    /* BB */ "mRowAdd(",
    /* BC */ NULL,
    /* BD */ NULL,
    /* BE */ "exact(",
    /* BF */ NULL,
    /* C0 */ "comDenom(",
    /* C1 */ "expand(",
    /* C2 */ "factor(",
    /* C3 */ "cFactor(",
    /* C4 */ TITOKEN_INTEGRAL "(",
    /* C5 */ TITOKEN_d "(",
    /* C6 */ "avgRC(",
    /* C7 */ "nDeriv(",
    /* C8 */ "taylor(",
    /* C9 */ "limit(",
    /* CA */ "propFrac(",
    /* CB */ "when(",
    /* CC */ "round(",
    /* CD */ NULL,
    /* CE */ "left(",
    /* CF */ "right(",
    /* D0 */ "mid(",
    /* D1 */ "shift(",
    /* D2 */ "seq(",
    /* D3 */ "list" TITOKEN_TRIANGLE "mat(",
    /* D4 */ "subMat(",
    /* D5 */ NULL,
    /* D6 */ "rand(",
    /* D7 */ "min(",
    /* D8 */ "max(",
    /* D9 */ NULL,
    /* DA */ NULL,
    /* DB */ NULL,
    /* DC */ NULL,
    /* DD */ NULL,
    /* DE */ NULL,
    /* DF */ NULL,
    /* E0 */ NULL,
    /* E1 */ NULL,
    /* E2 */ NULL,
    /* E3 */ NULL,
    /* E4 */ NULL,
    /* E5 */ NULL,
    /* E6 */ TITOKEN_COPYRIGHT,
    /* E7 */ NULL,
    /* E8 */ NULL,
    /* E9 */ NULL,
    /* EA */ NULL,
    /* EB */ NULL,
    /* EC */ NULL,
    /* ED */ NULL,
    /* EE */ NULL,
    /* EF */ NULL,
    /* F0 */ NULL,
    /* F1 */ NULL,
    /* F2 */ NULL,
    /* F3 */ NULL,
    /* F4 */ NULL,
    /* F5 */ NULL,
    /* F6 */ NULL,
    /* F7 */ NULL,
    /* F8 */ NULL,
    /* F9 */ NULL,
    /* FA */ NULL,
    /* FB */ NULL,
    /* FC */ NULL,
    /* FD */ NULL,
    /* FE */ NULL,
    /* FF */ NULL,
};

const char *const *const TIFILEUTILS_TOKENS_92 = tifileutils_tokens_92;