#include "nimonsgram.h"

void CreateGraph(int x, Graph *g){
    FIRST(*g) = NIL;
    AdrNode p = newGraphNode(x);
    if(p != NIL){
        FIRST(*g) = p;
    }
}

AdrNode newGraphNode(int x){
    AdrNode p = (AdrNode) malloc(sizeof(Node));
    if(p != NIL){
        p->id = x;
        p->nPred = 0;
        p->next = NIL;
        p->trail = NIL;
    }
    return p;
}

void deallocGraphNode(AdrNode p){
    free(p);
}

AdrSuccNode newSuccNode(AdrNode pn){
    AdrSuccNode q = (AdrSuccNode) malloc(sizeof(SuccNode));
    if(q != NIL){
        q->succ = pn;
        q->next = NIL;
    }
    return q;
}

void deallocSuccNode(AdrSuccNode p){
    free(p);
}

AdrNode searchNode(Graph g, int x){
    AdrNode p = FIRST(g);               //cari dr node pertama
    while(p != NIL){
        if(ID(p) != x){
            p = NEXTNODE(p);            //kl ga ketemu, next node
        } else{
            return p;                   //kl ketemu
        }
    }
    return NIL;
}

AdrSuccNode searchEdge(Graph g, int prec, int succ){
    AdrNode p = searchNode(g, prec);                    //mulai dr node pertama
    if(p != NIL){
        AdrSuccNode q = TRAIL(p);                       //cek semua successor dr node
        while(q != NIL){
            if(ID(SUCC(q)) != succ){
                q = NEXTSUCC(q);                        //kl ga ketemu lanjut ke next succ
            } else{
                return q;
            }
        }
    }
    return NIL;
}

void insertNode(Graph *g, int x, AdrNode *pn){
    *pn = newGraphNode(x);                      //buat node
    if(*pn != NIL){
        if(FIRST(*g) == NIL){                   //kl graph kosong, maka jadi FIRST
            FIRST(*g) = *pn;
            return;
        }
        AdrNode last = FIRST(*g);
        while(NEXTNODE(last) != NIL){
            last = NEXTNODE(last);              //cari node terakhir
        }
        NEXTNODE(last) = *pn;                   //tambah node baru di akhir
    }
}

void insertEdge(Graph *g, int prec, int succ){
    AdrNode nodePre = searchNode(*g, prec);             //cari node pre
    AdrNode nodeSucc = searchNode(*g, succ);            //cari node succ
    if(nodePre == NIL){
        insertNode(g, prec, &nodePre);                   //kl blm ada, tambah node baru
    }
    if(nodeSucc == NIL){
        insertNode(g, succ, &nodeSucc);                  //kl blm ada, tambah node baru
    }
    if(searchEdge(*g, prec, succ) == NIL){               //cek dulu ada double edge ga
        AdrSuccNode newEdge = newSuccNode(nodeSucc);
        if(newEdge != NIL){
            AdrSuccNode *ptTrail = &TRAIL(nodePre);     //buat pointer ke succ pertama dalam list succ
            while(*ptTrail != NIL){
                ptTrail = &NEXTSUCC(*ptTrail);          //cari succ terakhir
            }
            *ptTrail = newEdge;                         //tambah edge baru ke succ terakhir
            NPRED(nodeSucc)++;                          //predecessor (panah yang arah ke dia) bertambah
        }
    }
    return;
}

void deleteNode(Graph *g, int x){
    AdrNode delete = searchNode(*g, x);                 //cari node yang mau diapus
    if(delete != NIL){                                  //kl ada, lanjut
        AdrNode p = FIRST(*g);                          //mulai dr awal graph
        while(p != NIL){
            if(p != x){                                 //cari yang mau diapus
                AdrSuccNode *q = &TRAIL(p);             //ambil semua list succ
                while(*q != NIL){
                    if(SUCC(*q) == delete){             //
                        AdrSuccNode del = *q;
                        *q = NEXTSUCC(*q);
                        deallocSuccNode(del);
                        NPRED(delete)--;
                    } else{
                        q = &NEXTSUCC(*q);
                    }
                }
            }
            p = NEXTNODE(p); 
        }
        AdrSuccNode q = TRAIL(delete);
        while(q != NIL){
            AdrSuccNode del = q;
            q = NEXTSUCC(q);
            NPRED(SUCC(del))--;
            deallocSuccNode(del);
        }
        p = FIRST(*g);
        AdrNode prev = NIL;
        while(p != NIL && p != delete){
            prev = p;
            p = NEXTNODE(p);
        }
        if(prev == NIL){
            FIRST(*g) = NEXTNODE(delete);
        } else{
            NEXTNODE(prev) = NEXTNODE(delete);
        }
        deallocGraphNode(delete);
    }
    return;
}

void printGraph(Graph g){
    if(FIRST(g) == NIL){
        printf("Graph kosong\n");
        return;
    }
    AdrNode p = FIRST(g);
    while(p != NIL){
        printf("%d", ID(p));
        AdrSuccNode q = TRAIL(p);
        while(q != NIL){
            printf(" -> %d", ID(SUCC(q)));
            q = NEXTSUCC(q);
        }
        printf("\n");
        p = NEXTNODE(p);
    }
}

AdrNode findNPD(Graph g, int *maxFollower){
    *maxFollower = -1;
    AdrNode result = NIL;
    AdrNode p = FIRST(g);
    while(p != NIL){
        if(NPRED(p) > *maxFollower){
            *maxFollower = NPRED(p);
            result = p;
        }
        p = NEXTNODE(p);
    }
    return result;
}

AdrNode findMisterius(Graph g, int *minFollowing){
    *minFollowing = 999;
    AdrNode result = NIL;
    AdrNode p = FIRST(g);
    while(p != NIL){
        int count = 0;
        AdrSuccNode q = TRAIL(p);
        while(q != NIL){
            count++;
            q = NEXTSUCC(q);
        }
        if(count < *minFollowing){
            *minFollowing = count;
            result = p;
        }
        p = NEXTNODE(p);
    }
    return result;
}

// int main() {
//     Graph G;
//     CreateGraph(1, &G);

//     insertEdge(&G, 1, 2);
//     insertEdge(&G, 1, 3);
//     insertEdge(&G, 2, 3);
//     insertEdge(&G, 4, 3);
//     insertEdge(&G, 5, 2);
//     insertEdge(&G, 5, 3);
//     insertEdge(&G, 4, 2);
//     insertEdge(&G, 3, 4);
//     insertEdge(&G, 3, 5);

//     printf("Graph saat ini:\n");
//     printGraph(G);

//     int maxFollower, minFollowing;
//     AdrNode npd = findNPD(G, &maxFollower);
//     AdrNode misterius = findMisterius(G, &minFollowing);

//     printf("\nHasil Analisis:\n");
//     if (npd != NIL) {
//         printf("Si NPD adalah Nimons %d dengan %d followers.\n", ID(npd), maxFollower);
//     } else {
//         printf("Tidak ada Nimons NPD.\n");
//     }

//     if (misterius != NIL) {
//         printf("Si Misterius adalah Nimons %d dengan %d following.\n", ID(misterius), minFollowing);
//     } else {
//         printf("Tidak ada Nimons Misterius.\n");
//     }

//     return 0;
// }