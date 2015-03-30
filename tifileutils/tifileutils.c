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

int tiCalcToText(FILE* in, FILE* out) {
    int inFileSize;
    char c;
    CalcType inCalc;

    if (!in) {
        printf("Cannot read input file\n");
        exit(EXIT_FAILURE);
    }
    if (!out) {
        printf("Cannot read output file\n");
        exit(EXIT_FAILURE);
    }

    inCalc = tiDetectFileType(in);
    if ( !inCalc ) {
		printf("%s\n", "Input file is not a recognized calculator file type");
        exit(EXIT_FAILURE);
    }


    fseek( in, inCalc->SIZE_OFFSET, SEEK_SET );

    inFileSize = 0x100 * getc( in ) + getc( in );
    getc( in );

    return EXIT_SUCCESS;
}
