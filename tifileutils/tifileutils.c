#include "tifileutils.h"

CalcType tiDetectFileType(FILE* file) {
    char magicNumber[9];

    if (file == NULL) { goto error; }
    rewind(file);
    if (fgets (magicNumber, 9, file) == NULL) { goto error; }

    const CalcType *calc = TI_FAMILY;
    do {
        if (strcmp(magicNumber, (*calc)->MAGIC_NUMBER) == 0)
            return *calc;
    } while ( *++calc );

    return NULL;
    error:
    perror ("Error opening file");
    return NULL;
}
