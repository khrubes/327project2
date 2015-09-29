#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static char** alreadyUsedHeaders;
static char* charPtrForTypesArr;
static int* intPtrForTypesArr;
static double* doublePtrForTypesArr;
static char charForTypesArr;
static int intForTypesArr;
static double doubleForTypesArr;



bool isHeaderAlreadyUsed(char* headerName, int numHeadersAddedSoFar){
    for (int i=0; i<numHeadersAddedSoFar; i++) {
        if (strncmp(*(alreadyUsedHeaders+i), headerName, sizeof(headerName)/sizeof(headerName[i])) == 0) { //check this too
            return true;
        }
    }
    return false;
}

void assignHeaderArrays(char* headerNameStripped, void* ptrForTypesArr, int index, char** headerNamesArr, void** typesArr){
    *(headerNamesArr + index) = headerNameStripped;
    *(typesArr + index) = ptrForTypesArr;
    *(alreadyUsedHeaders + index) = headerNameStripped;
}

int checkHeader(char* headerName, int headerNameLength, int index, char** headerNamesArr, void** typesArr){
    
    if (isHeaderAlreadyUsed(headerName, index)) {
        return -1;
    }
    //TODO isValid functions
    //strip whitespace from headerName
    if (strncmp("IDentification Name", headerName, headerNameLength) == 0) {
        assignHeaderArrays("IDentification Name", (void*)charPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    } else if(strncmp("USAF", headerName, headerNameLength) == 0) {
        assignHeaderArrays("USAF", (void*)charPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    } else if(strncmp("NCDC", headerName, headerNameLength) == 0) {
        assignHeaderArrays("NCDC", (void*)intPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    } else if(strncmp("Date", headerName, headerNameLength) == 0) {
        assignHeaderArrays("Date", (void*)intPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    } else if(strncmp("HrMn", headerName, headerNameLength) == 0) {
        assignHeaderArrays("HrMn", (void*)intPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    } else if(strncmp("I", headerName, headerNameLength) == 0) {
        assignHeaderArrays("I", (void*)charPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    } else if(strncmp("Type", headerName, headerNameLength) == 0) {
        assignHeaderArrays("Type", (void*)charPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }else if(strncmp("QCP", headerName, headerNameLength) == 0) {
        assignHeaderArrays("QCP", (void*)intPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }
    else if(strncmp("Wind Dir", headerName, headerNameLength) == 0) {
        assignHeaderArrays("Wind Dir", (void*)intPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }
    else if(strncmp("Wind Dir Q", headerName, headerNameLength) == 0) {
        assignHeaderArrays("Wind Dir Q", (void*)intPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }
    else if(strncmp("Wind Dir I", headerName, headerNameLength) == 0) {
        assignHeaderArrays("Wind Dir I", (void*)charPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }else if(strncmp("Wind Spd", headerName, headerNameLength) == 0) {
        assignHeaderArrays("Wind Spd", (void*)doublePtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }
    else if(strncmp("Wind Spd Q", headerName, headerNameLength) == 0) {
        assignHeaderArrays("Wind Spd Q", (void*)intPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }
    else if(strncmp("Temp", headerName, headerNameLength) == 0) {
        assignHeaderArrays("Temp", (void*)doublePtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }
    else if(strncmp("Temp Q", headerName, headerNameLength) == 0) {
        assignHeaderArrays("Temp Q", (void*)intPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }
    else if(strncmp("Dewpt", headerName, headerNameLength) == 0) {
        assignHeaderArrays("Dewpt", (void*)doublePtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }
    else if(strncmp("Dewpt Q", headerName, headerNameLength) == 0) {
        assignHeaderArrays("Temp", (void*)intPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }
    else if(strncmp("Slp", headerName, headerNameLength) == 0) {
        assignHeaderArrays("Slp", (void*)doublePtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }
    else if(strncmp("Slp Q", headerName, headerNameLength) == 0) {
        assignHeaderArrays("Slp Q", (void*)intPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }
    else if(strncmp("RHx", headerName, headerNameLength) == 0) {
        assignHeaderArrays("RHx", (void*)intPtrForTypesArr, index, headerNamesArr, typesArr);
        return 0;
    }else {
        return -1; //headerName not a default header
    }
}

void init(){
    if(alreadyUsedHeaders == NULL){
        alreadyUsedHeaders = malloc(20 * sizeof(char*));
    }
    charForTypesArr = 'x';
    intForTypesArr = 1;
    doubleForTypesArr = 1.0;
    
    charPtrForTypesArr = &charForTypesArr;
    intPtrForTypesArr = &intForTypesArr;
    doublePtrForTypesArr = &doubleForTypesArr;
}

void freeAll(){
    //free everything malloced in this class
    free(alreadyUsedHeaders);
}

bool invalidNumColumns(int numColumns){
    return numColumns == -1 || numColumns > 20;
}

char* getInitializedCharArray(int size){
    char* arr = malloc(size * sizeof(char));
    for (int i =0; i < size; i++) {
        *(arr + i)= 0;
    }
    return arr;
}

char* stripWhiteSpace(char* string, int numWhiteSpaces, int length){
    char* newString = malloc((length-numWhiteSpaces) * sizeof(char));
    int indexOfNewString
    for (int i=0; i<length; i++) {
        if(*(string+i) != ' '){
            newString
        }
    }
}
