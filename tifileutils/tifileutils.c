#include "tifileutils.h"
#include "83/tokens.h"
#include "85/tokens.h"
#include "92/tokens.h"

CalcType tiDetectFileType(FILE* file) {
    const CalcType *calc = TI_FAMILY;
    char magicNumber[12];
    int i;

    if (file == NULL) { goto error; }
    rewind(file);

    for (i = 0; i < 11; i++)
        magicNumber[i] = getc(file);
    magicNumber[i] = '\0';

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
    int size;
    fseek( in, inCalc->SIZE_OFFSET, SEEK_SET );
    size = getc( in ) * 0x100 + getc( in );
    getc( in );
    return size;
}

int tiCalcToText(FILE* in, FILE* out) {
    int inFileSize;
    int c;
    unsigned int d;
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

//    printf("Input Calc: %s\n", inCalc->NAME);

    /* Because the TI-84+CSE/CE uses a *few* different symbols than earlier
     * members of the TI-83/84+ family, we should do something differently for
     * it. We *can* reliably detect if a file was created on / is intended for
     * a TI-84+CE, so that's half the battle...
     */
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
            case 0xEF:
                --inFileSize;
                d = getc( in );
                if (d <= (unsigned int)*TIFILEUTILS_TOKENS_83[c]) {
                    if (((char ***)TIFILEUTILS_TOKENS_83)[c][d+1])
                        fprintf( out, "%s", ((char ***)TIFILEUTILS_TOKENS_83)[c][d+1] );
                    else
                        fprintf( out, "[Unknown Token: %.2X%.2X]", c, d);
                } else {
                    fprintf( out, "[Out of range Token: %.4X%.4X]", c, d);
                }
                continue;
    		default:
                if (TIFILEUTILS_TOKENS_83[c])
    		        fprintf( out, "%s", TIFILEUTILS_TOKENS_83[c] );
                else
                    fprintf( out, "[Unknown Token: %.2X]", c );
            }
        }
    } else if (inCalc->FAMILY == TI85) {
    	while( inFileSize-- ) {
        	c = getc( in );
        	if( feof( in ) ) {
        		printf( "END OF FILE REACHED!" );
        		return EXIT_FAILURE;
        	}
            switch( c ) {
            case 0xE1: // Goto token;            zero-terminated string follows
                while (--inFileSize && !(d = getc( in )));
                ++inFileSize,ungetc( d, in );
            case 0xE0: // Lbl token;             zero-terminated string follows
            case 0x2D: // opening quote;         zero-terminated string follows
				fprintf( out, "%s", TIFILEUTILS_TOKENS_85[c] );
            case 0x44: // literal-number token;  zero-terminated string follows
				while (--inFileSize && (c=getc( in ))) {
                    fprintf( out, "%c", c );
                }
                continue;
			case 0x3A:
			case 0x39:
			case 0x38:
			case 0x37:
			case 0x36:
			case 0x35:
			case 0x34:
			case 0x33:
                do {
    				fprintf( out, "%c", getc( in ) );
                    --inFileSize;
                } while (--c != 0x32);
				continue;
            case 0x32: // variable-name tokens
            case 0x3B: // variable-name tokens
            case 0x3C: // variable-name tokens
                --inFileSize;
                d = getc( in );
				do {
                    fprintf( out, "%c", getc( in ) );
                    --inFileSize;
                } while (--d);
                continue;
            case 0x3E: // conversion token
                continue;
            case 0x3D:
            case 0x8E:
                --inFileSize;
                int d = getc( in );
                if (d <= (*TIFILEUTILS_TOKENS_85[c]&0xFF))
                    fprintf( out, "%s", ((char ***)TIFILEUTILS_TOKENS_85)[c][d+1] );
                continue;
    		default:
    			fprintf( out, "%s", TIFILEUTILS_TOKENS_85[c] );
            }
        }
    } else if (inCalc->FAMILY == TI92) {

        fseek( in, 0x49, SEEK_SET );
		int tokenizedFile = fgetc( in );

        if (!tokenizedFile) {
            inFileSize -= 4;
            getc( in ),getc( in ),getc( in ),getc( in ),getc( in ),getc( in ),getc( in ),getc( in );
            while ( inFileSize-- ) {
            	c = getc( in );
            	if( feof( in ) ) {
            		printf( "END OF FILE REACHED!" );
            		return EXIT_FAILURE;
            	}
                fprintf( out, "%c", c );
            }
        } else {
    		printf( "Tokenized TI-92 files not yet implemented\n" );
            return EXIT_FAILURE;
        }
    } else {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
