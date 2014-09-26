/**
* @author:     Pat Hawks
* Created on:  Sept 06, 2014
* Source File: tiFileUtils.c
*/

#include <stdio.h>
#include <string.h>

#define setTiToken(x, value) tiTokenList[x] = value

#define TI73    10
#define TI80     4
#define TI81     1
#define TI82  0x10
#define TI83  0x11
#define TI83P 0x12
#define TI84P 0x13
#define TI84C 0x33
#define TI85     2
#define TI86     7
#define TI89     8
#define TI92     5
#define TI92P    9

#define TINSPIRE 0xFF

typedef int CalcType;

int setTiTokens( char *tiTokenList[256], int targetCalc, int format ) {

	switch(targetCalc) {
		case TI85:
		case TI86:
		case TI89:
		case TI92:
		case TI92P:
			setTiToken( 0x00, NULL ); // Unknown Character
			setTiToken( 0x01, "►Rec" );
			setTiToken( 0x02, "►Pol" );
			setTiToken( 0x03, "►Cyl" );
			setTiToken( 0x04, "►Sph" );
			setTiToken( 0x05, "►DMS" );
			setTiToken( 0x06, "►Bin" );
			setTiToken( 0x07, "►Hex" );
			setTiToken( 0x08, "►Oct" );
			setTiToken( 0x09, "►Dec" );
			setTiToken( 0x0A, "►Frac" ); // superscript
			setTiToken( 0x0B, "→" );
			setTiToken( 0x0C, "[" ); // superscript
			setTiToken( 0x0D, "]" ); // squared
			setTiToken( 0x0E, "{" ); // superscript
			setTiToken( 0x0F, "}" ); // cubed
			setTiToken( 0x10, "(" );
			setTiToken( 0x11, ")" );
			setTiToken( 0x12, "round(" );
			setTiToken( 0x13, "max" );
			setTiToken( 0x14, "min" );
			setTiToken( 0x15, "mod" );
			setTiToken( 0x16, "cross" );
			setTiToken( 0x17, "dot" );
			setTiToken( 0x18, "aug" );
			setTiToken( 0x19, "rSwap" );
			setTiToken( 0x1A, "rAdd" );
			setTiToken( 0x1B, "multR" );
			setTiToken( 0x1C, "mRAdd" );
			setTiToken( 0x1D, "sub" );
			setTiToken( 0x1E, "lcm" );
			setTiToken( 0x1F, "gcd" );
			setTiToken( 0x20, "simult" );
			setTiToken( 0x21, "inter" );
			setTiToken( 0x22, "pEval" );
			setTiToken( 0x23, "randM" );
			setTiToken( 0x24, "seq" );
			setTiToken( 0x25, "evalF" );
			setTiToken( 0x26, "fnInt" );
			setTiToken( 0x27, "arc" );
			setTiToken( 0x28, "fMin" );
			setTiToken( 0x29, "fMax" );
			setTiToken( 0x2A, "der1" );
			setTiToken( 0x2B, "der2" );
			setTiToken( 0x2C, "nDer" );
			setTiToken( 0x2D, "\"" );
			setTiToken( 0x2E, "" ); // Angle?
			setTiToken( 0x2F, "," );
			setTiToken( 0x30, " or " );
			setTiToken( 0x31, " xor " );
			setTiToken( 0x32, "" );
			setTiToken( 0x33, "" );
			setTiToken( 0x34, "" );
			setTiToken( 0x35, "" );
			setTiToken( 0x36, "" );
			setTiToken( 0x37, "" );
			setTiToken( 0x38, "" );
			setTiToken( 0x39, "" );
			setTiToken( 0x3A, "" );
			setTiToken( 0x3B, "" ); // ?
			setTiToken( 0x3C, "" );
			setTiToken( 0x3D, "" );
			setTiToken( 0x3E, "" );
			setTiToken( 0x3F, "=" );
			setTiToken( 0x40, " and " );
			setTiToken( 0x41, "rand" );
			setTiToken( 0x42, "𝜋" );
			setTiToken( 0x43, "getKy" );
			setTiToken( 0x44, "" );
			setTiToken( 0x45, "%%" );
			setTiToken( 0x46, "!" );
			setTiToken( 0x47, "r" ); // Superscript r
			setTiToken( 0x48, "°" );
			setTiToken( 0x49, "-1" ); // Superscript
			setTiToken( 0x4A, "2" ); // Superscript
			setTiToken( 0x4B, "T" ); // Superscript
			setTiToken( 0x4C, "Menu" );
			setTiToken( 0x4D, "P2Reg" );
			setTiToken( 0x4E, "P3Reg" );
			setTiToken( 0x4F, "P4Reg" );
			setTiToken( 0x50, "==" );
			setTiToken( 0x51, "<" );
			setTiToken( 0x52, ">" );
			setTiToken( 0x53, "≤" );
			setTiToken( 0x54, "≥" );
			setTiToken( 0x55, "≠" );
			setTiToken( 0x56, "Radian" );
			setTiToken( 0x57, "Degree" );
			setTiToken( 0x58, "Normal" );
			setTiToken( 0x59, "Sci" );
			setTiToken( 0x5A, "Eng" );
			setTiToken( 0x5B, "Float" );
			setTiToken( 0x5C, "Fix" );
			setTiToken( 0x5D, "RectV" );
			setTiToken( 0x5E, "CylV" );
			setTiToken( 0x5F, "SphereV" );
			setTiToken( 0x60, "+" );
			setTiToken( 0x61, "-" );
			setTiToken( 0x62, "Func" );
			setTiToken( 0x63, "Param" );
			setTiToken( 0x64, "Pol" );
			setTiToken( 0x65, "DifEq" );
			setTiToken( 0x66, "Bin" );
			setTiToken( 0x67, "Oct" );
			setTiToken( 0x68, "Hex" );
			setTiToken( 0x69, "Dec" );
			setTiToken( 0x6A, "RectC" );
			setTiToken( 0x6B, "PolarC" );
			setTiToken( 0x6C, "dxDer1" );
			setTiToken( 0x6D, "dxNDer" );
			setTiToken( 0x6E, ":" );
			setTiToken( 0x6F, "\n" );
			setTiToken( 0x70, "*" );
			setTiToken( 0x71, "/" );
			setTiToken( 0x72, "SeqG" );
			setTiToken( 0x73, "SimulG" );
			setTiToken( 0x74, "PolarGC" );
			setTiToken( 0x75, "RectGC" );
			setTiToken( 0x76, "CoordOn" );
			setTiToken( 0x77, "CoordOff" );
			setTiToken( 0x78, "DrawLine" );
			setTiToken( 0x79, "DrawDot" );
			setTiToken( 0x7A, "AxesOn" );
			setTiToken( 0x7B, "AxesOff" );
			setTiToken( 0x7C, "GridOn" );
			setTiToken( 0x7D, "GridOff" );
			setTiToken( 0x7E, "LabelOn" ); // Unknown Character
			setTiToken( 0x7F, "LabelOff" );
			setTiToken( 0x80, "nPr" );
			setTiToken( 0x81, "nCr" );
			setTiToken( 0x82, "Trace" );
			setTiToken( 0x83, "ClDrw" );
			setTiToken( 0x84, "ZStd" );
			setTiToken( 0x85, "ZTrig" );
			setTiToken( 0x86, "ZFit" );
			setTiToken( 0x87, "ZIn" );
			setTiToken( 0x88, "ZOut" );
			setTiToken( 0x89, "ZSqr" );
			setTiToken( 0x8A, "ZInt" );
			setTiToken( 0x8B, "ZPrev" );
			setTiToken( 0x8C, "ZDecm" );
			setTiToken( 0x8D, "ZRcl" );
			setTiToken( 0x8E, "" ); // Unknown Character
			setTiToken( 0x8F, "DrawF" );
			setTiToken( 0x90, "FnOn" );
			setTiToken( 0x91, "FnOff" );
			setTiToken( 0x92, "StPic" );
			setTiToken( 0x93, "RcPic" );
			setTiToken( 0x94, "StGDB" );
			setTiToken( 0x95, "RcGDB" );
			setTiToken( 0x96, "Line" );
			setTiToken( 0x97, "Vert" );
			setTiToken( 0x98, "PtOn" );
			setTiToken( 0x99, "PtOff" );
			setTiToken( 0x9A, "PtChg" );
			setTiToken( 0x9B, "Shade" );
			setTiToken( 0x9C, "Circl" );
			setTiToken( 0x9D, "Axes" );
			setTiToken( 0x9E, "TanLn" );
			setTiToken( 0x9F, "DrInv" );
			setTiToken( 0xA0, "√(" );
			setTiToken( 0xA1, "-" );
			setTiToken( 0xA2, "abs" );
			setTiToken( 0xA3, "iPart" );
			setTiToken( 0xA4, "fPart" );
			setTiToken( 0xA5, "int" );
			setTiToken( 0xA6, "ln" );
			setTiToken( 0xA7, "e^" );
			setTiToken( 0xA8, "log" );
			setTiToken( 0xA9, "10^" );
			setTiToken( 0xAA, "sin" );
			setTiToken( 0xAB, "sin-1" ); // Superscript -1
			setTiToken( 0xAC, "cos" );
			setTiToken( 0xAD, "cos-1" ); // Superscript -1
			setTiToken( 0xAE, "tan" );
			setTiToken( 0xAF, "tan-1" ); // Superscript -1
			setTiToken( 0xB0, "sinh" );
			setTiToken( 0xB1, "sinh-1" ); // Superscript -1
			setTiToken( 0xB2, "cosh" );
			setTiToken( 0xB3, "cosh-1" ); // Superscript -1
			setTiToken( 0xB4, "tanh" );
			setTiToken( 0xB5, "tanh-1" ); // Superscript -1
			setTiToken( 0xB6, "sign" );
			setTiToken( 0xB7, "det" );
			setTiToken( 0xB8, "ident" );
			setTiToken( 0xB9, "unitV" );
			setTiToken( 0xBA, "norm" );
			setTiToken( 0xBB, "rnorm" );
			setTiToken( 0xBC, "cnorm" );
			setTiToken( 0xBD, "ref" );
			setTiToken( 0xBE, "rref" );
			setTiToken( 0xBF, "dim" );
			setTiToken( 0xC0, "dimL" );
			setTiToken( 0xC1, "sum" );
			setTiToken( 0xC2, "prod" );
			setTiToken( 0xC3, "sortA" );
			setTiToken( 0xC4, "sortD" );
			setTiToken( 0xC5, "li►vc" );
			setTiToken( 0xC6, "vc►li" );
			setTiToken( 0xC7, "lngth" );
			setTiToken( 0xC8, "conj" );
			setTiToken( 0xC9, "real" );
			setTiToken( 0xCA, "imag" );
			setTiToken( 0xCB, "angle" );
			setTiToken( 0xCC, "not" );
			setTiToken( 0xCD, "rotR" );
			setTiToken( 0xCE, "rotL" );
			setTiToken( 0xCF, "shftR" );
			setTiToken( 0xD0, "shftL" );
			setTiToken( 0xD1, "eigVl" );
			setTiToken( 0xD2, "eigVc" );
			setTiToken( 0xD3, "cond" );
			setTiToken( 0xD4, "poly" );
			setTiToken( 0xD5, "fcstx" );
			setTiToken( 0xD6, "fcsty" );
			setTiToken( 0xD7, "eval" );
			setTiToken( 0xD8, "If " );
			setTiToken( 0xD9, "Then " );
			setTiToken( 0xDA, "Else " );
			setTiToken( 0xDB, "While " );
			setTiToken( 0xDC, "Repeat" );
			setTiToken( 0xDD, "For" );
			setTiToken( 0xDE, "End" );
			setTiToken( 0xDF, "Return" );
			setTiToken( 0xE0, "" ); // Unknown Character
			setTiToken( 0xE1, "" ); // Unknown Character
			setTiToken( 0xE2, "Pause " );
			setTiToken( 0xE3, "Stop" );
			setTiToken( 0xE4, "IS>" );
			setTiToken( 0xE5, "DS<" );
			setTiToken( 0xE6, "Input" );
			setTiToken( 0xE7, "Prompt " );
			setTiToken( 0xE8, "InpSt" );
			setTiToken( 0xE9, "Disp " );
			setTiToken( 0xEA, "DispG" );
			setTiToken( 0xEB, "Outpt" ); // List?
			setTiToken( 0xEC, "ClLCD" );
			setTiToken( 0xED, "Eq►St" );
			setTiToken( 0xEE, "St►Eq" );
			setTiToken( 0xEF, "Fill" );
			setTiToken( 0xF0, "^" );
			setTiToken( 0xF1, "x√(" ); // superscript x
			setTiToken( 0xF2, "Solver" );
			setTiToken( 0xF3, "OneVar" );
			setTiToken( 0xF4, "LinR" );
			setTiToken( 0xF5, "ExpR" );
			setTiToken( 0xF6, "LnR" );
			setTiToken( 0xF7, "PwrR" );
			setTiToken( 0xF8, "ShwSt" );
			setTiToken( 0xF9, "Hist" );
			setTiToken( 0xFA, "xyLine" );
			setTiToken( 0xFB, "Scatter" );
			setTiToken( 0xFC, "SortX" );
			setTiToken( 0xFD, "SortY" );
			setTiToken( 0xFE, "LU" );
			setTiToken( 0xFF, NULL ); // Unknown Character
			break;
		default:
			setTiToken( 0x00, NULL ); // Unknown Character
			setTiToken( 0x01, "►DMS" );
			setTiToken( 0x02, "►Dec" );
			setTiToken( 0x03, "►Frac" );
			setTiToken( 0x04, "→" );
			setTiToken( 0x05, "BoxPlot" );
			setTiToken( 0x06, "[" );
			setTiToken( 0x07, "]" );
			setTiToken( 0x08, "{" );
			setTiToken( 0x09, "}" );
			setTiToken( 0x0A, "r" ); // superscript
			setTiToken( 0x0B, "°" );
			setTiToken( 0x0C, "-1" ); // superscript
			setTiToken( 0x0D, "²" ); // squared
			setTiToken( 0x0E, "T" ); // superscript
			setTiToken( 0x0F, "³" ); // cubed
			setTiToken( 0x10, "(" );
			setTiToken( 0x11, ")" );
			setTiToken( 0x12, "round(" );
			setTiToken( 0x13, "pxl-Test(" );
			setTiToken( 0x14, "augment(" );
			setTiToken( 0x15, "rowSwap(" );
			setTiToken( 0x16, "row+(" );
			setTiToken( 0x17, "*row(" );
			setTiToken( 0x18, "*row+(" );
			setTiToken( 0x19, "max(" );
			setTiToken( 0x1A, "min(" );
			setTiToken( 0x1B, "R►Pr(" );
			setTiToken( 0x1C, "R►P𝜽(" );
			setTiToken( 0x1D, "R►Rx(" );
			setTiToken( 0x1E, "R►Ry(" );
			setTiToken( 0x1F, "median(" );
			setTiToken( 0x20, "randM(" );
			setTiToken( 0x21, "mean(" );
			setTiToken( 0x22, "solve(" );
			setTiToken( 0x23, "seq(" );
			setTiToken( 0x24, "fnInt(" );
			setTiToken( 0x25, "nDeriv(" );
			setTiToken( 0x26, NULL ); // Unknown Character // ?
			setTiToken( 0x27, "fMin(" );
			setTiToken( 0x28, "fMax(" );
			setTiToken( 0x29, " " );
			setTiToken( 0x2A, "\"" ); // Unknown Character
			setTiToken( 0x2B, "," );
			setTiToken( 0x2C, "𝒊" );
			setTiToken( 0x2D, "!" );
			setTiToken( 0x2E, "CubicReg " );
			setTiToken( 0x2F, "QuartReg " );
			setTiToken( 0x30, "0" );
			setTiToken( 0x31, "1" );
			setTiToken( 0x32, "2" );
			setTiToken( 0x33, "3" );
			setTiToken( 0x34, "4" );
			setTiToken( 0x35, "5" );
			setTiToken( 0x36, "6" );
			setTiToken( 0x37, "7" );
			setTiToken( 0x38, "8" );
			setTiToken( 0x39, "9" );
			setTiToken( 0x3A, "." );
			setTiToken( 0x3B, "E" ); // ?
			setTiToken( 0x3C, " or " );
			setTiToken( 0x3D, " xor " );
			setTiToken( 0x3E, ":" );
			setTiToken( 0x3F, "\n" );
			setTiToken( 0x40, " and " );
			setTiToken( 0x41, "A" );
			setTiToken( 0x42, "B" );
			setTiToken( 0x43, "C" );
			setTiToken( 0x44, "D" );
			setTiToken( 0x45, "E" );
			setTiToken( 0x46, "F" );
			setTiToken( 0x47, "G" );
			setTiToken( 0x48, "H" );
			setTiToken( 0x49, "I" );
			setTiToken( 0x4A, "J" );
			setTiToken( 0x4B, "K" );
			setTiToken( 0x4C, "L" );
			setTiToken( 0x4D, "M" );
			setTiToken( 0x4E, "N" );
			setTiToken( 0x4F, "O" );
			setTiToken( 0x50, "P" );
			setTiToken( 0x51, "Q" );
			setTiToken( 0x52, "R" );
			setTiToken( 0x53, "S" );
			setTiToken( 0x54, "T" );
			setTiToken( 0x55, "U" );
			setTiToken( 0x56, "V" );
			setTiToken( 0x57, "W" );
			setTiToken( 0x58, "X" );
			setTiToken( 0x59, "Y" );
			setTiToken( 0x5A, "Z" );
			setTiToken( 0x5B, "𝜽" );
			setTiToken( 0x5C, NULL ); // Unknown Character
			setTiToken( 0x5D, NULL ); // Unknown Character
			setTiToken( 0x5E, NULL ); // Unknown Character
			setTiToken( 0x5F, "prgm" );
			setTiToken( 0x60, NULL ); // Unknown Character
			setTiToken( 0x61, NULL ); // Unknown Character
			setTiToken( 0x62, NULL ); // Lowercase letter follows?
			setTiToken( 0x63, NULL ); // Unknown Character
			setTiToken( 0x64, "Radian" );
			setTiToken( 0x65, "Degree" );
			setTiToken( 0x66, "Normal" );
			setTiToken( 0x67, "Sci" );
			setTiToken( 0x68, "Eng" );
			setTiToken( 0x69, "Float" );
			setTiToken( 0x6A, "=" );
			setTiToken( 0x6B, "<" );
			setTiToken( 0x6C, ">" );
			setTiToken( 0x6D, "≤" );
			setTiToken( 0x6E, "≥" );
			setTiToken( 0x6F, "≠" );
			setTiToken( 0x70, "+" );
			setTiToken( 0x71, "-" );
			setTiToken( 0x72, "Ans" );
			setTiToken( 0x73, "Fix " );
			setTiToken( 0x74, "Horiz" );
			setTiToken( 0x75, "Full" );
			setTiToken( 0x76, "Func" );
			setTiToken( 0x77, "Param" );
			setTiToken( 0x78, "Polar" );
			setTiToken( 0x79, "Seq" );
			setTiToken( 0x7A, "IndpntAuto" );
			setTiToken( 0x7B, "IndpntAsk" );
			setTiToken( 0x7C, "DependAuto" );
			setTiToken( 0x7D, "DependAsk" );
			setTiToken( 0x7E, NULL ); // Unknown Character
			setTiToken( 0x7F, "☐" );
			setTiToken( 0x80, "✛" );
			setTiToken( 0x81, "∙" );
			setTiToken( 0x82, "*" );
			setTiToken( 0x83, "/" );
			setTiToken( 0x84, "Trace" );
			setTiToken( 0x85, "ClrDraw" );
			setTiToken( 0x86, "ZStandard" );
			setTiToken( 0x87, "ZTrig" );
			setTiToken( 0x88, "ZBox" );
			setTiToken( 0x89, "Zoom In" );
			setTiToken( 0x8A, "Zoom Out" );
			setTiToken( 0x8B, "ZSquare" );
			setTiToken( 0x8C, "ZInteger" );
			setTiToken( 0x8D, "ZPrevious" );
			setTiToken( 0x8E, "ZDecimal" );
			setTiToken( 0x8F, "ZoomStat" );
			setTiToken( 0x90, "ZoomRcl" );
			setTiToken( 0x91, "PrintScreen" );
			setTiToken( 0x92, "ZoomSto" );
			setTiToken( 0x93, "Text(" );
			setTiToken( 0x94, " nPr " );
			setTiToken( 0x95, " nCr " );
			setTiToken( 0x96, "FnOn " );
			setTiToken( 0x97, "FnOff " );
			setTiToken( 0x98, "StorePic " );
			setTiToken( 0x99, "RecallPic " );
			setTiToken( 0x9A, "StoreGDB " );
			setTiToken( 0x9B, "RecallGDB " );
			setTiToken( 0x9C, "Line(" );
			setTiToken( 0x9D, "Vertical " );
			setTiToken( 0x9E, "Pt-On(" );
			setTiToken( 0x9F, "Pt-Off(" );
			setTiToken( 0xA0, "Pt-Change(" );
			setTiToken( 0xA1, "Pxl-On(" );
			setTiToken( 0xA2, "Pxl-Off(" );
			setTiToken( 0xA3, "Pxl-Change(" );
			setTiToken( 0xA4, "Shade(" );
			setTiToken( 0xA5, "Circle(" );
			setTiToken( 0xA6, "Horizontal " );
			setTiToken( 0xA7, "Tangent(" );
			setTiToken( 0xA8, "DrawInv " );
			setTiToken( 0xA9, "DrawF " );
			setTiToken( 0xAA, NULL ); // Unknown Character
			setTiToken( 0xAB, "rand" );
			setTiToken( 0xAC, "𝜋" );
			setTiToken( 0xAD, "getKey" );
			setTiToken( 0xAE, "''" );
			setTiToken( 0xAF, "?" );
			setTiToken( 0xB0, "-" ); // superscript
			setTiToken( 0xB1, "int(" );
			setTiToken( 0xB2, "abs(" );
			setTiToken( 0xB3, "det(" );
			setTiToken( 0xB4, "identity(" );
			setTiToken( 0xB5, "dim(" );
			setTiToken( 0xB6, "sum(" );
			setTiToken( 0xB7, "prod(" );
			setTiToken( 0xB8, "not(" );
			setTiToken( 0xB9, "iPart(" );
			setTiToken( 0xBA, "fPart(" );
			setTiToken( 0xBB, NULL ); // Unknown Character
			setTiToken( 0xBC, "√(" );
			setTiToken( 0xBD, "∛(" );
			setTiToken( 0xBE, "ln_(" );
			setTiToken( 0xBF, "e^(" ); // Math italics e
			setTiToken( 0xC0, "log(" );
			setTiToken( 0xC1, "10^(" ); // subscript 10?
			setTiToken( 0xC2, "sin(" );
			setTiToken( 0xC3, "sin-1(" ); // superscript -1
			setTiToken( 0xC4, "cos(" );
			setTiToken( 0xC5, "cos-1(" ); // superscript -1
			setTiToken( 0xC6, "tan(" );
			setTiToken( 0xC7, "tan-1(" ); // superscript -1
			setTiToken( 0xC8, "sinh(" );
			setTiToken( 0xC9, "sinh-1(" ); // superscript -1
			setTiToken( 0xCA, "cosh(" );
			setTiToken( 0xCB, "cosh-1(" ); // superscript -1
			setTiToken( 0xCC, "tanh(" );
			setTiToken( 0xCD, "tanh-1(" ); // superscript -1
			setTiToken( 0xCE, "If " );
			setTiToken( 0xCF, "Then" );
			setTiToken( 0xD0, "Else" );
			setTiToken( 0xD1, "While " );
			setTiToken( 0xD2, "Repeat " );
			setTiToken( 0xD3, "For(" );
			setTiToken( 0xD4, "End" );
			setTiToken( 0xD5, "Return" );
			setTiToken( 0xD6, "Lbl " );
			setTiToken( 0xD7, "Goto " );
			setTiToken( 0xD8, "Pause " );
			setTiToken( 0xD9, "Stop" );
			setTiToken( 0xDA, "IS>(" );
			setTiToken( 0xDB, "DS>(" );
			setTiToken( 0xDC, "Input " );
			setTiToken( 0xDD, "Prompt " );
			setTiToken( 0xDE, "Disp " );
			setTiToken( 0xDF, "DispGraph" );
			setTiToken( 0xE0, "Output(" );
			setTiToken( 0xE1, "ClrHome" );
			setTiToken( 0xE2, "Fill(" );
			setTiToken( 0xE3, "SortA(" );
			setTiToken( 0xE4, "SortD(" );
			setTiToken( 0xE5, "DispTable" );
			setTiToken( 0xE6, "Menu(" );
			setTiToken( 0xE7, "Send(" );
			setTiToken( 0xE8, "Get(" );
			setTiToken( 0xE9, "PlotsOn " );
			setTiToken( 0xEA, "PlotsOff " );
			setTiToken( 0xEB, "L" ); // List?
			setTiToken( 0xEC, "Plot1(" );
			setTiToken( 0xED, "Plot2(" );
			setTiToken( 0xEE, "Plot3(" );
			setTiToken( 0xEF, NULL ); // Unknown Character
			setTiToken( 0xF0, "^" );
			setTiToken( 0xF1, "x√(" ); // superscript x
			setTiToken( 0xF2, "1-Var_Stats " );
			setTiToken( 0xF3, "2-Var_Stats " );
			setTiToken( 0xF4, "LinReg(a+bx) " );
			setTiToken( 0xF5, "ExpReg " );
			setTiToken( 0xF6, "LnReg " );
			setTiToken( 0xF7, "PwrReg " );
			setTiToken( 0xF8, "Med-Med " );
			setTiToken( 0xF9, "QuadReg " );
			setTiToken( 0xFA, "ClrList " );
			setTiToken( 0xFB, "ClrTable" );
			setTiToken( 0xFC, "Histogram" );
			setTiToken( 0xFD, "xyLine" );
			setTiToken( 0xFE, "Scatter" );
			setTiToken( 0xFF, "LinReg(ax+b) " );
	}

	return 0;
}

static char getNextByte( FILE *inputFileHandle, int *size) {
	char c = fgetc( inputFileHandle );
	if( feof( inputFileHandle ) ) {
		printf( "END OF FILE REACHED!" );
	}
	*size = *size - 1;
	return c;
}

CalcType detectTiInputFileType( FILE *inputFileHandle ) {
	int numberOfBytesInMagicNumber = 11, i = 0;
	char calcMagicNumber[11];
	CalcType targetCalc = 0;

	fseek( inputFileHandle, 0, SEEK_SET );

	while( i < numberOfBytesInMagicNumber ){
		calcMagicNumber[i++] =
			fgetc(inputFileHandle);
	}

	targetCalc = 0;

	switch( calcMagicNumber[5] ) {
		case '5':
			targetCalc = TI85;
			break;
		case '6':
			targetCalc = TI86;
			break;
		case '9':
			targetCalc = TI89;
			break;
		case '2':
			if (calcMagicNumber[4]=='8') {
				targetCalc = TI82;
			} else {
				targetCalc = calcMagicNumber[6]=='*' ? TI92 : TI92P;
			}
			break;
		case '3':
			if ( calcMagicNumber[4]=='8' ) {
				if ( calcMagicNumber[6] == '*' ) {
						targetCalc = TI83;
					} else {
						targetCalc = calcMagicNumber[10] ? TI83P : TI84C;
				}
			} else {
				targetCalc = TI73;
			}
			break;
		case 'p':
			if ( calcMagicNumber[0] == '*' && calcMagicNumber[1] == 'T' && calcMagicNumber[2] == 'I' && calcMagicNumber[3] == 'M' && calcMagicNumber[4] == 'L' && calcMagicNumber[5] == 'P' && calcMagicNumber[6] == '0' && calcMagicNumber[9] == '0' ) {
				switch ( calcMagicNumber[7] ) {
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
						targetCalc = TINSPIRE;
						break;
				}
			}
	}

	if ( targetCalc != TINSPIRE && ( calcMagicNumber[0] != '*' || calcMagicNumber[1] != '*' || calcMagicNumber[2] != 'T' || calcMagicNumber[3] != 'I' ) ) {
		targetCalc = 0;
	}

	return targetCalc;
}

static inline int convertCalcData83( CalcType targetCalc, FILE *inputFileHandle, FILE *outputFileHandle ) {
	register unsigned char c;
	int size;
	int sizeOffset = 0x47;
	int tokenizedFile = 1;
	const char *tiTokenList[256];

	setTiTokens( (char **)tiTokenList, targetCalc, 0 );

	fseek( inputFileHandle, sizeOffset, SEEK_SET );
	size = fgetc( inputFileHandle ) * 256 + fgetc( inputFileHandle );

	fgetc( inputFileHandle );

	if ( tokenizedFile ) {
		while( size-- ) {
			c = fgetc( inputFileHandle );
			if( feof( inputFileHandle ) ) {
				printf( "END OF FILE REACHED!" );
				break;
			}
			switch(c){
				case 0x5C: // Matrix
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "[%c]", c + 0x41 );
					break;
				case 0x5D: // List
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "L%c", (c+1)%10 + 0x30 );
					break;
				case 0x5E: // Could be one of three things...
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "?" );
					break;
				case 0x60: // Pic
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "Pic%c", (c+1)%10 + 0x30 );
					break;
				case 0x61: // Pic
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "GDB%c", (c+1)%10 + 0x30 );
					break;
				case 0x62: // More complicated than this...
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "z" );
					break;
				case 0x63: // More complicated than this...
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "?" );
					break;
				case 0xAA: // More complicated than this...
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "Str%c", (c+1)%10 + 0x30 );
					break;
				default:
					if (tiTokenList[(unsigned char)c])
						fprintf( outputFileHandle, "%s", tiTokenList[(unsigned char)c] );
			}
		}
	} else {
		while( size-- ) {
			c = fgetc( inputFileHandle );
			if( feof( inputFileHandle ) ) {
				printf( "END OF FILE REACHED!" );
				break;
			}
			fprintf( outputFileHandle, "%c", c );
		}
	}
	fprintf( outputFileHandle, "\n" );

	return 0;
}

static inline int convertCalcData85( CalcType targetCalc, FILE *inputFileHandle, FILE *outputFileHandle ) {
	register unsigned char c;
	int size;
	int sizeOffset = 0x39;
	const char *tiTokenList[256];

	fseek( inputFileHandle, sizeOffset, SEEK_SET );
	c = fgetc( inputFileHandle );
	while( c != fgetc( inputFileHandle ) );
	size = fgetc( inputFileHandle ) * 256 + fgetc( inputFileHandle );
	fgetc( inputFileHandle );

	setTiTokens( (char **)tiTokenList, targetCalc, 0 );

	while( size-- ) {
		c = fgetc( inputFileHandle );
		if( feof( inputFileHandle ) ) {
			printf( "END OF FILE REACHED!" );
			break;
		}
		switch(c) {
			case 0x44: // literal-number token
				c = getNextByte( inputFileHandle, &size);
				while( c ) {
					fprintf( outputFileHandle, "%c", c );
					c = fgetc( inputFileHandle );
					size--;
				}
				break;
			case 0x2D:
				fprintf( outputFileHandle, "\"" );
				c = getNextByte( inputFileHandle, &size);
				while( c ) {
					fprintf( outputFileHandle, "%c", c );
					c = getNextByte( inputFileHandle, &size);
				}
				fprintf( outputFileHandle, "\"" );
				break;
			case 0x3A: // { These are all intended to fall through!
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x39:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x38:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x37:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x36:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x35:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x34:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x33:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
				break; // }
			case 0x32:
			case 0x3B:
			case 0x3C:
				c = getNextByte( inputFileHandle, &size);
				while( c ) {
					fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
					c--;
				}
				break;
			case 0x3D:
			case 0x8E:
				getNextByte( inputFileHandle, &size);
				break;
			case 0xE0:
				fprintf( outputFileHandle, "Lbl ");
				c = getNextByte( inputFileHandle, &size);
				while( !c ) {
					c = getNextByte( inputFileHandle, &size);
				}
				while( c ) {
					fprintf( outputFileHandle, "%c", c );
					c = getNextByte( inputFileHandle, &size);
				}
				break;
			case 0xE1:
				fprintf( outputFileHandle, "Goto ");
				c = getNextByte( inputFileHandle, &size);
				while( !c ) {
					c = getNextByte( inputFileHandle, &size);
				}
				while( c ) {
					fprintf( outputFileHandle, "%c", c );
					c = getNextByte( inputFileHandle, &size);
				}
				break;
			default:
				if (tiTokenList[(unsigned char)c]) {
					fprintf( outputFileHandle, "%s", tiTokenList[(unsigned char)c] );
				}
		}
	}
	fprintf( outputFileHandle, "\n" );

	return 0;
}

static inline int convertCalcData92( CalcType targetCalc, FILE *inputFileHandle, FILE *outputFileHandle ) {
	register unsigned char c;
	int size;
	// int sizeOffset = 0x56;
	int sizeOffset = 0x4C;
	int tokenizedFile;
	const char *tiTokenList[256];

	setTiTokens( (char **)tiTokenList, targetCalc, 0 );

	fseek( inputFileHandle, 0x49, SEEK_SET );
		tokenizedFile = fgetc( inputFileHandle ) != 0;

	fseek( inputFileHandle, sizeOffset, SEEK_SET );
	c = fgetc( inputFileHandle );
	size = 256 * fgetc( inputFileHandle ) + c - 0x52;

	if (!tokenizedFile) {
		size -= 0x12;
	}

	fseek( inputFileHandle, 0x58, SEEK_SET );

	if ( tokenizedFile ) {
		while( size-- ) {
			c = fgetc( inputFileHandle );
			if( feof( inputFileHandle ) ) {
				printf( "END OF FILE REACHED!" );
				break;
			}
			if (tiTokenList[(unsigned char)c])
				fprintf( outputFileHandle, "%s", tiTokenList[(unsigned char)c] );
		}
	} else {
		while( size-- ) {
			c = fgetc( inputFileHandle );
			if( feof( inputFileHandle ) ) {
				printf( "END OF FILE REACHED!" );
				break;
			}
			fprintf( outputFileHandle, "%c", c );
		}
	}
	fprintf( outputFileHandle, "\n" );

	return 0;
}

int convertCalcData( CalcType targetCalc, FILE *inputFileHandle, FILE *outputFileHandle ) {
	int sucessCode;

	switch(targetCalc) {
		case TI89:
		case TI92:
		case TI92P:
			sucessCode = convertCalcData92( targetCalc, inputFileHandle, outputFileHandle );
			break;
		case TI85:
		case TI86:
			sucessCode = convertCalcData85( targetCalc, inputFileHandle, outputFileHandle );
			break;
		default:
			sucessCode = convertCalcData83( targetCalc, inputFileHandle, outputFileHandle );
			break;
	}

	return 0;
}
