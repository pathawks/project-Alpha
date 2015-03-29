#include "tifileutils.h"

const CalcType* tiDetectFileType(FILE* file) {
    char magicNumber[9];

    if (file == NULL) { goto error; }
    rewind(file);
    if (fgets (magicNumber, 9, file) == NULL) { goto error; }

    CalcType const* const* calc = TI_FAMILY;
    do {
        if (strcmp(magicNumber, (*calc)->MAGIC_NUMBER) == 0)
            return *calc;
    } while ( *++calc );

    return NULL;
    error:
    perror ("Error opening file");
    return NULL;
}
