#ifndef TICALCFAMILY_H
#define TICALCFAMILY_H

#include <stdlib.h>

typedef struct {
    const char* MAGIC_NUMBER;
    const char* NAME;
} CalcType;

const CalcType TI73;
const CalcType TI82;
const CalcType TI83;
const CalcType TI83P;
const CalcType TI85;
const CalcType TI86;
const CalcType TI89;
const CalcType TI92;
const CalcType TI92P;
CalcType const* const* TI_FAMILY;

#endif
