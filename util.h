#include <stdbool.h>

bool invalidNumColumns(int numColumns);

char* getInitializedCharArray(int size);

char* stripWhiteSpace(char* string, int numWhiteSpaces, int length);

int checkHeader(char* headerName, int headerNameLength, int index, char** headerNamesArr, void** typesArr);

void assignHeaderArrays(char* headerNameStripped, void* ptrForTypesArr, int index, char** headerNamesArr, void** typesArr);

void init();

void freeAll();


