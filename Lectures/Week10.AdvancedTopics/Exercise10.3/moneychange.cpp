#include "moneychange.hpp"
#include <iostream>

void demoChangeMoney() {
    std::cout << "Nhap so loai tien: ";
    int n;
    std::cin >> n;
    int* money = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap menh gia cua loai to tien thu " << i + 1 << ": ";
        std::cin >> money[i];
    }
    std::cout << "Nhap so tien can doi: ";
    int m;
    std::cin >> m;
    changeMoneyBottomUp(money, n, m);
    delete[] money;
}

void changeMoneyBottomUp(int* money, int n, int m) {
    int* minMoneyChange = new int[m + 1]{};
    int* trace = new int[m + 1]{};
    for (int i = 0; i <= m; ++i) {
        minMoneyChange[i] = (1 << 25);
    }

    minMoneyChange[0] = 0;
    int curMoney;
    for (curMoney = 1; curMoney <= m; ++curMoney) {
        for (int j = 0; j < n; ++j) {
            if (curMoney - money[j] >= 0 
                && minMoneyChange[curMoney] > minMoneyChange[curMoney - money[j]] + 1)
            {
                minMoneyChange[curMoney] = minMoneyChange[curMoney - money[j]] + 1;
                trace[curMoney] = money[j];
            }
        }
    }

    std::cout << "\nSo to tien it nhat can dung de doi thanh " << m << " dong: ";
    std::cout <<minMoneyChange[m] << '\n';
    std::cout << "Cac to tien da dung: ";
    curMoney = m;
    while (curMoney != 0) {
        std::cout << trace[curMoney] << " ";
        curMoney -= trace[curMoney];
    }
    std::cout << '\n';

    delete[] trace;
    delete[] minMoneyChange;
}
