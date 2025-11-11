#include "DLL.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

address createElement (infotype data){
    address p = new elementList;
    info(p) = data;
    next(p) = NIL;
    prev(p) = NIL;
    return p;
}


void createNewList(List &L){
    first(L) = NIL;
    last(L) = NIL;
}

bool isEmpty (List L){
    return first(L) == NIL && last(L) == NIL;
}

//silahkan uncomment untuk NIM ganjil
//void insertFirst (List &a, address p){
//    ...
//}

//silahkan uncomment untuk NIM genap
void insertLast(List &L, address p){
    if (isEmpty(L)) {
        first(L) = p;
        last(L) = p;
    } else {
        prev(p) = last(L);
        next(last(L)) = p;
        last(L) = p;
    }
}

void insertAfter(List &L, address p, address prec){
    if (prec != NIL) {
        next(p) = next(prec);
        prev(p) = prec;
        if (next(prec) != NIL) {
            prev(next(prec)) = p;
        } else {
            last(L) = p;
        }
        next(prec) = p;
    }
}

void deleteFirst(List &L, address p){
    if (isEmpty(L)) {
        cout << "list kosong" << endl;
    } else if (first(L) != last(L)) {
        p = first(L);
        first(L) = next(p);
        prev(first(L)) = NIL;
        next(p) = NIL;
    }else {
        p = first(L);
        first(L) = NIL;
        last(L) = NIL;
        next(p) = NIL;
        prev(p) = NIL;
    }
}

void deleteLast(List &L, address p){
    if (isEmpty(L)) {
        cout << "list kosong" << endl;
    } else if (next(first(L))==NIL){
        p = first(L);
        first(L) = NIL;
        last(L) = NIL;
        next(p) = NIL;
        prev(p) = NIL;
    }else{
        p = last(L);
        last(L) = prev(p);
        prev(p) = NIL;
        next(last(L)) = NIL;
    }

}

int length(List L) {
    int jml = 0;
    address p = first(L);
    while (p != NIL) {
        jml++;
        p = next(p);
    }
    return jml;
}


address findElement (List L, int ID) {
    address Q = first(L);
    while (Q != NIL) {
        if (info(Q).ID == ID) { 
            return Q;
        }
        Q = next(Q);
    }
    return NIL;
}

void printList(List L){
    if (isEmpty(L)){
        cout << "list kosong" << endl;
    }else {
        address p = first(L);
        while (p != NIL){
            cout << "ID: " << info(p).ID << endl;
            cout << "Konten: " << info(p).konten << endl;
            cout << "Jumlah Like: " << info(p).jumlahLike << endl;
            cout << "Username: " << info(p).username << endl;
            cout << "------------------------" << endl;
            p = next(p);
        }
    }
}

//buatlah subprogram splitlist
void splitList(List L, List &L1, List &L2) {
    createNewList(L1);
    createNewList(L2);
    address p = first(L);
    int len = length(L);
    int mid = len / 2;
    int count = 0;

    while (p != NIL) {
        address newElem = createElement(info(p));
        if (count < mid) {
            insertLast(L1, newElem);
        } else {
            insertLast(L2, newElem);
        }
        p = next(p);
        count++;
    }
}

void showUsername(List L, string username) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }

    bool found = false;
    address p = first(L);
    cout << "=== Postingan dari pengguna: " << username << " ===" << endl;

    while (p != NIL) {
        if (info(p).username == username) {
            cout << "ID: " << info(p).ID << endl;
            cout << "Konten: " << info(p).konten << endl;
            cout << "Jumlah Like: " << info(p).jumlahLike << endl;
            cout << "---------------------------" << endl;
            found = true;
        }
        p = next(p);
    }

    if (!found) {
        cout << "Tidak ada postingan dengan username '" << username << "'." << endl;
    }
}

void showMostLiked(List L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }

    address p = first(L);
    address maxNode = p;

    while (p != NIL) {
        if (info(p).jumlahLike > info(maxNode).jumlahLike) {
            maxNode = p;
        }
        p = next(p);
    }

    cout << "=== Postingan Terpopuler ===" << endl;
    cout << "ID: " << info(maxNode).ID << endl;
    cout << "Konten: " << info(maxNode).konten << endl;
    cout << "Jumlah Like: " << info(maxNode).jumlahLike << endl;
    cout << "Username: " << info(maxNode).username << endl;
    cout << "---------------------------" << endl;
}

void showUpdatedLikes(List &L, int ID, int perubahan) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }

    address p = findElement(L, ID);
    if (p == NIL) {
        cout << "Postingan dengan ID " << ID << " tidak ditemukan!" << endl;
    } else {
        info(p).jumlahLike += perubahan;
        if (info(p).jumlahLike < 0) {
            info(p).jumlahLike = 0; 
        }

        cout << "Jumlah like postingan ID " << ID << " telah diperbarui." << endl;
        cout << "Jumlah Like Sekarang: " << info(p).jumlahLike << endl;
    }
}