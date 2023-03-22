#ifndef BT42_COPY_H_
#define BT42_COPY_H_
#include <cstdio>
#include "constants.h"

void print_guide();
std::FILE *copy(std::FILE *fi, std::FILE *fo);
void copy(int argc, char **argv);
void printError(ErrorCode code);

#endif