#include "Demo.hpp"
#include "Array.hpp"
#include "List.hpp"
#include "Fraction.hpp"
#include "sort.hpp"
#include <iostream>
#include <string>

void demoSortArray() {
    using std::cout;
    cout << "Da em chao thay,";
    cout << "em la Ta Chi Thanh Danh, ";
    cout << "MSSV 22120049.\n";
    cout << "Hom nay em xin demo ham sap xep mang cho hai kieu du lieu";
    cout << " Fraction va std::string.\n";
    cout << "Voi moi kieu du lieu, em se demo mang";
    cout << " duoc sap xep tang dan va sau do la sap xep giam dan.\n";
    demoSortFractionArray();
    demoSortStringArray();
}

void demoSortFractionArray() {
    using std::cout;
    cout << "Em xin phep demo ham sap xep mang chua kieu du lieu Fraction.\n";
    cout << "De nhap phan so, thay vui long nhap theo dinh dang a/b (vi du: 1/2 3/5 7/9).\n";
    Array<Fraction> FractionArray;

    FractionArray.read(std::cin, std::cout);

    cout << "Mang Fraction truoc khi duoc sap xep:\n";
    FractionArray.print(std::cout);

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
    cout << "Mang std::string chi nhan cac ky tu lien nhau.\n";
    Array<std::string> StringArray;

    StringArray.read(std::cin, std::cout);

     cout << "Mang std::string truoc khi duoc sap xep:\n";
    StringArray.print(std::cout);

    cout << "Mang std::string sau khi duoc sap xep theo thu tu tang dan:\n";
    StringArray.sort(less<std::string>);
    StringArray.print(std::cout);

    cout << "Mang std::string sau khi duoc sap xep theo thu tu giam dan:\n";
    StringArray.sort(greater<std::string>);
    StringArray.print(std::cout);

    cout.put('\n');
}

void demoSortList() {
    using std::cout;
    cout << "Em xin demo ham sap xep danh sach lien ket don";
    cout << " cho hai kieu du lieu Fraction va std::string.\n";
    cout << "Voi moi kieu du lieu, em se demo danh sach lien ket";
    cout << " duoc sap xep tang dan va sau do la sap xep giam dan.\n";\
    demoSortFractionList();
    demoSortStringList();
}

void demoSortFractionList() {
    using std::cout;
    cout << "Em xin phep demo ham sap xep danh sach lien ket don";
    cout << " chua kieu du lieu Fraction.\n";
    cout << "De nhap phan so, thay vui long nhap theo dinh dang a/b (vi du: 1/2 3/5 7/9).\n";
    cout << "De dung viec nhap phan so, thay vui long nhap 0/0.\n";
    List<Fraction> FractionList;
    FractionList.input(std::cin, std::cout, Fraction(0, 0));

    cout << "Danh sach Fraction truoc khi duoc sap xep:\n";
    FractionList.display(std::cout);

    cout << "Danh sach Fraction sau khi duoc sap xep theo thu tu tang dan:\n";
    FractionList.sort(less<Fraction>);
    FractionList.display(std::cout);

    cout << "Danh sach Fraction sau khi duoc sap xep theo thu tu giam dan:\n";
    FractionList.sort(greater<Fraction>);
    FractionList.display(std::cout);
}

void demoSortStringList() {
    using std::cout;
    cout << "Em xin phep demo ham sap xep danh sach lien ket don";
    cout << " chua kieu du lieu std::string.\n";
    cout << "De nhap chuoi, thay vui long nhap chuoi";
    cout << " khong co dau cach, ket thuc boi dau xuong dong.\n";
    cout << "De dung viec nhap chuoi, thay vui long nhap STOP.\n";
    List<std::string> StringList;
    StringList.input(std::cin, std::cout, "STOP");

    cout << "Danh sach std::string truoc khi duoc sap xep:\n";
    StringList.display(std::cout);

    cout << "Danh sach std::string sau khi duoc sap xep theo thu tu tang dan:\n";
    StringList.sort(less<std::string>);
    StringList.display(std::cout);

    cout << "Danh sach std::string sau khi duoc sap xep theo thu tu giam dan:\n";
    StringList.sort(greater<std::string>);
    StringList.display(std::cout);
}
