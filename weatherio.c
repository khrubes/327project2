#include <stdio.h>
#include "headerstructs.h"
int validate_format( char * fileName){
    	// //call validate_format( char * ) with argv[1]
     //    FILE *file = fopen(fileName , "r" );
        
     //    /* fopen returns 0, the NULL pointer, on failure */
     //    if ( file == NULL )
     //    {
     //        printf( "Could not open file\n" );
     //    }
     //    else
     //    {
     //        int x;
     //        while  ( ( x = fgetc( file ) ) != EOF )
     //        {
     //            printf( "%c", x );
     //        }
     //        printf("\n");
     //        fclose( file );
     //    }

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(fileName, "r");
    if (fp == NULL)
        return 1;

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s \n", line);
    }

    free(line);
}