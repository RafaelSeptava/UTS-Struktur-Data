#include "DLL.h"
#include "DLL.cpp"
#include <iostream>
using namespace std;

int main() {
    List L;
    createNewList(L);

    infotype data1 = {1, "Postingan 1", 10, "A"};
    infotype data2 = {2, "Postingan 2", 20, "B"};
    infotype data3 = {3, "Postingan 3", 15, "C"};

    address p1 = createElement(data1);
    address p2 = createElement(data2);
    address p3 = createElement(data3);

    insertLast(L, p1);
    insertLast(L, p2);
    insertLast(L, p3);

    printList(L);
    showUsername(L, "A");
    showMostLiked(L);

    return 0;
}