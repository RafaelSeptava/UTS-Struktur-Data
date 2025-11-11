Asesmen	Praktikum	Sub	CLO	3 Struktur	Data	Linear

Nama: Rafael Putra Septava

NIM: 103122400015

Kelas: SE-08-01

1. Kode Program

Berikut adalah kode program untuk menunjukan jumlah data postingan menggunakan struktur data linked list.

DLL.h
#ifndef DLL_H
#define DLL_H
#include <iostream>
#include <stdlib.h>

#define first(L) (L).first
#define last(L) (L).last
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info
#define NIL NULL

using namespace std;

//deklarasi struct infotype
struct infotype {
    int ID;
    string konten;
    int jumlahLike;
    string username;
};

typedef struct elementList* address;

//deklarasi struct linked list
struct elementList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

//deklarasi subprogram
address newElement(infotype data);
void createNewList(List &L);
bool isEmpty(List L);
void insertFirst(List &L, address p);
void insertAfter(List &L, address prec, address p);
void insertLast(List &L, address p);
void deleteFirst(List &L, address &p);
void deleteLast(List &L, address &p);
int length(List L);
address findElement(List L, int ID);
void printList(List L);

//deklarasi subprogram split list
void insertAscending(List &L, infotype data);
void showUsername(List L, string username);
void showMostLiked(List L);
void showUpdatedLikes(List L, int ID, int newLikes);
void splitList(List L, List &L1, List &L2);

#endif

DLL.cpp

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

Main.cpp

#include "DLL.h"
#include "DLL.cpp"
#include <iostream>
using namespace std;
// Rafael Putra Septava_103122400015
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

2. Penjelasan Kode

createElement(infotype data) = membuat node baru berisi data postingan, prev, next,
void createNewList(List &L) = mengisi list kosong dengan First dan Last bernilai NIL,
isEmpty(List L) = mengembalikan true jika nilai kosong,

insertLast(List &L, address p) = menambah node di akhir list,
insertAfter(List &L, address p, address prec) = menyisipkan node p setelah node tertentu,
deleteFirst dan deleteLast = menghapus elemen pertama dan terakhir,

length(List L) = menghitung jumlah node dalam list,
findElement(List L, int ID) = mencari node berdasarkan ID,
printList(List L) = menampilkan postingan ,

3. Output Program

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/e1b70116-a264-47d0-8a05-8960ea9073b7" />


4. Penjelasan Lanjutan (Analisis Output)

showUsername(List L, string username) = menampilkan data postingan sesuai username yang dipilih
showMostLiked(List L) = menemukan dan menampilkan postingan dengan jumlah like terbanyak
showUpdatedLikes = menambah atau mengurangi berdasarkan perubahan like

5. Kesimpulan

Berdasarkan hasil UTS yang sudah kerjakan, saya menyimpulkan bahwa tugas UTS ini adalah membuat list dari postingan dengan atribut ID, konten, jumlah like dan juga username. Lalu juga memahami 
bagaimana cara mencari program dari nama postingan. Dan juga saya memahami bagaimana cara membuat subprogram dari postingan terpopuler.
