#ifndef TIFILEUTILS_H
#define TIFILEUTILS_H

#include <stdio.h>
#include <string.h>
#include "ticalcfamily.h"

CalcType tiDetectFileType(FILE*);
char** loadTokens(CalcType);

int tiCalcToText(FILE*, FILE*);

#endif
