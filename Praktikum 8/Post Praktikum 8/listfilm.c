#include "listfilm.h"

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

void InsertAfter(List *L, address P, address Prec){
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

/****************** PENGHAPUSAN FILM ******************/
void RemoveGenre(List *L, infotype X){
    address P = First(*L);
    address prev = Nil;
    int count = 0;
    while(P != Nil){
        if(Info(P) == X){
            address del = P;
            if(prev == Nil){
                First(*L) = Next(P);
                P = First(*L);
            } else{
                Next(prev) = Next(P);
                P = Next(P);
            }
            Dealokasi(&del);
            count++;
        } else{
            prev = P;
            P = Next(P);
        }
    }
    if(count>0){
        printf("Berhasil menghapus %d film\n", count);
    } else{
        printf("Tidak ada film yang memiliki genre dengan ID: %d\n", X);
    }
}