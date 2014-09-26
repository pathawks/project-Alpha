/**
* This program converts a .8xp file to a .txt file
*
* @author:     Pat Hawks
* Created on:  Sept 06, 2014
* Source File: alpha.c
*/

#define VERSION "1.00"
#define AUTHOR "PHATRINO member of the TI-underground"

#define ERROR_FILES_NOT_SPECIFIED 1
#define CANNOT_OPEN_INPUT_FILE 2

#define print(string) printf( string "\n" );
#define die( string, errornumber ) print( string ); return errornumber;

#include <stdio.h>
#include "tiFileUtils/tiFileUtils.c"

static inline void displayHeader() {
	print();
	print( "        project: ALPHA");
	print( "current version: " VERSION );
	print( "  technology by: " AUTHOR );
	print();

	return;
}

static inline void displayHelp() {
	print( "alpha [inputfile.extension] [outputfile.extension 2] [arguments]" );
	print();
	print( "Input extensions...              Output extensions" );
	print( "83p 8xp 89p 89t 92p 92t          txt" );
	print();
	print( "Valid arguments are" );
	print( "nifty - File complies to Nifty Markup Language v1.0" );
	print( "colon - Starts each new line with :" );
	print();
	print( "Read the file called alpha.txt" );
	print();

	return;
}

int main( int argc, char **argv ) {
	char *inputFile, *outputFile, *format;
	FILE *inputFileHandle, *outputFileHandle;
	CalcType targetCalc;

	displayHeader();
	if ( argc < 3 ) { // Input & Output files not specified
		displayHelp();
		return 1;
	}

	inputFile = argv[1];
	outputFile = argv[2];
	format = argv[3] ? argv[3] : NULL;

	inputFileHandle  = fopen(inputFile, "r");
	if ( inputFileHandle == NULL ) {
		die( "Error opening input file", -1 );
	}

	targetCalc = detectTiInputFileType( inputFileHandle );
	if ( !targetCalc || targetCalc == TINSPIRE ) {
		die( "Input file is not a recognized calculator file type", -3 );
	}

	outputFileHandle = fopen(outputFile, "w");
	if ( outputFileHandle == NULL ) {
		die( "Error opening output file", -2 );
	}

	printf( "Converting  %s to %s\n", inputFile, outputFile );

	convertCalcData( targetCalc, inputFileHandle, outputFileHandle );

	fclose( inputFileHandle );
	fclose( outputFileHandle );
	print( "Finshed!\n" );

	return 0;
}
