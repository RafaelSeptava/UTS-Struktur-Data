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