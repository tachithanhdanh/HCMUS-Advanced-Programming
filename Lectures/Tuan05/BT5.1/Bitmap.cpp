#include "Bitmap.hpp"
#include <cstring>
#include <iostream>

int min(int a, int b) {
    return (a < b ? a : b);
}

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
    char paddings[5] = {};
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
    // printBMPHeaderInfo(header);
    // printDIBInfo(dib);
    int total = height_parts * width_parts;
    // using namespace std;
    // cout << total << endl;
    mini_bmp = new PixelArray[total];
    headers = new BMPHeader[total];
    DIBs = new DIB[total];
    std::int32_t len_width = main_bmp.pixel_width / width_parts;
    std::int32_t len_height = main_bmp.pixel_height / height_parts;
    for (int i = 0; i < height_parts; ++i) {
        for (int j = 0; j < width_parts; ++j) {
            std::int32_t left = j * len_width * main_bmp.pixel_size;
            std::int32_t bottom = i * len_height;
            std::int32_t mini_pixel_width = len_width;
            if (j == width_parts - 1) {
                mini_pixel_width = main_bmp.pixel_width - len_width * (width_parts - 1);
            }
            std::int32_t mini_pixel_height = len_height;
            if (i == height_parts - 1) {
                mini_pixel_height = main_bmp.pixel_height - len_height * (height_parts - 1);
            }
            int pos = i * width_parts + j;
            createPixelArray(mini_bmp[pos], mini_pixel_height, mini_pixel_width, dib.color_depth);
            int top = min(bottom + mini_pixel_height, main_bmp.pixel_height);
            int right = min(left + mini_pixel_width * main_bmp.pixel_size, main_bmp.number_of_cols);
            for (int ii = bottom; ii < top; ++ii) {
                for (int jj = left; jj < right; ++jj) {
                    //left + mini_pixel_widthcout << ii - bottom << " " << jj - left << endl;
                    mini_bmp[pos].array[ii - bottom][jj - left] = main_bmp.array[ii][jj];
                }
            }
            saveData(header, headers[pos], dib, DIBs[pos], mini_bmp[pos]);
            pushDataIntoBMP(pos, headers[pos], DIBs[pos], mini_bmp[pos], filename);
        }
    }
}

void pushDataIntoBMP(int pos, BMPHeader &header, DIB &dib, const PixelArray &PA, const char *filename) {
    char extension[9] = "_cut_";
    extension[5] = char((pos / 100) % 10) + '0';
    extension[6] = char((pos / 10) % 10) + '0';
    extension[7] = char(pos % 10) + '0';
    char *output = new char[std::strlen(filename) + std::strlen(extension)]{};
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
    ofile.close();
    delete []output;
    output = nullptr;
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
    h_dest.offset = 54;
    h_dest.file_size = h_dest.offset + pixel_array_size;
    dib_dest = dib_src;
    dib_dest.DIB_size = 40;
    dib_dest.pixel_array_size = pixel_array_size;
    dib_dest.image_height = PA.pixel_height;
    dib_dest.image_width = PA.pixel_width;
    return;
}

void freeDynamicallyAllocatedMemory(BMPHeader *&headers, DIB *&DIBs, PixelArray *&PAs, PixelArray &main_bmp, int height_parts, int width_parts) {
    int total = height_parts * width_parts;
    delete []headers;
    headers = nullptr;
    delete []DIBs;
    DIBs = nullptr;
    for (int i = 0; i < total; ++i) {
        deletePixelArray(PAs[i]);
    }
    deletePixelArray(main_bmp);
    delete []PAs;
    PAs = nullptr;
    return;
}

void deletePixelArray(PixelArray &PArray) {
    for (int j = 0; j < PArray.pixel_height; ++j) {
        delete []PArray.array[j];
        PArray.array[j] = nullptr;
    }
    delete []PArray.array;
    PArray.array = nullptr;
    return;
}

void printBMPHeaderInfo(const BMPHeader &header) {
    std::cout << "signature: " << header.signature[0] << header.signature[1] << '\n';
    std::cout << "file size: " << header.file_size << '\n';
    std::cout << "offset: " << header.offset << '\n';
}

void printDIBInfo(const DIB &dib) {
    using std::cout;
    cout << "DIB size: " << dib.DIB_size << '\n';
    cout << "Image width: " << dib.image_width << '\n';
    cout << "Image height: " << dib.image_height << '\n';
    cout << "color depth: " << dib.color_depth << '\n';
    cout << "Compression Algorithm: " << dib.compression_algorithm << '\n';
}