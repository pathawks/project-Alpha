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

    if (inCalc->FAMILY == TI83) {
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
                if (d <= (*TIFILEUTILS_TOKENS_83[c]&0xFF))
                    fprintf( out, "%s", ((char ***)TIFILEUTILS_TOKENS_83)[c][d+1] );
                continue;
    		default:
    			fprintf( out, "%s", TIFILEUTILS_TOKENS_83[c] );
            }
        }
    } else if (inCalc->FAMILY == TI86) {
    	while( inFileSize-- ) {
        	c = getc( in );
        	if( feof( in ) ) {
        		printf( "END OF FILE REACHED!" );
        		return EXIT_FAILURE;
        	}
            switch( c ) {
            case 0x2D: // opening quote;         zero-terminated string follows
            case 0xE0: // Lbl token;             zero-terminated string follows
            case 0xE1: // Goto token;            zero-terminated string follows
            case 0x44: // literal-number token;  zero-terminated string follows
            case 0x33: // 1 char var
            case 0x34: // 2 char var
            case 0x35: // 3 char var
            case 0x36: // 4 char var
            case 0x37: // 5 char var
            case 0x38: // 6 char var
            case 0x39: // 7 char var
            case 0x3A: // 8 char var
            case 0x32: // variable-name tokens
            case 0x3B: // variable-name tokens
            case 0x3C: // variable-name tokens
            case 0x3E: // conversion token
                continue;
            case 0x3D:
            case 0x8E:
                --inFileSize;
                int d = getc( in );
                if (d <= (*TIFILEUTILS_TOKENS_83[c]&0xFF))
                    fprintf( out, "%s", ((char ***)TIFILEUTILS_TOKENS_83)[c][d+1] );
                continue;
    		default:
    			fprintf( out, "%s", TIFILEUTILS_TOKENS_83[c] );
            }
        }
    }

    return EXIT_SUCCESS;
}
