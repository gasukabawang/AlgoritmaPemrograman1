#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address P = (address) malloc(sizeof(ElmtList));
    if(P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P){
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    address P = First(L);
    while(P != Nil){
        if(Info(P) == X){
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
    if(P != Nil){
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
    if(P != Nil){
        if(IsEmpty(*L)){
            First(*L) = P;
        } else{
            address last = First(*L);
            while(Next(last) != Nil){
                last = Next(last);
            }
            Next(last) = P;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    address P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X){
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L) = P; 
}

void InsertAfter (address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P){
    if(IsEmpty(*L)){
        InsertFirst(L, P);
    } else{
        address last = First(*L);
        while(Next(last) != Nil){
            last = Next(last);
        }
        Next(last) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}

void DelP (List *L, infotype X){
    address P = First(*L);
    address prev = Nil;
    while(P != Nil && Info(P) != X){
        prev = P;
        P = Next(P);
    }
    if(P != Nil){
        if(prev == Nil){
            First(*L) = Next(P);
        } else{
            Next(prev) = Next(P);
        }
        free(P);
    }
}

void DelLast (List *L, address *P){
    address Last = First(*L), Prev = Nil;
    while (Next(Last) != Nil) {
        Prev = Last;
        Last = Next(Last);
    }
    *P = Last;
    if (Prev == Nil) {
        First(*L) = Nil;
    } else {
        Next(Prev) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = Nil;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    address P = First(L);
    printf("[");
    while(P != Nil){
        printf("%d", Info(P));
        P = Next(P);
        if(P != Nil){
            printf(",");
        }
    }
    printf("]\n");
}

int NbElmt (List L){
    int count = 0;
    address P = First(L);
    while(P != Nil){
        count++;
        P = Next(P);
    }
    return count;
}

infotype Max (List L){
    address P = First(L);
    infotype max = Info(P);
    while(P != Nil){
        if(Info(P) > max){
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}

address AdrMax (List L){
    if (IsEmpty(L)) return Nil;
    address P = First(L), adrmax = P;
    while(P != Nil){
        if(Info(P) > Info(adrmax)){
            adrmax = P;
        }
        P = Next(P);
    }
    return adrmax;
}

infotype Min (List L){
    address P = First(L);
    infotype min = Info(P);
    while(P != Nil){
        if(Info(P) < min){
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}

address AdrMin (List L){
    if (IsEmpty(L)) return Nil;
    address P = First(L), adrmin = P;
    while(P != Nil){
        if(Info(P) < Info(adrmin)){
            adrmin = P;
        }
        P = Next(P);
    }
    return adrmin;
}

float Average (List L){
    int sum = 0, count = 0;
    address P = First(L);
    while(P != Nil){
        sum += Info(P);
        count++;
        P = Next(P);
    }
    return (float)sum/count;
}

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){
    address P = First(*L), Prec = Nil, NextP;
    while(P != Nil) {
        NextP = Next(P);
        Next(P) = Prec;
        Prec = P;
        P = NextP;
    }
    First(*L) = Prec;
}

void Konkat1 (List *L1, List *L2, List *L3){
    CreateEmpty(L3);
    if (IsEmpty(*L1)) {
        First(*L3) = First(*L2);
    } else {
        First(*L3) = First(*L1);
        address P = First(*L1);
        while (Next(P) != Nil) {
            P = Next(P);
        }
        Next(P) = First(*L2);
    }
    First(*L1) = Nil;
    First(*L2) = Nil;
}

/****************** Fungsi Tambahan ******************/
void SortListAsc(List *L){
    if (IsEmpty(*L) || Next(First(*L)) == Nil) return;

    address last = Nil; 
    while (last != First(*L)) {
        address P = First(*L);
        while (Next(P) != last && Next(P) != Nil) {
            address Q = Next(P);
            if (Info(P) > Info(Q)) {
                infotype temp = Info(P);
                Info(P) = Info(Q);
                Info(Q) = temp;
            }
            P = Next(P);
        }
        last = P;
    }
}

void RemoveDuplicate(List *L){
    if(IsEmpty(*L)){
        return;
    }
    address P = First(*L);
    while(P != Nil){
        infotype val = Info(P);
        address prev = P;
        address next = Next(P);
        while(next != Nil){
            if(Info(next) == val){
                address temp = next;
                next = Next(next);
                DelAfter(L, &temp, prev);
            } else{
                prev = next;
                next = Next(next);
            }
        }
        P = Next(P);
    }
}