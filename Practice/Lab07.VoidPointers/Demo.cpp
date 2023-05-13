#include "Demo.hpp"
#include "Fraction.hpp"
#include "SinglyLinkedList.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
using std::cout;

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

Node_ptr getRandomNode(const SLL& List, const string& op, const string& type) {
    int randomPos{};
    Node_ptr randomNode = nullptr;
    randomPos = rand() % List.countNode();
    do {
        randomPos = rand() %List.countNode();
    } while (randomPos == 0 || randomPos + 1 == List.countNode());
    randomNode = List.getKthElement(randomPos);
    cout << "Node duoc " << op << " co dia chi la ";
    cout << randomNode;
    cout << " chua du lieu la " << type << " ";
    return randomNode;
}

void printListSize(const SLL& List) {
    cout << "Thao tac so 10: Dem so phan tu cua danh sach lien ket.\n";
    cout << "So phan tu cua danh sach lien ket hien tai: ";
    cout << List.countNode() << "\n";
}

void demoOperation12(SLL& List) {
    cout << "Thao tac so 12: Xoa phan tu tai vi tri xac dinh trong danh sach lien ket.\n";
    cout << "Moi thay nhap vi tri can xoa: ";
    int pos;
    std::cin >> pos;
    List.deleteKthNode(pos);
}

void demoFractionSLL() {
    // https://stackoverflow.com/questions/9246536/warning-c4244-argument-conversion-from-time-t-to-unsigned-int-possible
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // int randomPos{};
    Node_ptr randomNode = nullptr;

    greeting("Fraction");
    SLL FractionList(sizeof(Fraction));

    // 1
    inputFractionSLL(FractionList);
    cout.put('\n');

    // 2
    outputFractionSLL(FractionList);
    cout.put('\n');

    // 4
    FractionList.insertAtEnding(getFraction());
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 5
    cout << "Bay gio em se demo thao tac so 5";
    cout << " bang cach lay ngau nhien mot node nao do";
    cout << " de chen phan so moi vao sau no.\n";
    randomNode = getRandomNode(FractionList, "insertAfter", "phan so");
    cout << *reinterpret_cast<Fraction_ptr>(randomNode->getData());
    cout << "\n";
    FractionList.insertAfter(randomNode, getFraction(false));
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 6
    cout << "Bay gio em se demo thao tac so 6";
    cout << " bang cach lay ngau nhien mot node nao do";
    cout << " de chen phan so moi vao truoc no.\n";
    getRandomNode(FractionList, "insertBefore", "phan so");
    cout << *reinterpret_cast<Fraction_ptr>(randomNode->getData());
    cout << "\n";
    FractionList.insertBefore(randomNode, getFraction(false));
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 7
    FractionList.deleteAtBeginning();
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 8
    FractionList.deleteAtEnding();
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 9
    cout << "Bay gio em se demo thao tac so 9";
    cout << " bang cach lay ngau nhien mot node nao do";
    cout << " de xoa.\n";
    randomNode = getRandomNode(FractionList, "deleteMiddle", "phan so");
    cout << *reinterpret_cast<Fraction_ptr>(randomNode->getData());
    cout << "\n";
    FractionList.deleteANode(randomNode);
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 10
    printListSize(FractionList);
    cout.put('\n');

    // 11
    cout << "Thao tac 11: Chen phan tu vao vi tri xac dinh";
    cout << " trong danh sach lien ket.\n";
    cout << "Moi thay nhap vi tri can chen: ";
    int pos;
    std::cin >> pos;
    FractionList.insertBeforeKthElement(getFraction(false), pos);
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 12
    demoOperation12(FractionList);
    printFractionListAfterOperation(FractionList);
    cout.put('\n');

    // 3
    FractionList.deleteAllNode();
    cout << "Da huy xong toan bo danh sach phan so.\n";
    cout << "Em xin dung ham in danh sach phan so de cho thay thay danh sach hien gio la rong.\n";
    printFractionListAfterOperation(FractionList);
    cout.put('\n');
}

void printFractionListAfterOperation(const SLL& FractionList) {
    cout << "Danh sach sau khi da hoan thanh xong thao tac vua roi.\n";
    outputFractionSLL(FractionList);
}

Fraction_ptr getFraction(bool flag) {
    if (flag) {
        cout << "Moi thay nhap phan so de phuc vu cho thao tac tiep theo.\n";
    }
    cout << "Moi thay nhap phan so: ";
    Fraction_ptr pFrac = new Fraction(0, 0);
    std::cin >> *pFrac;
    return pFrac;
}

void inputFractionSLL(SLL& FractionList) {
    cout << "Thao tac 1: Xay dung danh sach lien ket ";
    cout << " dung kieu du lieu Fraction.\n";
    cout << "Moi thay nhap danh sach cac phan so.\n";
    cout << "Cac phan so sau khi nhap se duoc xu ly thanh phan so toi gian.\n";
    cout << "Vi du: thay nhap 100/200 thi em se toi gian lai thanh 1/2\n";
    cout << "Dinh dang nhap: a/b voi a la tu so, b la tu so.\n";
    cout << "Vi du: 1/2, 3/4, 4/5, ...\n";
    cout << "De dung viec nhap danh sach phan so, thay vui long nhap 0/0.\n";
    Fraction_ptr pFrac = nullptr;
    do {
        pFrac = getFraction(false);
        if (*pFrac != nullFrac) {
            FractionList.insertAtEnding(pFrac);
        }
    } while (*pFrac != nullFrac);
    delete pFrac;
    complete(1);
}

void outputFractionSLL(const SLL& FractionList) {
    outputGreeting("Fraction");
    if (FractionList.getHead() == nullptr) {
        outputEmptyList();
    } else {
        for (Node_ptr cur = FractionList.getHead(); cur; cur = cur->nextNode()) {
            cout << *cur;
            cout << ", data = " << *reinterpret_cast<Fraction_ptr>(cur->getData());
            cout << "\n";
        }
    }
    // complete(2);
}

void demoStringSLL() {
    cout << "\n\n";
    greeting("std::string");
    SLL StringList(sizeof(string));
    Node_ptr randomNode = nullptr;

    // 1
    ignoreLine();
    inputStringSLL(StringList);
    cout.put('\n');

    // 2
    outputStringSLL(StringList);
    cout.put('\n');

    // 4
    StringList.insertAtEnding(getString());
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 5
    cout << "Bay gio em se demo thao tac so 5";
    cout << " bang cach lay ngau nhien mot node nao do";
    cout << " de chen string moi vao sau no.\n";
    randomNode = getRandomNode(StringList, "insertAfter", "string");
    cout << *reinterpret_cast<string_ptr>(randomNode->getData());
    cout << "\n";
    StringList.insertAfter(randomNode, getString(false));
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 6
    cout << "Bay gio em se demo thao tac so 6";
    cout << " bang cach lay ngau nhien mot node nao do";
    cout << " de chen string moi vao truoc no.\n";
    getRandomNode(StringList, "insertBefore", "string");
    cout << *reinterpret_cast<string_ptr>(randomNode->getData());
    cout << "\n";
    StringList.insertBefore(randomNode, getString(false));
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 7
    StringList.deleteAtBeginning();
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 8
    StringList.deleteAtEnding();
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 9
    cout << "Bay gio em se demo thao tac so 9";
    cout << " bang cach lay ngau nhien mot node nao do";
    cout << " de xoa.\n";
    randomNode = getRandomNode(StringList, "deleteMiddle", "string");
    cout << *reinterpret_cast<string_ptr>(randomNode->getData());
    cout << "\n";
    StringList.deleteANode(randomNode);
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 10
    printListSize(StringList);
    cout.put('\n');

    // 11
    cout << "Thao tac 11: Chen phan tu vao vi tri xac dinh";
    cout << " trong danh sach lien ket.\n";
    cout << "Moi thay nhap vi tri can chen: ";
    int pos;
    std::cin >> pos;
    ignoreLine();
    StringList.insertBeforeKthElement(getString(false), pos);
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 12
    demoOperation12(StringList);
    printStringListAfterOperation(StringList);
    cout.put('\n');

    // 3
    StringList.deleteAllNode();
    cout << "Da huy xong toan bo danh sach phan so.\n";
    cout << "Em xin dung ham in danh sach phan so de cho thay thay danh sach hien gio la rong.\n";
    printStringListAfterOperation(StringList);
}

void printStringListAfterOperation(const SLL& StringList) {
    cout << "Danh sach sau khi da hoan thanh xong thao tac vua roi.";
    outputStringSLL(StringList);
}

string_ptr getString(bool flag) {
    if (flag) {
        cout << "Moi thay nhap chuoi de phuc vu cho thao tac tiep theo.\n";
    }
    cout << "Moi thay nhap chuoi: ";
    string_ptr pString = new string();
    std::getline(std::cin, *pString);
    return pString;
}

void inputStringSLL(SLL& StringList) {
    cout << "Thao tac 1: Xay dung danh sach lien ket ";
    cout << " dung kieu du lieu std::string.\n";
    cout << "Moi thay nhap danh sach cac chuoi ky tu.\n";
    cout << "Dinh dang nhap nhu binh thuong, ket thuc boi dau xuong dong.\n";
    cout << "Vi du: Em chao thay Thinh.\n";
    cout << "De dung viec nhap danh sach string, thay vui long nhap xau rong roi enter.\n";
    string_ptr pString = nullptr;
    do {
        pString = getString(false);
        if (!pString->empty()) {
            StringList.insertAtEnding(pString);
        }
    } while (!pString->empty());
    delete pString;
    complete(1);
}

void outputStringSLL(const SLL& StringList) {
    outputGreeting("std::string");
    if (StringList.getHead() == nullptr) {
        outputEmptyList();
    } else {
        for (Node_ptr cur = StringList.getHead(); cur; cur = cur->nextNode()) {
            cout << *cur;
            cout << ", data = " << *reinterpret_cast<string_ptr>(cur->getData());
            cout << "\n";
        }
    }
    complete(2);
}

void outputEmptyList() {
    cout << "Empty list!\n";
}

void complete(int num) {
    cout << "Da thuc hien xong thao tac " << num << ".\n";
}

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
