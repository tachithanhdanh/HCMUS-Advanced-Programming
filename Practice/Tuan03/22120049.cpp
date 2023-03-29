#include <iostream>
#include <limits> // for std::numeric_limits

constexpr int MAX = 300;

int mystrlen(const char *str);
char *mystrncpy(char *dest, const char *source, int count);
char *mystrcpy(char *dest, const char *source);
void CopySubString(char *dest, const char *source, int startPos, int count);
void InsertSubString(char *str, const char *substr, int startPos);
void DeleteSubString(char *source, int startPos, int count);
int FindSubString(char *str, char *substr, int startPos);
bool IsSubString(char *str, char *substr);
int CountMatches(char *str, char *substr);
void solve();
void bai1(char *dest, char *source, int &count);
void bai2(char *dest, char *source);
void bai3(char *source, int &startPos, int &count);
void bai4(char *str, char *substr, int &startPos);
void bai5(char *str, char *substr);
void bai6(char *str, char *substr);
void ignoreLine();

int main(void) {
    solve();
    return 0;
}

void solve() {
    char dest[MAX]{};
    char source[MAX]{};
    char str[MAX]{};
    char substr[MAX]{};
    int count{};
    int startPos{};
    bai1(dest, source, count);
    bai2(dest, source);
    bai3(source, startPos, count);
    bai4(str, substr, startPos);
    bai5(str, substr);
    bai6(str, substr);
    return;
}

// https://stackoverflow.com/questions/1744665/need-help-with-getline


void bai1(char *dest, char *source, int &count) {
    std::cout << "Da em chao thay, day la bai lam cua Ta Chi Thanh Danh - MSSV 22120049.\n";
    std::cout << "Day la ham mystrncpy (StringNCopy).\n";
    std::cout << "Moi thay nhap chuoi nguon: ";
    std::cin.getline(source, MAX);
    std::cout << "Moi thay nhap so luong ky tu: ";
    // ignoreLine();
    std::cin >> count;
    mystrncpy(dest, source, count);
    std::cout << "Chuoi ket qua sau khi duoc su dung ham mystrncpy (StringNCopy): " << dest << '\n';
    return;
}

void bai2(char *dest, char *source) {
    std::cout << "Day la ham mystrcpy (StringCopy).\n";
    std::cout << "Moi thay nhap chuoi nguon: ";
    ignoreLine();
    std::cin.getline(source, MAX);
    // ignoreLine();
    mystrcpy(dest, source);
    std::cout << "Chuoi ket qua sau khi duoc su dung ham mystrcpy (StringCopy): " << dest << '\n';
    return;
}

void bai3(char *source, int &startPos, int &count) {
    std::cout << "Day la ham DeleteSubString.\n";
    std::cout << "Moi thay nhap chuoi nguon: ";
    std::cin.getline(source, MAX);
    // ignoreLine();
    std::cout << "Moi thay nhap vi tri bat dau xoa: ";
    std::cin >> startPos;
    std::cout << "Moi thay nhap so luong ky tu xoa: ";
    std::cin >> count;
    DeleteSubString(source, startPos, count);
    std::cout << "Chuoi ket qua sau khi duoc su dung ham DeleteSubString: " << source << '\n';
    return;
}

void bai4(char *str, char *substr, int &startPos) {
    std::cout << "Day la ham FindSubString.\n";
    std::cout << "Moi thay nhap chuoi cha: ";
    ignoreLine();
    std::cin.getline(str, MAX);
    // ignoreLine();
    std::cout << "Moi thay nhap chuoi con: ";
    std::cin.getline(substr, MAX);
    std::cout << "Moi thay nhap vi tri bat dau tim: ";
    std::cin >> startPos;
    std::cout << "Vi tri xuat hien dau tien cua chuoi con" 
              << " trong chuoi cha tinh tu vi tri bat dau tim: "
              << FindSubString(str, substr, startPos) << '\n';
    return;
}

void bai5(char *str, char *substr) {
    std::cout << "Day la ham IsSubString.\n";
    std::cout << "Moi thay nhap chuoi cha: ";
    ignoreLine();
    std::cin.getline(str, MAX);
    std::cout << "Moi thay nhap chuoi con: ";
    std::cin.getline(substr, MAX);
    std::cout << "Ket qua cua ham IsSubString(char *ChuoiCha, char *ChuoiCon)"
              << " la " << std::boolalpha << IsSubString(str, substr) << '\n';
    return;
}

void bai6(char *str, char *substr) {
    std::cout << "Day la ham CountMatches.\n";
    std::cout << "Moi thay nhap chuoi cha: ";
    std::cin.getline(str, MAX);
    std::cout << "Moi thay nhap chuoi con: ";
    std::cin.getline(substr, MAX);
    std::cout << "Ket qua cua ham CountMatches(char *ChuoiCha, char *ChuoiCon)"
              << " la " << CountMatches(str, substr) << '\n';
    return;
}

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int mystrlen(const char *str) {
    // https://stackoverflow.com/a/1733294
    const char *p = str;
    while (*p) 
        ++p;
    return static_cast<int>(p - str);
}

char *mystrncpy(char *dest, const char *source, int count) {
    // https://stackoverflow.com/questions/14159625/implementation-of-strncpy
    char *_dest = dest;
    while (count-- && (*dest++ = *source++));
    // dest[count] = '\0'; // null-terminated the string
    return _dest;
}

char *mystrcpy(char *dest, const char *source) {
    // https://stackoverflow.com/questions/14476627/strcpy-implementation-in-c
    char *p = dest;
    while ((*p++ = *source++));
    return dest;
}

void CopySubString(char *dest, const char *source, int startPos, int count) {
    mystrncpy(dest, source + startPos, count);
    dest[count] = '\0';
}

void InsertSubString(char *str, const char *substr, int startPos) {
    int len = mystrlen(str);
    int sublen = mystrlen(substr);
    char *temp;
    if (startPos > len) {
        startPos = len;
    }
    if (startPos < len) {
        temp = new char[len - startPos + 1]{};
        mystrcpy(temp, str + startPos);
        mystrcpy(str + startPos, substr);
        mystrcpy(str + startPos + sublen, temp);
        delete []temp;
        temp = nullptr;
    } else {
        mystrcpy(str + startPos, substr);
    }
    return;
}

void DeleteSubString(char *source, int startPos, int count) {
    char *str = source;
    char *substr = source + startPos + count;
    int len = mystrlen(str);
    // int sublen = mystrlen(substr);
    if (substr - str > len) {
        substr = source + len;
    }
    if (startPos < len) {
        mystrcpy(str + startPos, substr);
    }
    return;
}

int FindSubString(char *str, char *substr, int startPos) {
    int len = mystrlen(str);
    int sublen = mystrlen(substr);
    for (int i = startPos; i < len - sublen + 1; ++i) {
        if (*(str + i) == *substr) {
            bool flag = true; 
            for (int j = 0; j < sublen; ++j) {
                if (*(str + i + j) != *(substr + j)) {
                    flag = false;
                }
            }
            if (flag) return i;
        }
    }
    return -1;
}
bool IsSubString(char *str, char *substr) {
    return (FindSubString(str, substr, 0) != -1 ? true : false);
}

int CountMatches(char *str, char *substr) {
    int len = mystrlen(str);
    int sublen = mystrlen(substr);
    int count = 0;
    for (int i = 0; i < len - sublen + 1; ++i) {
        if (*(str + i) == *substr) {
            bool flag = true; 
            for (int j = 0; j < sublen; ++j) {
                if (*(str + i + j) != *(substr + j)) {
                    flag = false;
                }
            }
            count += flag;
        }
    }
    return count;
}
