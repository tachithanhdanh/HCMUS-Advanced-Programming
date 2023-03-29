#include <iostream>
#include <cstring>

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

int main(void) {
    void solve();
    return 0;
}

void solve() {
    char dest[MAX]{};
    char source[MAX]{};
    int count;
    std::cout << "Da em chao thay, day la ham mystrncpy (StringNCopy).\n";
    std::cout << "Moi thay nhap chuoi ket qua: ";
    std::cin.getline(source, MAX);
    std::cout << "Moi thay nhap so luong ky tu: ";
    std::cin >> count;
    mystrncpy(dest, source, count);
    std::cout << "Chuoi ket qua sau khi duoc su dung ham mystrncpy: " << dest << '\n';

}

int mystrlen(const char *str) {
    const char *p = str;
    while (*p) {
        ++p;
    }
    return static_cast<int>(p - str);
}

char *mystrncpy(char *dest, const char *source, int count) {
    char *_dest = dest;
    while (count-- && (*dest++ = *source++));
    // dest[count] = '\0'; // null-terminated the string
    return _dest;
}

char *mystrcpy(char *dest, const char *source) {
    char *p = dest;
    while (*p++ = *source++);
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
    InsertSubString(source, source + startPos + count, startPos);
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
    int len = mystrlen(str);
    int sublen = mystrlen(substr);
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