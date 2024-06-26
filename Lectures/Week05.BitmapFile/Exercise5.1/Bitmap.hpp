#ifndef BT51_BITMAP_HPP_
#define BT51_BITMAP_HPP_
#include <cstdint>
#include <fstream>

#pragma pack(push, 1)

struct BMPHeader {
    std::int8_t signature[2];
    std::int32_t file_size;
    std::int32_t reserved_data;
    std::int32_t offset;
};

struct DIB {
    std::int32_t DIB_size;
    std::int32_t image_width;
    std::int32_t image_height;
    std::int16_t color_plane;
    std::int16_t color_depth;
    std::int32_t compression_algorithm;
    std::int32_t pixel_array_size;
    std::int32_t horizontal_resolution;
    std::int32_t vertical_resolution;
    std::int32_t number_of_colors;
    std::int32_t number_of_important_colors;
};

#pragma pack(pop)

struct PixelArray {
    std::int32_t pixel_size;
    std::int32_t pixel_height; // number of rows
    std::int32_t pixel_width; 
    std::int32_t number_of_cols; // number of columns
    std::int32_t padding_bytes;
    std::uint8_t **array;
};

struct Coordinates {
    std::int32_t len_width;
    std::int32_t len_height;
    std::int32_t left;
    std::int32_t bottom;
    std::int32_t top;
    std::int32_t right;
    std::int32_t mini_pixel_width;
    std::int32_t mini_pixel_height;
    int pos;
};

void readBMPHeader(BMPHeader &header, std::ifstream &bmp_file);
void readDIB(DIB &dib, std::ifstream &bmp_file);
void readPixelArray(PixelArray &main_bmp, const BMPHeader &header, const DIB &dib, std::ifstream &bmp_file);
void cutBMP(PixelArray &main_bmp, PixelArray *&mini_bmp, BMPHeader *&headers, DIB *&DIBs, const BMPHeader &header, const DIB &dib, int height_parts, int width_parts, const char *filename);
void createPixelArray(PixelArray &PA, int height, int width, int depth);
void saveData(const BMPHeader &h_src, BMPHeader &h_dest, const DIB &dib_src, DIB &dib_dest, const PixelArray &PA);
void pushDataIntoBMP(int pos, BMPHeader &header, DIB &dib, const PixelArray &PA, const char *filename);
int min(int, int);
void printBMPHeaderInfo(const BMPHeader &header);
void printDIBInfo(const DIB &dib);
void freeDynamicallyAllocatedMemory(BMPHeader *&headers, DIB *&DIBs, PixelArray *&PAs, PixelArray &main_bmp, int height_parts, int width_parts);
void deletePixelArray(PixelArray &PArray);
void calculateCoordinates(Coordinates &C, int i, int j, PixelArray &main_bmp, int height_parts, int width_parts);

#endif