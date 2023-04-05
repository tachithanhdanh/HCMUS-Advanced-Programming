#include <iostream>
#include <iomanip>

// https://stackoverflow.com/questions/6622962/generic-way-to-print-out-variable-name-in-c
// https://stackoverflow.com/questions/10507264/how-to-use-macro-argument-as-string-literal
#define print_exercise_name(n) std::cout << "Day la bai " << n << ".\n"
#define get_input(n) \
    std::cout << "Moi thay nhap so nguyen duong " << #n << " = "; \
    std::cin >> n
#define print_result(exercise, function_name) \
    std::cout << "Ket qua cua bai " << #exercise << \
    " la " << #function_name << " = " << function_name << ".\n"
#define print_horizontal_line() \
    for (int i = 0; i < 40; ++i) std::cout << '-'; \
    std::cout << '\n';

using std::cout;
using std::cin;

constexpr int MAX = 1001;
constexpr int N = 101;

void solve();
void exercise1();
void exercise2();
void exercise3();
void exercise4();
void exercise5();
void exercise6();
void exercise7();
void exercise8();
void exercise9();
void exercise10();
void exercise11();
void exercise12();
long long S1(int n);
long double S2(int n);
long double S3(int n);
long long S4(int n, long long x);
long double S5(int n, int x);
int count_prime_numbers(int *a, int n);
int count_perfect_numbers(int *a, int n);
int sum_of_even_numbers_in_array(int *a, int l, int r);
void print_index_of_prime_numbers_in_array(int *a, int n);
void print_index_of_even_numbers_in_array(int *a, int n);
long double special_sum(long double *a, int n);
int count_distinct_numbers_in_array(int *a, int n, int *b = nullptr);
long long fast_pow(long long x, int n);
int sum(int n);
bool is_prime(int n);
bool is_perfect(int n);
template <typename T> void readArray(T *a, int &n);

int main(void) {
    solve();
    return 0;
}

void solve() {
    cout.setf(std::ios::fixed);
    cout.precision(12);
    exercise1();
    exercise2();
    exercise3();
    exercise4();
    exercise5();
    exercise6();
    exercise7();
    exercise8();
    exercise9();
    exercise10();
    exercise11();
    exercise12();
    return;
}

void exercise1() {
    print_exercise_name(1);
    int n;
    get_input(n);
    // cin >> n;
    // cout << "Ket qua cua bai 1 la S(n) = " << S1(n) << '.\n';
    print_result(1, S1(n));
    // cout << S1(n) << ".\n";
    print_horizontal_line();
    return;
}

void exercise2() {
    // cout << "Day la bai 2.\n";
    print_exercise_name(2);
    int n;
    get_input(n);
    // cin >> n;
    print_result(1, S2(n));
    // cout << "Ket qua cua bai 2 la S(n) = "  
    // cout << std::setprecision(12) << S2(n) << ".\n";
    print_horizontal_line();
    return;
}

void exercise3() {
    // cout << "Day la bai 3.\n";
    print_exercise_name(3);
    int n;
    get_input(n);
    // cin >> n;
    // cout << "Ket qua cua bai 3 la S(n) = "
    print_result(3, S3(n));
    print_horizontal_line();
    // cout << std::setprecision(12) << S3(n) << ".\n";
    return;
}

void exercise4() {
    // cout << "Day la bai 4.\n";
    print_exercise_name(4);
    int n, x;
    get_input(n);
    // cin >> n;
    get_input(x);
    // cin >> x;
    // cout << "Ket qua cua bai 4 la S(n, x) = " 
    print_result(4, S4(n, x));
    print_horizontal_line();
    // cout << S4(n, x) << ".\n";
    return;
}

void exercise5() {
    // cout << "Day la bai 5.\n";
    print_exercise_name(5);
    int n, x;
    get_input(n);
    // cin >> n;
    get_input(x);
    // cin >> x;
    print_result(5, S5(n, x));
    print_horizontal_line();
    return;
}

template <typename T>
void readArray(T *a, int &n) {
    cout << "Nhap so phan tu cua mang n = ";
    cin >> n;
    cout << "Nhap cac phan tu cua mang a (ngan cach boi khoang trang): ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return;
}

void exercise6() {
    print_exercise_name(6);
    int a[N], n;
    readArray(a, n);
    cout << "So luong so nguyen to trong mang mot chieu cac so nguyen duong: ";
    cout << count_prime_numbers(a, n) << ".\n";
    print_horizontal_line();
    return;
}

void exercise7() {
    print_exercise_name(7);
    int a[N], n;
    readArray(a, n);
    cout << "So luong so hoan thien trong mang mot chieu cac so nguyen duong: ";
    cout << count_perfect_numbers(a, n) << ".\n";
    print_horizontal_line();
    return;
}

void exercise8() {
    print_exercise_name(8);
    int a[N], n;
    readArray(a, n);
    cout << "Tong cac so chan trong mang mot chieu cac so nguyen duong: ";
    cout << sum_of_even_numbers_in_array(a, 0, n - 1) << ".\n";
    print_horizontal_line();
    return;
}

void exercise9() {
    print_exercise_name(9);
    int a[N], n;
    readArray(a, n);
    cout << "Cac vi tri ma o do cac phan tu la nguyen to trong mang nguyen duong: \n";
    print_index_of_prime_numbers_in_array(a, n);
    cout << "\n";
    print_horizontal_line();
    return;
}

void exercise10() {
    print_exercise_name(10);
    int a[N], n;
    readArray(a, n);
    cout << "Cac vi tri ma o do cac phan tu la chan trong mang nguyen duong: \n";
    print_index_of_even_numbers_in_array(a, n);
    cout << "\n";
    print_horizontal_line();
    return;
}

void exercise11() {
    print_exercise_name(11);
    long double a[N];
    int n;
    readArray(a, n);
    cout << "Tong cac gia tri lon hon cac gia tri lien truoc no trong mang mot chieu cac so thuc: ";
    cout << special_sum(a, n) << ".\n";
    print_horizontal_line();
    return;
}

void exercise12() {
    print_exercise_name(12);
    int a[N], n;
    readArray(a, n);
    cout << "So cac gia tri phan biet trong mang mot chieu so duong: ";
    cout << count_distinct_numbers_in_array(a, n);
    cout << "\n";
    print_horizontal_line();
    return;
}

long long S1(int n) {
    if (n <= 1) return 1LL;
    return 1LL * n * S1(n - 1);
}

long double S2(int n) {
    if (n < 0) return 0.0L;
    if (n == 0) return 1.0L;
    return 1.0L / (2.0L * n + 1.0L) + S2(n - 1);
}

long double S3(int n) {
    if (n < 0) return 0.0L;
    if (n == 0) return 0.5L;
    return (2.0L * n + 1.0L) / (2.0L * n + 2.0L) + S3(n - 1);
}

long long fast_pow(long long x, int n) {
    if (n < 0) return 0;
    if (n == 0) return 1LL;
    if (n == 1) return x;
    if (n & 1) return x * fast_pow(x, n - 1);
    long long temp = fast_pow(x, n >> 1);
    return temp * temp;
}

long long S4(int n, long long x) {
    if (n <= 0) return 0LL;
    return fast_pow(x, n) + S4(n - 1, x);
}

long double S5(int n, int x) {
    if (n == 0) return 0.0L;
    long double last_value = static_cast<long double>(fast_pow(x, n)) / (1.0L * sum(n));
    return last_value + S5(n - 1, x);
}

int sum(int n) {
    if (n < 1) return 0;
    return n + sum(n - 1);
}

int count_prime_numbers(int *a, int n) {
    if (n <= 0) return 0;
    if (n == 1) return is_prime(a[n - 1]);
    return is_prime(a[n - 1]) + count_prime_numbers(a, n - 1);
}

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3 || n == 5 || n == 7) return true;
    if (!(n & 1) || n % 3 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int count_perfect_numbers(int *a, int n) {
    if (n <= 0) return 0;
    if (n == 1) return is_perfect(a[n - 1]);
    return is_perfect(a[n - 1]) + count_perfect_numbers(a, n - 1);
}

bool is_perfect(int n) {
    if (n < 3) return false;
    int sum_divisors = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum_divisors += i;
        }
    }
    return sum_divisors == n;
}

int sum_of_even_numbers_in_array(int *a, int l, int r) {
    if (l == r) {
        return (a[l] % 2 == 0 ? a[l] : 0);
    }
    int mid = (l + r) / 2;
    int sum_left = sum_of_even_numbers_in_array(a, l, mid);
    int sum_right = sum_of_even_numbers_in_array(a, mid + 1, r);
    return sum_left + sum_right;
}

void print_index_of_prime_numbers_in_array(int *a, int n) {
    if (n <= 0) return;
    if (is_prime(a[n - 1])) {
        std::cout << n - 1 << ' ';
    }
    print_index_of_prime_numbers_in_array(a, n - 1);
    return;
}

void print_index_of_even_numbers_in_array(int *a, int n) {
    if (n <= 0) return;
    if (a[n - 1] % 2 == 0) {
        // std:: cout << "a[n - 1] = " << a[n - 1] << " at ";
        std::cout << n - 1 << ' ';
    }
    print_index_of_even_numbers_in_array(a, n - 1);
    return;
}

long double special_sum(long double *a, int n) {
    // asssume the element before the first element is minus infinity.
    if (n <= 0) return 0.0L;
    if (n == 1) return a[n - 1];
    return (a[n - 1] > a[n - 2] ? a[n - 1] : 0.0L) + special_sum(a, n - 1);
}

int count_distinct_numbers_in_array(int *a, int n, int *b) {
    if (b == nullptr) {
        b = new int[MAX]{};
    }
    if (n == 0) {
        delete []b;
        return 0;
    }
    ++b[a[n - 1]];
    bool is_distinct = b[a[n - 1]] == 1;
    return is_distinct + count_distinct_numbers_in_array(a, n - 1, b);
}
