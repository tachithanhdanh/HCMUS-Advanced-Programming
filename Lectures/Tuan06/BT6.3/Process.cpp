#include "Process.hpp"
#include <iostream>

// https://stackoverflow.com/a/7537829
void generate_permutations(char *s, int k, int n) {
    if (k == n) {
        std::cout << s << '\n';
        return;
    }
    for (int i = k; i < n; ++i) {
        // co dinh s[k]
        swap(s[k], s[i]); 

        // goi de quy de sinh tiep hoan vi
        generate_permutations(s, k + 1, n); 

        // tra lai trang thai ban dau de tiep tuc duyet tuc (buoc backtrack)
        swap(s[k], s[i]);
    }
    return;
}


// https://stackoverflow.com/a/12992511
void generate_combinations(char *src, char *dest, int offset, int k, int pos, int n, bool flag) {
    if (k == 0) {
        if (flag) {
            // std::cout << pos << '\n';
            dest[pos] = '\0';
            generate_permutations(dest, 0, pos);
        }
        else {
            std::cout << dest << '\n';
        }
        return;
    }
    for (int i = offset; i < n - k + 1; ++i) {
        dest[pos] = src[i];
        generate_combinations(src, dest, i + 1, k - 1, pos + 1, n, flag);
        dest[pos] = '\0';
    }
    return;
}

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
    return;
}

void sort(char *s, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (s[i] > s[j]) {
                swap(s[i], s[j]);
            }
        }
    }
    return;
}

void generate_permutations_of_size_k(char *src, char *dest, int k, int n) {
    generate_combinations(src, dest, 0, k, 0, n, true);
    return;
}