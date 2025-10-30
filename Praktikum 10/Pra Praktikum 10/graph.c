#include "graph.h"

void initGraph(Graph *g, int nVertices){
    g->nVertices = nVertices;
    for(int i = 0; i < g->nVertices; i++){
        for(int j = 0; j <g->nVertices; j++){
            g->adjMatrix[i][j] = 0;
        }
    }
}

int IsValidVertex(Graph G, int v){
    return v < G.nVertices && v >= 0? 1 : 0;
}

void addEdge(Graph *g, int src, int dest){
    if(IsValidVertex(*g, src) && IsValidVertex(*g, dest)){
        g->adjMatrix[src][dest] = 1;
        g->adjMatrix[dest][src] = 1;
    }
}

void removeEdge(Graph *g, int src, int dest){
    if(IsValidVertex(*g, src) && IsValidVertex(*g, dest)){
        g->adjMatrix[src][dest] = 0;
        g->adjMatrix[dest][src] = 0;
    }
}

int isAdjacent(Graph *g, int src, int dest){
    if(IsValidVertex(*g, src) && IsValidVertex(*g, dest)){                  //cek dulu valid ga simpulnya
        if(g->adjMatrix[src][dest] == 1 && g->adjMatrix[dest][src] == 1){   //baru cek sebelahan ato ngga
            return 1;
        } else{
            return 0;
        }
    } else{
        return 0;
    }
}

// void printGraph(Graph *g)
// {
//     printf("Adjacency Matrix:\n");
//     for (int i = 0; i < g->nVertices; i++)
//     {
//         for (int j = 0; j < g->nVertices; j++)
//         {
//             printf("%d ", g->adjMatrix[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     Graph g;

//     // Inisialisasi graph dengan 5 simpul
//     initGraph(&g, 5);

//     // Tambahkan edge
//     addEdge(&g, 0, 1);
//     addEdge(&g, 0, 2);
//     addEdge(&g, 1, 2);
//     addEdge(&g, 1, 3);
//     addEdge(&g, 3, 4);

//     // Cetak graph
//     printGraph(&g);

//     // Cek ketetanggaan
//     printf("Apakah 0 dan 1 bertetangga? %s\n", isAdjacent(&g, 0, 1) ? "Ya" : "Tidak");
//     printf("Apakah 2 dan 4 bertetangga? %s\n", isAdjacent(&g, 2, 4) ? "Ya" : "Tidak");

//     // Hapus edge dan cetak ulang
//     removeEdge(&g, 1, 2);
//     printf("\nSetelah menghapus edge antara 1 dan 2:\n");
//     printGraph(&g);

//     return 0;
// }