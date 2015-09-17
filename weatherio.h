#ifndef WEATHER_IO
#define WEATHER_IO

/**
This function returns 0 if the file name specified parameter contains a valid formatted weather
data file. The function returns the first line number that an error occurred. At a minimum you
must validate the following:
Not enough data in row
Invalid data format
Invalid file or file name
*/
int validate_format( char * );


/**
This function returns the number of data columns (header columns) in the file name specified in
the first parameter.
*/
int header_columns( char *);


/**
This function returns the number of data columns in the file, and in addition, returns the c-strings
for those headers in an array that is passed as the second parameter. You may safely assume that
no header string is greater than 64 characters.
*/
int read_header( char *, char ** );



#endif



