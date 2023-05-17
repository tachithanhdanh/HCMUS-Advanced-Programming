#include <iostream>

using cmpFcnPtr = bool(*)(int, int);
using intPtr = int*;

bool descending(int, int);
bool evenNumberDescending(int, int);
bool negativeAscendingPositiveDescending(double, double);
bool primeAscending(int, int);
bool evenAscendingOddDescending(int, int);
void sortIntArray(intPtr arr, int n, cmpFcnPtr cmpFcn);
void sortDoubleArray(double* arr, int n, bool(*cmpFcn)(double, double));
bool isPrime(int num);
void swapInt(int& lhs, int& rhs);
void swapDouble(double& lhs, double& rhs);
void demoArraySorting(cmpFcnPtr cmpFcn);
void demo();
void demoExercise3();
void inputIntArray(intPtr& arr, int& n);
void printIntArray(intPtr arr, int n);
void inputDoubleArray(double*& arr, int& n);
void printDoubleArray(double* arr, int n);

int main() {
    demo();
    return 0;
}

void demo() {
    using std::cout;
    cout << "Da em chao thay, em la Thanh Danh, ";
    cout << "MSSV 22120049.\n";
    cout << "Hom nay em xin demo cac ham phuc vu cho viec sap xep.\n\n";

    cout << "Bai toan 1: Sap xep mang so nguyen theo thu tu giam dan.\n";
    demoArraySorting(descending);
    cout.put('\n');
    
    cout << "Bai toan 2: Sap xep phan tu chan";
    cout << " trong mang so nguyen theo thu tu giam dan.\n";
    demoArraySorting(evenNumberDescending);
    cout.put('\n');

    cout << "Bai toan 3: Sap xep phan tu am thi tang";
    cout << " con phan tu duong thi giam";
    cout << " trong mang so thuc.\n";
    demoExercise3();
    cout.put('\n');

    cout << "Bai toan 4: Sap xep phan tu nguyen to trong";
    cout << " mang so nguyen theo thu tu tang dan.\n";
    demoArraySorting(primeAscending);
    cout.put('\n');

    cout << "Bai toan 5: Sap xep mang mot chieu";
    cout << " cac so nguyen theo yeu cau sau:\n";
    cout << "+ Tat ca so chan don ve phia trai cua mang theo thu tu tang dan.\n";
    cout << "+ Tat ca so le don ve phia phai cua mang theo thu tu giam dan.\n";
    demoArraySorting(evenAscendingOddDescending);
    cout.put('\n');
}

void demoArraySorting(cmpFcnPtr cmpFcn) {
    intPtr arr = nullptr;
    int n{};
    inputIntArray(arr, n);
    std::cout << "\nMang so nguyen truoc khi sap xep.\n";
    printIntArray(arr, n);
    sortIntArray(arr, n, cmpFcn);
    std::cout << "Mang so nguyen sau khi duoc sap xep theo yeu cau bai toan.\n";
    printIntArray(arr, n);
    delete[] arr;
}

void demoExercise3() {
    double* arr;
    int n;
    inputDoubleArray(arr, n);
    std::cout << "\nMang so thuc truoc khi sap xep.\n";
    printDoubleArray(arr, n);
    sortDoubleArray(arr, n, negativeAscendingPositiveDescending);
    std::cout << "Mang so thuc sau khi duoc sap xep theo yeu cau bai toan.\n";
    printDoubleArray(arr, n);
    delete[] arr;
}

void inputDoubleArray(double*& arr, int& n) {
    std::cout << "Moi thay nhap kich co mang n = ";
    std::cin >> n;
    std::cout << "Moi thay nhap mang so thuc arr.";
    arr = new double[n]{};
    for (int i = 0; i < n; ++i) {
        std::cout << "Moi thay nhap arr[" << i << "] = ";
        std::cin >> arr[i];
    }
}
void printDoubleArray(double* arr, int n) {
    std::cout << "Mang so thuc arr co kich co n = " << n << '\n';
    std::cout << "Cac phan tu trong mang (ngan cach nhau boi khoang trang):\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " \n"[i == n - 1];
    }
}

void sortDoubleArray(double* arr, int n, bool(*cmpFcn)(double, double)) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!cmpFcn(arr[j], arr[j + 1])) {
                swapDouble(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortIntArray(intPtr arr, int n, cmpFcnPtr cmpFcn) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!cmpFcn(arr[j], arr[j + 1])) {
                swapInt(arr[j], arr[j + 1]);
            }
        }
    }
}

void swapInt(int& lhs, int& rhs) {
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

void swapDouble(double& lhs, double& rhs) {
    double temp = lhs;
    lhs = rhs;
    rhs = temp;
}

void inputIntArray(intPtr& arr, int& n) {
    std::cout << "Moi thay nhap kich co mang n = ";
    std::cin >> n;
    std::cout << "Moi thay nhap mang so nguyen arr.";
    arr = new int[n]{};
    for (int i = 0; i < n; ++i) {
        std::cout << "Moi thay nhap arr[" << i << "] = ";
        std::cin >> arr[i];
    }
}

void printIntArray(intPtr arr, int n) {
    std::cout << "Mang arr co kich co n = " << n << '\n';
    std::cout << "Cac phan tu trong mang (ngan cach nhau boi khoang trang):\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " \n"[i == n - 1];
    }
}

bool descending(int a, int b) {
    return a >= b;
}

bool evenNumberDescending(int lhs, int rhs) {
    if (lhs == rhs) return true;

    if (lhs % 2) {
        return rhs % 2;
    } else {
        if (rhs % 2) {
            return true;
        } else {
            return lhs > rhs;
        }
    }
}

bool negativeAscendingPositiveDescending(double lhs, double rhs) {
    if (lhs == rhs) return true;

    if (lhs < 0) {
        if (rhs >= 0) {
            return true;
        } else {
            return lhs < rhs;
        }
    } else if (lhs == 0) {
        return rhs > 0;
    } else {
        if (rhs <= 0) {
            return false;
        } else {
            return lhs > rhs;
        }
    }
}

bool primeAscending(int lhs, int rhs) {
    if (lhs == rhs) return true;
    
    if (isPrime(lhs)) {
        if (!isPrime(rhs)) {
            return true;
        } else {
            return lhs < rhs;
        }
    } else {
        if (isPrime(rhs)) {
            return false;
        } else {
            return true;
        }
    }
}

bool isPrime(int num) {
    if (num < 2) return false;
    if (num % 2 == 0 && num > 2) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool evenAscendingOddDescending(int lhs, int rhs) {
    if (lhs == rhs) return true;

    if (lhs % 2 == 0 && rhs % 2 == 0) {
        return lhs < rhs;
    } else if (lhs % 2 == 1 && rhs % 2 == 1) {
        return lhs > rhs;
    } else if (lhs % 2 == 1 && rhs % 2 == 0) {
        return false;
    } else return true;
}
