#ifndef BT42_CONSTANTS_H_
#define BT42_CONSTANTS_H_

constexpr int SIZE = 1 << 0;
constexpr int MAX_SIZE = 1 << 6;
constexpr int COUNT = MAX_SIZE / SIZE;
enum ErrorCode {invalidSyntax, fileNotFound};

#endif