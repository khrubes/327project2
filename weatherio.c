#include <stdio.h>
#include "headerstructs.h"

int header_columns( char * ) {
    int numCommas = 0;
    FILE *file = fopen(fileName , "r" );
    
    if ( file != NULL )
    {
        int c;
        int numCommas = 0;
        while  ( ( c = fgetc( file ) ) != EOF )
        {
            if(c == ',') {
                numCommas++;
            }
        }
        fclose( file );
    }
    return numCommas;
}

int validate_format( char * fileName){
    int numColumns = header_columns(fileName);

    // FILE *fp;
    // char *line = NULL;
    // size_t len = 0;
    // ssize_t read;

    // fp = fopen(fileName, "r");
    // if (fp == NULL)
    //     return 1;

    // while ((read = getline(&line, &len, fp)) != -1) {
    //     printf("Retrieved line of length %zu :\n", read);
    //     printf("%s \n", line);
    // }

    // free(line);
}