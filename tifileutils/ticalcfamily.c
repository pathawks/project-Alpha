#include "ticalcfamily.h"

const struct Calc sTI83 = {
    "**TI83**",
    "TI-83",
    0x47,
    &sTI83,
};

const struct Calc sTI73 = {
    "**TI73**",
    "TI-73",
    0x47,
    &sTI83,
};

const struct Calc sTI82 = {
    "**TI82**",
    "TI-82",
    0x47,
    &sTI83,
};

const struct Calc sTI83P = {
    "**TI83F*",
    "TI-84+",
    0x47,
    &sTI83,
};

const struct Calc sTI85 = {
    "**TI85**",
    "TI-85",
    0x39,
    &sTI85,
};

const struct Calc sTI86 = {
    "**TI86**",
    "TI-86",
    0x39,
    &sTI85,
};

const struct Calc sTI92 = {
    "**TI92**",
    "TI-92",
    0x4C,
    &sTI92,
};

const struct Calc sTI89 = {
    "**TI89**",
    "TI-89",
    0x4C,
    &sTI92,
};

const struct Calc sTI92P = {
    "**TI92P*",
    "TI-92+",
    0x4C,
    &sTI92,
};

const CalcType TI73  = &sTI73;
const CalcType TI82  = &sTI82;
const CalcType TI83  = &sTI83;
const CalcType TI83P = &sTI83P;
const CalcType TI85  = &sTI85;
const CalcType TI86  = &sTI86;
const CalcType TI89  = &sTI89;
const CalcType TI92  = &sTI92;
const CalcType TI92P = &sTI92P;

const CalcType tiFamilyArray[] = {
    &sTI73,
    &sTI82,
    &sTI83,
    &sTI83P,
    &sTI85,
    &sTI86,
    &sTI89,
    &sTI92,
    &sTI92P,
    NULL
};

const CalcType *const TI_FAMILY = tiFamilyArray;
