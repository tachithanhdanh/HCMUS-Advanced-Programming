#include <fstream>
#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>

struct Fraction {
    int numerator;
    int denominator;
};

void ReplaceChar();
void copyFile();
void exercise_3();
void readFractionsFromFile(Fraction *&fracs, int &n);
void printFractionsToFile(const Fraction *fracs, const int &n);
void sortFractionArray(Fraction *&fracs, const int &n);
bool greater(const Fraction &frac1, const Fraction &frac2);
void InsertAFractionToArray(Fraction *&fracs, int &n, Fraction *frac);
void normalize(Fraction *frac);
void frequencyOfCharacters();

int main(void) {
    ReplaceChar(); // bai 1
    copyFile(); // bai 2
    exercise_3(); // bai 3
    frequencyOfCharacters(); // bai 4
    return 0;
}

void ReplaceChar() {
    std::cout << "Day la bai 1.\n";
    std::cout << "Da em chao thay, day la ham ReplaceChar"
              << " co tac dung thay the mot ky tu nao do"
              << " bang mot ky tu moi trong van ban.\n";
    std::cout << "File van ban duoc su dung o day la bai1.txt\n";
    std::cout << "Moi thay nhap ky tu cu can duoc thay the: ";
    char oldChar;
    std::cin >> oldChar;
    std::cout << "Moi thay nhap ky tu moi sau khi da thay the: ";
    char newChar;
    std::cin >> newChar;
    // mo file vua doc vua ghi
    // https://stackoverflow.com/questions/12252075/ifstream-tellg-not-returning-the-correct-position
    // https://stackoverflow.com/questions/2641639/fstreams-tellg-seekg-returning-higher-value-than-expected
    std::fstream iofile("bai1.txt", std::ios::in | std::ios::out | std::ios::binary); 

    char chChar = '\0';
    while (iofile.get(chChar)) {
        if (chChar == oldChar) {
            // lui 1 ky tu ve truoc de quay tro ve ky tu == oldChar
            iofile.seekg(-1, std::ios::cur);

            iofile.put(newChar);

            iofile.seekg(iofile.tellg(), std::ios::beg);
        }
    }
    iofile.close();
    std::cout << "Da hoan thanh xong bai 1."
              << " Thay co the mo file bai1.txt de kiem tra ket qua.\n\n";
    return;
}

void copyFile() {
    std::cout << "Day la bai 2.\n";
    std::cout << "Da em chao thay, day la ham copyFile"
              << " co tac dung sao chep hai tap tin.\n";
    std::cout << "O day ta sao chep noi dung tu file bai2in.txt sang file bai2out.txt\n";
    std::ifstream ifile("bai2in.txt");
    std::ofstream ofile("bai2out.txt");

    char data;
    while (ifile) {
        ifile.get(data);
        ofile.put(data);
    }
    // nho dong file lai
    ifile.close();
    ofile.close();
    std::cout << "Da hoan thanh xong bai 2."
              << " Thay co the mo file bai2out.txt de kiem tra.\n\n";
    return;
}


void exercise_3() {
    std::cout << "Day la bai 3.\n";
    Fraction *fracs = nullptr;
    int n = 0;
    readFractionsFromFile(fracs, n);
    sortFractionArray(fracs, n);
    printFractionsToFile(fracs, n);
    if (fracs) {
        delete []fracs;
        fracs = nullptr;
    }
    std::cout << "Da hoan thanh xong bai 3."
              << " Thay co the mo file bai3out.txt de kiem tra.\n\n";
    return;
}

void sortFractionArray(Fraction *&fracs, const int &n) {
    std::cout << "Day la ham sortFractionArray.\n"
              << "Ham nay co sap xep cac phan so trong mang"
              << " theo thu tu tang dan.\n";
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (greater(fracs[i], fracs[j])) {
               std::swap(fracs[i], fracs[j]);
            }
        }
    }
    return;
}

// return true if frac1 > frac2, false otherwise.
bool greater(const Fraction &frac1, const Fraction &frac2) {
    int numerator1 = frac1.numerator * frac2.denominator;
    int numerator2 = frac2.numerator * frac1.denominator;
    return numerator1 > numerator2;
}

void readFractionsFromFile(Fraction *&fracs, int &n) {
    std::cout << "Day la ham readFractionsFromFile.\n"
              << "Ham nay co tac dung doc cac phan so tu file bai3in.txt"
              << " vao trong mang cap phat dong trong RAM.\n";
    std::ifstream ifile("bai3in.txt");
    Fraction *frac = new Fraction;
    while (ifile >> frac->numerator >> frac->denominator) {
        normalize(frac);
        InsertAFractionToArray(fracs, n, frac);
    }
    delete frac;
    frac = nullptr;
    ifile.close();
    return;
}

void normalize(Fraction *frac) {
    int sign;
    if (frac->numerator * frac->denominator < 0) {
        sign = -1;
    } else {
        sign = 1;
    }
    frac->denominator = std::abs(frac->denominator);
    frac->numerator = sign * std::abs(frac->numerator);
    return;
}

void printFractionsToFile(const Fraction *fracs, const int &n) {
    std::cout << "Day la ham printFractionsToFile.\n"
              << "Ham nay co tac dung ghi cac phan so sau khi da duoc sap xep "
              << " vao file bai3out.txt\n";
    std::ofstream ofile("bai3out.txt");
    for (int i = 0; i < n; ++i) {
        ofile << fracs[i].numerator << ' ' << fracs[i].denominator << '\n';
    }
    ofile.close();
    return;
}

void InsertAFractionToArray(Fraction *&fracs, int &n, Fraction *frac) {
    int m = n + 1;
    Fraction *fracs_new = new Fraction[m];
    // if p_new != nullptr
    if (fracs_new) {
        if (fracs != nullptr) {
            std::copy(fracs, fracs + n, fracs_new);
            delete []fracs;
            fracs = nullptr;
        }
        std::swap(fracs, fracs_new);
        fracs[n].numerator = frac->numerator;
        fracs[n].denominator = frac->denominator;
        std::swap(n, m);
    } else {
        std::cout << "Khong the them duoc phan tu moi vao cuoi mang!\n";
    }
    return;
}

void frequencyOfCharacters() {
    std::cout << "Day la bai 4.\n"
              << "Day la ham frequencyOfCharacters"
              << " co tac dung thong ke so luan xuat hien"
              << " cua cac ky tu tu tap tin van ban bai4in.txt"
              << " va sau do ghi lai so lan xuat hien ra tap tin bai4out.txt\n";
    std::ifstream ifile("bai4in.txt");
    int count[26] = {};
    char ch;
    while (ifile.get(ch)) {
        if (std::isalpha(ch)) {
            ch = static_cast<char>(std::tolower(ch));
            ++count[ch - 'a'];
        }
    }
    ifile.close();
    std::ofstream ofile("bai4out.txt");
    for (int i = 0; i < 26; ++i) {
        if (count[i]) {
            ofile << static_cast<char>(i + 'a') << ": " << count[i] << '\n';
        }
    }
    ofile.close();
    std::cout << "Da hoan thanh xong bai 4."
              << " Thay co the mo file bai4out.txt de kiem tra.\n\n";
    return;
}