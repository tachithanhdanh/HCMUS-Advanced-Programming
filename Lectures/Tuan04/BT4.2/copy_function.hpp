#ifndef BT42_COPY_HPP_
#define BT42_COPY_HPP_
#include <cstdio>
#include "constants.hpp"

void print_guide();
std::FILE *copy(std::FILE *fi, std::FILE *fo);
void copy(int argc, char **argv);
void printError(ErrorCode code);

#endif