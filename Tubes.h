#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <cstdlib>

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) L.first
#define last(L) L.last
#define toUniv(P) (P)->toUniv
#define toFak(P) (P)->toFak

using namespace std;

typedef struct dataFakultas *addressFak;
typedef struct dataUniversitas *addressUniv;
typedef struct listRelasi *addressRlsi;

struct infotype {
    string Nama_Univ;
    string Nama_Fak;
    int jumlah;
};

struct dataUniversitas {         //double sirkular
    infotype info;
    addressUniv next;
    addressUniv prev;
};

struct listRelasi {         //single
    addressRlsi next;
    addressUniv toUniv;
    addressFak toFak;
};

struct dataFakultas {          //double
    infotype info;
    addressFak next;
    addressFak prev;
};

struct Universitas {
    addressUniv first;
    addressUniv last;
};

struct Fakultas {
    addressFak first;
    addressFak last;
};

struct Relasi {
    addressRlsi first;
};

bool isEmpty(Universitas U);
bool isEmpty(Fakultas F);
bool isEmpty(Relasi R);

void CreateListUniv(Universitas &U);
void CreateListFak(Fakultas &F);
void CreateListRel(Relasi &R);

void AlokasiDataUniv(infotype X, addressUniv &P);
void AlokasiDataFak(infotype X, addressFak &P);
void AlokasiRelasi(addressUniv x, addressFak y, addressRlsi &P);

void InsertLastRelasi(Universitas U,Fakultas F,Relasi &L, addressRlsi P);
void InsertLastRelasi2(Universitas U,Fakultas F,Relasi &L, addressRlsi P);
void InsertFirstFak(Fakultas &F, addressFak P);
void InsertUniv(Universitas &U, addressUniv P);

void DeleteRelasi(Relasi &R, addressRlsi &S);
void DeleteUniv(Universitas &U, string X,Relasi &L);
void DeleteFak(Fakultas &F, string X, Relasi &L);

addressFak SearchFakultas(Fakultas F, string X);
addressUniv SearchUniv(Universitas U, string X);

void PrintAll(Universitas U, Fakultas F, Relasi R);
void PrintUniv(Relasi L, Universitas U, Fakultas F);
void PrintFak(Relasi L,Universitas U,Fakultas F);
void PrintFakTerbanyak(Universitas U, Fakultas F, Relasi L);
void PrintFakTersedikit(Universitas U,Fakultas F,Relasi L);

addressRlsi SearchFakRlsi(Relasi R, addressFak P);
addressRlsi SearchUnivRlsi(Relasi R, addressUniv P);


#endif // TUBES_H_INCLUDED
