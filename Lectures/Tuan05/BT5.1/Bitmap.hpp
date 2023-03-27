#ifndef BT51_BITMAP_HPP_
#define BT51_BITMAP_HPP_
#include <cstdint>
#include <fstream>

#pragma pack(push, 2)

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

struct PixelArray {
    std::int32_t pixel_size;
    std::int32_t pixel_height; // number of rows
    std::int32_t pixel_width; // number of columns
    std::int32_t number_of_cols;
    std::size_t padding_bytes;
    std::uint8_t **array;
};

#pragma pack(pop)

void readBMPHeader(BMPHeader &header, std::ifstream &bmp_file);
void readDIB(DIB &dib, std::ifstream &bmp_file);
void readPixelArray(PixelArray &main_bmp, const BMPHeader &header, const DIB &dib, std::ifstream &bmp_file);
void cutBMP(PixelArray &main_bmp, PixelArray *&mini_bmp, BMPHeader *&headers, DIB *&DIBs, const BMPHeader &header, const DIB &dib, int height_parts, int width_parts, const char *filename);
void createPixelArray(PixelArray &PA, int height, int width, int depth);
void saveData(const BMPHeader &h_src, BMPHeader &h_dest, const DIB &dib_src, DIB &dib_dest, const PixelArray &PA);
void pushDataIntoBMP(int pos, const BMPHeader &header, const DIB &dib, const PixelArray &PA, const char *filename);

#endif