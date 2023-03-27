#include "Bitmap.hpp"
#include <cstring>

void readBMPHeader(BMPHeader &header, std::ifstream &bmp_file) {
    bmp_file.seekg(0, std::ios::beg);
    bmp_file.read((char *)(&header), sizeof(header));
    return;
}

void readDIB(DIB &dib, std::ifstream &bmp_file) {
    bmp_file.seekg(sizeof(BMPHeader), std::ios::beg);
    bmp_file.read((char *)(&dib), sizeof(dib));
    return;
}

void readPixelArray(PixelArray &main_bmp, const BMPHeader &header, const DIB &dib, std::ifstream &bmp_file) {
    createPixelArray(main_bmp, dib.image_height, dib.image_width, dib.color_depth);
    bmp_file.seekg(header.offset, std::ios::beg);
    char paddings[main_bmp.padding_bytes] = {};
    for (int i = 0; i < main_bmp.pixel_height; ++i) {
        bmp_file.read((char *)(main_bmp.array[i]), main_bmp.number_of_cols);
        bmp_file.read(paddings, main_bmp.padding_bytes);
    }
    return;
}

void cutBMP(PixelArray &main_bmp, PixelArray *&mini_bmp,
            BMPHeader *&headers, DIB *&DIBs, 
            const BMPHeader &header, const DIB &dib, 
            int height_parts, int width_parts, 
            const char *filename) {
    int total = height_parts * width_parts;
    mini_bmp = new PixelArray[total];
    headers = new BMPHeader[total];
    DIBs = new DIB[total];
    std::int32_t len_width = main_bmp.pixel_width / width_parts;
    std::int32_t len_height = main_bmp.pixel_height / height_parts;
    for (int i = 0; i < width_parts; ++i) {
        for (int j = 0; j < height_parts; ++j) {
            std::int32_t left = i * len_width;
            std::int32_t bottom = j * len_height;
            std::int32_t mini_pixel_height = len_height;
            if (j == height_parts - 1) {
                mini_pixel_height = main_bmp.pixel_height - len_height * (height_parts - 1);
            }
            std::int32_t mini_pixel_width = len_width;
            if (i == width_parts - 1) {
                mini_pixel_height = main_bmp.pixel_width - len_width * (width_parts - 1);
            }
            int pos = i * height_parts + j;
            createPixelArray(mini_bmp[pos], mini_pixel_height, mini_pixel_width, dib.color_depth);
            for (int ii = bottom; ii < bottom + mini_pixel_height; ++ii) {
                for (int jj = left; jj < left + mini_pixel_width; ++jj) {
                    mini_bmp[pos].array[ii - bottom][jj - left] = main_bmp.array[ii][jj];
                }
            }
            saveData(header, headers[pos], dib, DIBs[pos], mini_bmp[pos]);
            pushDataIntoBMP(pos, headers[pos], DIBs[pos], mini_bmp[pos], filename);
            // mini_bmp[pos].pixel_size = main_bmp.pixel_size;
            // mini_bmp[pos].pixel_height = mini_pixel_height;
            // mini_bmp[pos].pixel_width = mini_pixel_width;
            // mini_bmp[pos].number_of_cols = mini_pixel_width * mini_bmp[pos].pixel_size;
            // mini_bmp[pos].padding_bytes = (4 - (mini_bmp[pos].number_of_cols % 4)) % 4;
            // mini_bmp[pos].array = new std::uint8_t*[mini_bmp[pos].pixel_height];
            // mini_bmp
        }
    }
}

void pushDataIntoBMP(int pos, const BMPHeader &header, const DIB &dib, const PixelArray &PA, const char *filename) {
    char extension[12] = "_cutted_";
    extension[8] = ((pos / 100) % 10) + '0';
    extension[9] = ((pos / 10) % 10) + '0';
    extension[10] = (pos % 10) + '0';
    char *output = new char[std::strlen(filename) + 12]{};
    std::strncpy(output, filename, std::strlen(filename) - 4);
    std::strcat(output, extension);
    std::strcat(output, ".bmp");
    std::ofstream ofile(output, std::ios::binary);
    ofile.write((char *)(&header), sizeof(header));
    ofile.write((char *)(&dib), sizeof(dib));
    std::uint8_t padding_byte = 0;
    for (int i = 0; i < PA.pixel_height; ++i) {
        ofile.write((char *)PA.array[i], PA.number_of_cols);
        for (int j = 0; j < PA.padding_bytes; ++j) {
            ofile.put(padding_byte);
        }
    }
    return;
}

void createPixelArray(PixelArray &PA, int height, int width, int depth) {
    PA.pixel_height = height; // number of rows
    PA.pixel_size = depth / 8;
    PA.pixel_width = width;
    PA.number_of_cols = width * PA.pixel_size; // number of columns
    PA.padding_bytes = (4 - (PA.number_of_cols % 4)) % 4;
    PA.array = new std::uint8_t*[PA.pixel_height];
    for (int i = 0; i < PA.pixel_height; ++i) {
        PA.array[i] = new std::uint8_t[PA.number_of_cols];
    }
    return;
}

void saveData(const BMPHeader &h_src, BMPHeader &h_dest, const DIB &dib_src, DIB &dib_dest, const PixelArray &PA) {
    std::int32_t pixel_array_size = (PA.number_of_cols + PA.padding_bytes) * PA.pixel_height;
    h_dest = h_src;
    h_dest.file_size = h_dest.offset + pixel_array_size;
    dib_dest = dib_src;
    dib_dest.pixel_array_size = pixel_array_size;
    dib_dest.image_height = PA.pixel_height;
    dib_dest.image_width = PA.pixel_width;
    return;
}