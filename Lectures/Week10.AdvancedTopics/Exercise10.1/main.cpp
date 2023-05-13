#include "ListSort.hpp"
#include "List.hpp"
#include <iostream>

int main() {
    List list;
    init(list);
    inputList(list);
    std::cout << "List before sorting:\n";
    printList(list);
    sort(list);
    std::cout << "list after sorting using merge sort:\n";
    printList(list);
}
