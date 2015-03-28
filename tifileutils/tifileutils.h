#ifndef TIFILEUTILS_H
#define TIFILEUTILS_H

#include <stdio.h>
#include <string.h>
#include "ticalcfamily.h"

const CalcType* tiDetectFileType(FILE* file) {
    char magicNumber[9];
    unsigned int i;

    if (file == NULL) { goto error; }
    rewind(file);
    if (fgets (magicNumber, 9, file) == NULL) { goto error; }

    for(i=0; i <= TI_FAMILY_SIZE; i++)
        if (strcmp(magicNumber, TI_FAMILY[i]->MAGIC_NUMBER) == 0)
            return TI_FAMILY[i];

    return NULL;
    error:
    perror ("Error opening file");
    return NULL;
}

#endif
