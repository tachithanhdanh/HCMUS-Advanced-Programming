#include "copy_function.h"
#include "constants.h"
#include <cstdio>
#include <cstring>

void print_guide() {
    std::fprintf(stdout, "Copies one or more files to another location.\n");
    std::fprintf(stdout, "Cu phap dong lenh chuong trinh COPY. (Su dung dau / de ghi duong dan file)\n");
    std::fprintf(stdout, "Cu phap 1: sao chep dat ten moi:\n");
    std::fprintf(stdout, "\tCOPY <file nguon> <file dich>\n");
    std::fprintf(stdout, "Cu phap 2: sao chep giu ten cu:\n");
    std::fprintf(stdout, "\tCOPY <file nguon> <folder dich>/\n");
    std::fprintf(stdout, "Cu phap 3: noi tap tin:\n");
    std::fprintf(stdout, "\tCOPY <file 1> + <file 2> <file dich>\n");
    std::fprintf(stdout, "Cu phap 4: xem huong dan:\n");
    std::fprintf(stdout, "\tCOPY -?");
    return;
}

std::FILE *copy(std::FILE *fi, std::FILE *fo) {
    // MAX_SIZE + 1 ensure that buffer is null-terminated at the end
    char buffer[MAX_SIZE + 1] = {}; 
    long long int count;
    do {
        count = std::fread(buffer, sizeof(char) * SIZE, COUNT, fi);
        std::fwrite(buffer, sizeof(char) * SIZE, count, fo);
    } while(count == COUNT);
    return fo;
}

void copy(int argc, char **argv) {
    if (argc == 2) {
        if (std::strcmp(argv[1], "-?")) {
            printError(invalidSyntax);
            return;
        } else {
            print_guide();
        }
    } else if (argc == 3) {
        int len1 = static_cast<int>(std::strlen(argv[1]));
        int len2 = static_cast<int>(std::strlen(argv[2]));
        char *dest_path, *src_path = argv[1];
        bool dynamically_allocated = false;
        if (argv[2][len2 - 1] == '/') {
            int pos_slash = -1;
            for (int i = len1 - 1; i >= 0; --i) {
                if (argv[1][i] == '/') {
                    pos_slash = i;
                    break;
                }
            }
            int copy_len1 = len1 - pos_slash + 1;
            dest_path = new char[copy_len1 + len2 + 1]{};
            dynamically_allocated = true;
            std::strcpy(dest_path, argv[2]);
            std::strcat(dest_path, argv[1] + pos_slash + 1);
        } else {
            dest_path = argv[2];
        }
        std::FILE *fi, *fo;
        if ((fi = std::fopen(src_path, "rb")) == nullptr) {
            printError(fileNotFound);
            return;
        }
        fo = std::fopen(dest_path, "wb");
        copy(fi, fo);
        std::fclose(fi);
        std::fclose(fo);
        if (dynamically_allocated) {
            delete []dest_path;
            dest_path = nullptr;
        }
    } else if (argc == 5 && std::strcmp(argv[2], "+") == 0) {
        std::FILE *fi1, *fi2, *fo;
        if ((fi1 = std::fopen(argv[1], "rb")) == nullptr) {
            printError(fileNotFound);
        }
        if ((fi2 = std::fopen(argv[3], "rb")) == nullptr) {
            std::fclose(fi1);
            printError(fileNotFound);
        }
        fo = std::fopen(argv[4], "wb");
        // char buffer[MAX_SIZE];
        // int count;
        fo = copy(fi1, fo);
        copy(fi2, fo);
        std::fclose(fi1);
        std::fclose(fi2);
        std::fclose(fo);
    } else {
        printError(invalidSyntax);
    }
}

void printError(ErrorCode code) {
    if (code == invalidSyntax) {
        fprintf(stdout, "The syntax of the command is incorrect.\n");
    } else if (code == fileNotFound) {
        fprintf(stdout, "The system cannot find the file specified.\n");
    }
    return;
}