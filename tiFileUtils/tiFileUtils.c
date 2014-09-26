/**
* @author:     Pat Hawks
* Created on:  Sept 06, 2014
* Source File: tiFileUtils.c
*/

#include <stdio.h>
#include <string.h>

#define setTiToken(x, value) tiTokenList[x] = value

#define TI73   0x12 // 0001 0010
#define TI80      2
#define TI81      1
#define TI82   0x10 // 0001 0000
#define TI83   0x11 // 0001 0001
#define TI83P  0x15 // 0001 0101
#define TI84P  0x1D // 0001 1101
#define TI84C  0x3D // 0011 1101
#define TI85      4 // 0000 0100
#define TI86      5 // 0000 0101
#define TI89      8 // 0000 1000
#define TI92   0x0C // 0000 1100
#define TI92P  0x0D // 0000 1101
#define TIV200 0x0E // 0000 1110

#define TINSPIRE 0xFF

typedef int CalcType;

int setTiTokens( char *tiTokenList[256], int targetCalc, int format ) {

	switch(targetCalc) {
		case TI89:
		case TI92:
		case TI92P:
			#include "token92.c"
		case TI85:
		case TI86:
			#include "token85.c"
			break;
		default:
			#include "token83.c"
	}

	return 0;
}

static char getNextByte( FILE *inputFileHandle, int *size) {
	char c = fgetc( inputFileHandle );
	if( feof( inputFileHandle ) ) {
		printf( "END OF FILE REACHED!" );
	}
	*size = *size - 1;
	return c;
}

CalcType detectTiInputFileType( FILE *inputFileHandle ) {
	const int numberOfBytesInMagicNumber = 11;
	int i = 0;
	char calcMagicNumber[11];
	CalcType targetCalc = 0;

	fseek( inputFileHandle, 0, SEEK_SET );

	while( i < numberOfBytesInMagicNumber ){
		calcMagicNumber[i++] =
			fgetc(inputFileHandle);
	}

	targetCalc = 0;

	switch( calcMagicNumber[5] ) {
		case '5':
			targetCalc = TI85;
			break;
		case '6':
			targetCalc = TI86;
			break;
		case '9':
			targetCalc = TI89;
			break;
		case '2':
			if (calcMagicNumber[4]=='8') {
				targetCalc = TI82;
			} else {
				targetCalc = calcMagicNumber[6]=='*' ? TI92 : TI92P;
			}
			break;
		case '3':
			switch( calcMagicNumber[4] ) {
				case '8':
					if ( calcMagicNumber[6] == '*' ) {
							targetCalc = TI83;
						} else {
							targetCalc = calcMagicNumber[10] ? TI83P : TI84C;
					}
					break;
				case '7':
					targetCalc = TI73;
					break;
			}
			break;
		case 'p':
			if ( calcMagicNumber[0] == '*' && calcMagicNumber[1] == 'T' && calcMagicNumber[2] == 'I' && calcMagicNumber[3] == 'M' && calcMagicNumber[4] == 'L' && calcMagicNumber[5] == 'P' && calcMagicNumber[6] == '0' && calcMagicNumber[9] == '0' ) {
				switch ( calcMagicNumber[7] ) {
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
						targetCalc = TINSPIRE;
						break;
				}
			}
	}

	if ( targetCalc != TINSPIRE && ( calcMagicNumber[0] != '*' || calcMagicNumber[1] != '*' || calcMagicNumber[2] != 'T' || calcMagicNumber[3] != 'I' ) ) {
		targetCalc = 0;
	}

	return targetCalc;
}

static inline int convertCalcData83( CalcType targetCalc, FILE *inputFileHandle, FILE *outputFileHandle ) {
	register unsigned char c;
	int size;
	int sizeOffset = 0x47;
	int tokenizedFile = 1;
	const char *tiTokenList[256];

	setTiTokens( (char **)tiTokenList, targetCalc, 0 );

	fseek( inputFileHandle, sizeOffset, SEEK_SET );
	size = fgetc( inputFileHandle ) * 256 + fgetc( inputFileHandle );

	fgetc( inputFileHandle );

	if ( tokenizedFile ) {
		while( size-- ) {
			c = fgetc( inputFileHandle );
			if( feof( inputFileHandle ) ) {
				printf( "END OF FILE REACHED!" );
				break;
			}
			switch(c){
				case 0x5C: // Matrix
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "[%c]", c + 0x41 );
					break;
				case 0x5D: // List
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "L%c", (c+1)%10 + 0x30 );
					break;
				case 0x5E: // Could be one of three things...
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "?" );
					break;
				case 0x60: // Pic
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "Pic%c", (c+1)%10 + 0x30 );
					break;
				case 0x61: // Pic
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "GDB%c", (c+1)%10 + 0x30 );
					break;
				case 0x62: // More complicated than this...
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "z" );
					break;
				case 0x63: // More complicated than this...
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "?" );
					break;
				case 0xAA: // More complicated than this...
					c = getNextByte( inputFileHandle, &size);
					fprintf( outputFileHandle, "Str%c", (c+1)%10 + 0x30 );
					break;
				default:
					if (tiTokenList[(unsigned char)c])
						fprintf( outputFileHandle, "%s", tiTokenList[c] );
			}
		}
	} else {
		while( size-- ) {
			c = fgetc( inputFileHandle );
			if( feof( inputFileHandle ) ) {
				printf( "END OF FILE REACHED!" );
				break;
			}
			fprintf( outputFileHandle, "%c", c );
		}
	}
	fprintf( outputFileHandle, "\n" );

	return 0;
}

static inline int convertCalcData85( CalcType targetCalc, FILE *inputFileHandle, FILE *outputFileHandle ) {
	register unsigned char c;
	int size;
	int sizeOffset = 0x39;
	const char *tiTokenList[256];

	fseek( inputFileHandle, sizeOffset, SEEK_SET );
	c = fgetc( inputFileHandle );
	while( c != fgetc( inputFileHandle ) );
	size = fgetc( inputFileHandle ) * 256 + fgetc( inputFileHandle );
	fgetc( inputFileHandle );

	setTiTokens( (char **)tiTokenList, targetCalc, 0 );

	while( size-- ) {
		c = fgetc( inputFileHandle );
		if( feof( inputFileHandle ) ) {
			printf( "END OF FILE REACHED!" );
			break;
		}
		switch(c) {
			case 0x44: // literal-number token
				c = getNextByte( inputFileHandle, &size);
				while( c ) {
					fprintf( outputFileHandle, "%c", c );
					c = fgetc( inputFileHandle );
					size--;
				}
				break;
			case 0x2D:
				fprintf( outputFileHandle, "\"" );
				c = getNextByte( inputFileHandle, &size);
				while( c ) {
					fprintf( outputFileHandle, "%c", c );
					c = getNextByte( inputFileHandle, &size);
				}
				fprintf( outputFileHandle, "\"" );
				break;
			case 0x3A: // { These are all intended to fall through!
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x39:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x38:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x37:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x36:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x35:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x34:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
			case 0x33:
				fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
				break; // }
			case 0x32:
			case 0x3B:
			case 0x3C:
				c = getNextByte( inputFileHandle, &size);
				while( c ) {
					fprintf( outputFileHandle, "%c", getNextByte( inputFileHandle, &size) );
					c--;
				}
				break;
			case 0x3D:
			case 0x8E:
				getNextByte( inputFileHandle, &size);
				break;
			case 0xE0:
				fprintf( outputFileHandle, "Lbl ");
				c = getNextByte( inputFileHandle, &size);
				while( !c ) {
					c = getNextByte( inputFileHandle, &size);
				}
				while( c ) {
					fprintf( outputFileHandle, "%c", c );
					c = getNextByte( inputFileHandle, &size);
				}
				break;
			case 0xE1:
				fprintf( outputFileHandle, "Goto ");
				c = getNextByte( inputFileHandle, &size);
				while( !c ) {
					c = getNextByte( inputFileHandle, &size);
				}
				while( c ) {
					fprintf( outputFileHandle, "%c", c );
					c = getNextByte( inputFileHandle, &size);
				}
				break;
			default:
				if (tiTokenList[(unsigned char)c]) {
					fprintf( outputFileHandle, "%s", tiTokenList[c] );
				}
		}
	}
	fprintf( outputFileHandle, "\n" );

	return 0;
}

static inline int convertCalcData92( CalcType targetCalc, FILE *inputFileHandle, FILE *outputFileHandle ) {
	register unsigned char c;
	int size;
	// int sizeOffset = 0x56;
	int sizeOffset = 0x56;
	int tokenizedFile;
	const char *tiTokenList[256];

	fseek( inputFileHandle, 0x49, SEEK_SET );
		tokenizedFile = fgetc( inputFileHandle ) != 0;

	fseek( inputFileHandle, sizeOffset, SEEK_SET );
	size = 256 * fgetc( inputFileHandle ) + fgetc( inputFileHandle ) - 10;

	if ( tokenizedFile ) {
		setTiTokens( (char **)tiTokenList, targetCalc, 0 );
		while( size-- ) {
			c = fgetc( inputFileHandle );
			if( feof( inputFileHandle ) ) {
				printf( "END OF FILE REACHED!" );
				break;
			}
			if (tiTokenList[(unsigned char)c])
				fprintf( outputFileHandle, "%s", tiTokenList[c] );
		}
	} else {
		while( size-- ) {
			c = fgetc( inputFileHandle );
			if( feof( inputFileHandle ) ) {
				printf( "END OF FILE REACHED!" );
				break;
			}
			fprintf( outputFileHandle, "%c", c );
		}
	}
	fprintf( outputFileHandle, "\n" );

	return 0;
}

int convertCalcData( CalcType targetCalc, FILE *inputFileHandle, FILE *outputFileHandle ) {
	int sucessCode;

	switch(targetCalc) {
		case TI89:
		case TI92:
		case TI92P:
			sucessCode = convertCalcData92( targetCalc, inputFileHandle, outputFileHandle );
			break;
		case TI85:
		case TI86:
			sucessCode = convertCalcData85( targetCalc, inputFileHandle, outputFileHandle );
			break;
		case TINSPIRE:
			sucessCode = 1;
			break;
		default:
			sucessCode = convertCalcData83( targetCalc, inputFileHandle, outputFileHandle );
			break;
	}

	return sucessCode;
}
