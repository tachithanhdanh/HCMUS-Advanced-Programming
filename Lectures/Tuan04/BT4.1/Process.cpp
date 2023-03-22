#include "Process.h"
#include <iostream>
#include <cstring>
#include <cctype>

void InsertWordToWordArray(char **&s, int &n, char *&word) {
    int m = n + 1;
    char **s_new = new char*[m];
    // if p_new != nullptr
    if (s_new) {
        if (s != nullptr) {
            for (int i = 0; i < n; ++i) {
                s_new[i] = s[i];
            }
            delete []s;
        }
        s = s_new;
        s[n] = word;
        n = m;
    } else {
        std::cout << "Khong the them duoc ky tu moi vao cuoi chuoi cap phat dong!\n";
    }
    return;
}

void InsertCharToString(char *&s, int &n, const char c) {
    int m = n + 1;
    char *s_new = new char[m];
    // if p_new != nullptr
    if (s_new) {
        if (s != nullptr) {
            std::memcpy(s_new, s, n);
            delete []s;
        }
        s = s_new;
        s[n] = c;
        n = m;
    } else {
        std::cout << "Khong the cap phat them bo nho moi!\n";
    }
    return;
}

void process(const char *inputString, const int inputLen, char **&stringArray, int &arrayLen, int &countWords) {
    int start_pos = -1;
    int word_size;
    for (int i = 0; i < inputLen; ++i) {
        if (std::isalpha(inputString[i])) {
            if (start_pos == -1) {
                start_pos = i;
            }
        } else if (start_pos != -1) {
            ++countWords;
            word_size = i - start_pos;
            char *word = new char[word_size + 1]{};
            std::strncpy(word, inputString + start_pos, word_size);
            InsertWordToWordArray(stringArray, arrayLen, word);
            // delete word;
            // word = nullptr;
            start_pos = -1;
        } 
    }
    return;
}