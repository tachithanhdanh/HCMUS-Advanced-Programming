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
    if (argc < 2) return -1;
    if (argc == 6) {
        height_parts = std::atoi(argv[3]);
        width_parts = std::atoi(argv[5]);
    } else if(argc == 4) {
        if (argv[2][1] == 'h') {
            height_parts = std::atoi(argv[3]);
        } else {
            width_parts = std::atoi(argv[3]);
        }
    }
    filename = argv[1];
    std::ifstream bmp_file(filename, std::ios::binary);
    readBMPHeader(header, bmp_file);
    readDIB(dib, bmp_file);
    readPixelArray(main_bmp, header, dib, bmp_file);
    cutBMP(main_bmp, mini_bmp, headers, DIBs, header, dib, height_parts, width_parts, filename);
    freeDynamicallyAllocatedMemory(headers, DIBs, mini_bmp, main_bmp, height_parts, width_parts);
    return 0;
}