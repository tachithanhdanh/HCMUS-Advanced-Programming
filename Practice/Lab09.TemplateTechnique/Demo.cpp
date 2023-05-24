#include "Demo.hpp"
#include "Array.hpp"
#include "Fraction.hpp"
#include "sort.hpp"
#include <iostream>
#include <string>

void demoSortArray() {
    using std::cout;
    cout << "Da em chao thay,";
    cout << "em la Ta Chi Thanh Danh, ";
    cout << "MSSV 22120049.\n";
    cout << "Hom nay em xin demo ham sap xep cho hai kieu du lieu";
    cout << " Fraction va std::string.\n";
    cout << "Voi moi kieu du lieu, em se demo mang ";
    cout << " duoc sap xep tang dan va sau do la sap xep giam dan.\n";
    demoSortFractionArray();
    demoSortStringArray();

}

void demoSortFractionArray() {
    using std::cout;
    cout << "Em xin phep demo ham sap xep mang chua kieu du lieu Fraction.\n";
    cout << "De nhap phan so, thay vui long nhap theo dinh dang a/b (vi du: 1/2 3/5 7/9).";
    Array<Fraction> FractionArray;

    FractionArray.read(std::cin, std::cout);

    cout << "Mang Fraction sau khi duoc sap xep theo thu tu tang dan:\n";
    FractionArray.sort(less<Fraction>);
    FractionArray.print(std::cout);

    cout << "Mang Fraction sau khi duoc sap xep theo thu tu giam dan:\n";
    FractionArray.sort(greater<Fraction>);
    FractionArray.print(std::cout);

    cout.put('\n');
}

void demoSortStringArray() {
    using std::cout;
    cout << "Em xin phep demo ham sap xep mang chua kieu du lieu std::string.\n";
    cout << "Mang std::string chi nhan cac ky tu lien nhau.";
    Array<string> FractionArray;

    FractionArray.read(std::cin, std::cout);

    cout << "Mang std::string sau khi duoc sap xep theo thu tu tang dan:\n";
    FractionArray.sort(less<string>);
    FractionArray.print(std::cout);

    cout << "Mang std::string sau khi duoc sap xep theo thu tu giam dan:\n";
    FractionArray.sort(greater<string>);
    FractionArray.print(std::cout);

    cout.put('\n');
}

void demoSLL() {
    demoFractionSLL();
    demoStringSLL();
}

const Fraction nullFrac(0, 0);

void greeting(const string& dataType) {
    cout << "Da em chao thay,";
    cout << " sau day em xin demo danh sach lien ket";
    cout << " dung cho kieu du lieu";
    cout << " " << dataType << "\n";
    cout << "Trong qua trinh demo cac thao tac,";
    cout << " se co mot so thao tac duoc su dung lai nhieu lan";
    cout << " do dac thu cua chuong trinh.\n";
    cout << "Vi thao tac thu 3 la";
    cout << " thao tac xoa toan bo danh sach lien ket";
    cout << " nen em xin phep demo cuoi cung.\n";
}

void outputGreeting(const string& dataType) {
    cout << "Thao tac so 2: In danh sach lien ket.\n";
    cout << "Danh sach lien ket chua kieu du lieu " << dataType << ".\n";
    cout << "Danh sach lien ket duoc in theo thu tu tu head den tail.\n";
}