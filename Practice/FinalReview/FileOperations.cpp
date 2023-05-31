#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    std::fstream input("input.txt", std::ios::in | std::ios::binary);
    input.seekg(12, std::ios::beg);
    char* buffer = new char[12]{};
    input.read(buffer, 10);
    input.close();
    std::fstream output("output.txt", std::ios::out | std::ios::binary);
    output.write(buffer, 10);
    output.close();
    input.open("input.txt", std::ios::in | std::ios::out | std::ios::binary);
    char cur;
    while (input.get(cur)) {
        input.seekg(-1, std::ios::cur);
        if (std::isalpha(cur)) {
            if (std::isupper(cur)) {
                cur = std::tolower(cur);
            } else {
                cur = std::toupper(cur);
            }
        }
        input.put(cur);
        input.seekg(input.tellg(), std::ios::beg);
    }
    input.close();
    return 0;
}