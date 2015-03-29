#include "ticalcfamily.h"

const CalcType TI73 = {
    "**TI73**",
    "TI-73"
};

const CalcType TI82 = {
    "**TI82**",
    "TI-82"
};

const CalcType TI83 = {
    "**TI83**",
    "TI-83"
};

const CalcType TI83P = {
    "**TI83F*",
    "TI-84+"
};

const CalcType TI85 = {
    "**TI85**",
    "TI-85"
};

const CalcType TI86 = {
    "**TI86**",
    "TI-86"
};

const CalcType TI89 = {
    "**TI89**",
    "TI-89"
};

const CalcType TI92 = {
    "**TI92**",
    "TI-92"
};

const CalcType TI92P = {
    "**TI92P*",
    "TI-92+"
};

CalcType const* const tiFamilyArray[] = {
    &TI73,
    &TI82,
    &TI83,
    &TI83P,
    &TI85,
    &TI86,
    &TI89,
    &TI92,
    &TI92P,
    NULL
};

CalcType const* const* TI_FAMILY = tiFamilyArray;
