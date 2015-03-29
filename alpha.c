/**
 * This program converts a .8xp file to a .txt file
 *
 * @author:     Pat Hawks
 * Created on:  Sept 06, 2014
 * Source File: alpha.c
 */

#define VERSION "1.00"
#define AUTHOR "PHATRINO member of the TI-underground"

#include <stdio.h>
#include <stdlib.h>
#include "tifileutils/tifileutils.h"

void displayHeader() {
	printf(
        "\n"
        "        project: ALPHA\n"
        "current version: %s\n"
        "  technology by: %s\n\n"
	, VERSION, AUTHOR);

	return;
}

void displayHelp( char *programName ) {
	printf(
        "%s [inputfile.extension] [outputfile.extension 2] [arguments]\n"
        "\n"
        "Input extensions...              Output extensions\n"
        "83p 8xp 89p 89t 92p 92t          txt\n"
        "\n"
        "Valid arguments are\n"
        "nifty - File complies to Nifty Markup Language v1.0\n"
        "colon - Starts each new line with :\n"
        "\n"
        "Read the file called alpha.txt\n",
        programName
	);

	return;
}

int main( int argc, char** argv ) {
    const char*  inFileName = argv[1];
    const char* outFileName = argv[2];
    FILE* inFile;
	FILE* outFile;

	displayHeader();

    if (argc != 3) {
        displayHelp( *argv );
        return EXIT_FAILURE;
    }

    if( !(inFile = fopen(inFileName, "r"))){
		perror("Error opening input file");
		return EXIT_FAILURE;
	}
	if ( !(outFile = fopen(outFileName, "r"))) {
//		perror("Error opening output file");
//		return EXIT_FAILURE;
	}

	const CalcType* TI = tiDetectFileType( inFile );

	if (!TI) {
		printf("%s\n", "Input file is not a recognized calculator file type");
		return EXIT_FAILURE;
	}

	fclose(inFile);
	fclose(outFile);
	printf("%s", "Finshed!\n");

	return EXIT_SUCCESS;
}
