#include "Bitmap.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char **argv) {
    BMPHeader header;
    DIB dib;
    PixelArray main_bmp;
    PixelArray *mini_bmp;
    BMPHeader *headers;
    DIB *DIBs;
    int height_parts = 1;
    int width_parts = 1;
    char *filename;
    if (argc == 6) {
        std::ifstream bmp_file(argv[1], std::ios::binary);
        readBMPHeader(header, bmp_file);
        readDIB(dib, bmp_file);
        readPixelArray(main_bmp, header, dib, bmp_file);
        height_parts = std::atoi(argv[3]);
        width_parts = std::atoi(argv[5]);
        filename = argv[1];
        cutBMP(main_bmp, mini_bmp, headers, DIBs, header, dib, height_parts, width_parts, filename);
    }
    return 0;
}