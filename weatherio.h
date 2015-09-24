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
int header_columns( char * );


/**
This function returns the number of data columns in the file, and in addition, returns the c-strings
for those headers in an array that is passed as the second parameter. You may safely assume that
no header string is greater than 64 characters.
*/
int read_header( char *, char ** );

/**
This functions returns a row of data in an open file and assumes that the file pointer is positioned
at a row passed (past?) the header file. The first parameter is a FILE * type to an open file. The second
parameter is the array of c-strings that are the headers, as returned by the read_header function.
The last parameter is an array of pointers where each pointer points to the appropriate type for
the item read in the column as defined by the header information. Note that you will need to
dynamically allocate memory for this to work. The single return value returns 0 if the row was
read correctly, and otherwise returns an integer that indicates the type of error. You may diecide
on the error codes, but they should be well documented and placed in the header (.h) file.
*/
int read_row( FILE *, char **, void **);


#endif



