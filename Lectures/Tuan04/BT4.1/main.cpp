#include "IOFunctions.h"
#include "Process.h"
#include <iostream>

int main(void) {
    char *inputString = nullptr;
    int inputLen = 0;
    readInputString(inputString, inputLen);
    int countWords = 0;
    char **stringArray = nullptr;
    int arrayLen = 0;
    process(inputString, inputLen, stringArray, arrayLen, countWords);
    printResultString(stringArray, arrayLen, countWords);
    deleteDynamicString(inputString);
    deleteStringArray(stringArray, arrayLen);
    return 0;
}
