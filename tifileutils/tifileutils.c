#include "tifileutils.h"
#include "83/tokens.h"

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

int tiCalcFileSize(FILE* in, CalcType inCalc) {
    int inFileSize;

    fseek( in, inCalc->SIZE_OFFSET, SEEK_SET );
    inFileSize = 0x100 * getc( in ) + getc( in );
    getc( in );

    return inFileSize;
}

int tiCalcToText(FILE* in, FILE* out) {
    int inFileSize;
    char * const* tiTokenList = (char *const *)tifileutils_tokens_83;
    int c;
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

    inFileSize = tiCalcFileSize( in, inCalc );

	while( inFileSize-- ) {
    	c = getc( in );
    	if( feof( in ) ) {
    		printf( "END OF FILE REACHED!" );
    		return EXIT_FAILURE;
    	}
        switch( c ) {
        case 0x5C:
        case 0x5D:
        case 0x5E:
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:
        case 0x7E:
        case 0xAA:
        case 0xBB:
            --inFileSize;
            int d = getc( in );
            if (d <= (*tiTokenList[c]&0xFF))
                fprintf( out, "%s", ((char ***)tiTokenList)[c][d+1] );
            continue;
		default:
			fprintf( out, "%s", tiTokenList[c] );
        }
    }

    return EXIT_SUCCESS;
}
