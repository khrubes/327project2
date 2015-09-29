#include <stdio.h>
#include <stdlib.h>
#include "util.h"
//
//typedef bool ( *isValid )( char* );
//
static char** HEADER_NAMES;
static void** TYPES;
//static isValid* IS_VALID_FUNCTIONS_ARR;

int header_columns( char * fileName) {
    int numCommas = 0;
    FILE *file = fopen(fileName , "r" );

    if ( file != NULL )
    {
        int c;
        while  ( ( c = fgetc( file ) ) != EOF )
        {
            if (c == '\n') { //stop after new line
                break;
            }
            
            if(c == ',') {
                numCommas++;
            }
        }
        fclose( file );
        return numCommas + 1; //always 1 more column than the # of commas
    }
    return -1; //failure
}


int read_header( char * fileName, char ** headerNames) {
    FILE *file = fopen(fileName , "r" );
    int errorValue = 0;

    if ( file != NULL )
    {
        init();
        char* headerNameStr = getInitializedCharArray(64); // FREE ME
        int c;
        int numCharactersInHeaderNameStr = 0;
        int numHeader = 0;
        int numWhiteSpaces = 0;
        while  ( ( c = fgetc( file ) ) != EOF )
        {
            if (c == '\n') { //we are done with the header line
                break;
            }
            
            if(c == ' '){
                numWhiteSpaces++;
            }
            
            if(c == ',') {
                headerNameStr[++numCharactersInHeaderNameStr] = '\0';
                //we have our header string now, copy into smaller array and do checks
                
                //TODO checks
                
                if(checkHeader(stripWhiteSpaces(headerNameStr, numWhiteSpaces, numCharactersInHeaderNameStr), numCharactersInHeaderNameStr-1, numHeader, HEADER_NAMES, TYPES) == -1){
                    errorValue = -1;
                    break;
                }
                
                //empty headerNameStr
                free(headerNameStr);
                headerNameStr = getInitializedCharArray(64);
                numCharactersInHeaderNameStr = 0;
                numHeader++;
                continue;
            }
            
            if(numCharactersInHeaderNameStr == 64){
                errorValue = -1;
                break;
            
            }
            headerNameStr[numCharactersInHeaderNameStr] = c;
            numCharactersInHeaderNameStr++;
            
        }
        free(headerNameStr);
        freeAll();
        fclose( file );
    }else{
        return -1;
    }
    
    return (errorValue==0) ? (sizeof(HEADER_NAMES) / sizeof(char*)) : errorValue; // check this
}


int validate_format( char * fileName){
    int numColumns = header_columns(fileName);
    
    if (invalidNumColumns(numColumns)) {
        return -1; //TODO add error codes for invalid number of columns
    }
    
    HEADER_NAMES = malloc( (numColumns) * sizeof(char *) ); //free me
    TYPES = malloc( (numColumns) * sizeof(void *) );//free me
    numColumns = read_header(fileName, HEADER_NAMES);
    
    if (numColumns == -1) {
        return numColumns; //failure, TODO add error codes for invalid number of columns.
    }
    
	printf("%d\n", numColumns);
    return 0; /* change later */
}


