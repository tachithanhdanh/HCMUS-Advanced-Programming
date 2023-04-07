#include "Process.hpp"
#include <cstring>
#include <iostream>

constexpr int MAX = (1 << 9);

int main(void) {
    char s[MAX]{};
    int len;
    std::cout << "Nhap chuoi s = ";
    std::cin.getline(s, MAX);
    len = static_cast<int>(std::strlen(s));

    int K;
    std::cout << "Nhap K = ";
    std::cin >> K;

    sort(s, len);

    std::cout << "\nTat ca cac hoan vi cua chuoi s: \n";
    generate_permutations(s, 0, len);

    char *dest = new char[K + 1]{};
    std::cout << "\nTat ca cac chinh hop chap " << K << " cua chuoi s: \n";
    generate_permutations_of_size_k(s, dest, K, len);

    std::cout << "\nTat cac cac to hop chap " << K << " cua chuoi s: \n";
    generate_combinations(s, dest, 0, K, 0, len);

    delete []dest;
    dest = nullptr;
    return 0;
}