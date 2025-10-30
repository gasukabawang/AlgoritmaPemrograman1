#include "graph.h"

void initGraph(Graph *g, int nVertices){
    g->nVertices = nVertices;
    for(int i = 0; i < nVertices; i++){
        for(int j = 0; j < nVertices; j++){
            g->adjMatrix[i][j] = -1;
        }
    }
}

int IsValidVertex(Graph G, int v){
    if(v >= 0 && v < G.nVertices){
        return 1;
    } else{
        return 0;
    }
}

void addEdge(Graph *g, int src, int dest, int weight){
    if(IsValidVertex(*g, src) && IsValidVertex(*g, dest)){
        g->adjMatrix[src][dest] = weight;
    }
}

void removeEdge(Graph *g, int src, int dest, int *weight){
    if(IsValidVertex(*g, src) && IsValidVertex(*g, dest)){
        *weight = g->adjMatrix[src][dest];
        g->adjMatrix[src][dest] = -1;
    }
}

int isAdjacent(Graph *g, int src, int dest){
    if(IsValidVertex(*g, src) && IsValidVertex(*g, dest)){
        return g->adjMatrix[src][dest] != -1;
    }
    return 0;
}

// void printGraph(Graph *g) {
//     printf("Adjacency Matrix:\n");
//     for (int i = 0; i < g->nVertices; i++) {
//         for (int j = 0; j < g->nVertices; j++) {
//             printf("%d ", g->adjMatrix[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     Graph g;

//     // Inisialisasi graph dengan 5 simpul
//     initGraph(&g, 5);

//     // Tambahkan edge
//     addEdge(&g, 0, 1, 10);
//     addEdge(&g, 0, 2, 20);
//     addEdge(&g, 1, 2, 30);
//     addEdge(&g, 1, 3, 40);
//     addEdge(&g, 3, 4, 50);

//     // Cetak graph
//     printGraph(&g);

//     // Cek ketetanggaan
//     printf("Apakah 0 dan 1 bertetangga? %s\n", isAdjacent(&g, 0, 1) ? "Ya" : "Tidak");
//     printf("Apakah 2 dan 4 bertetangga? %s\n", isAdjacent(&g, 2, 4) ? "Ya" : "Tidak");

//     // Hapus edge dan cetak ulang
//     int weight;
//     removeEdge(&g, 1, 2, &weight);
//     printf("\nEdge yang dihapus berbobot: %d\n", weight);
//     printf("\nSetelah menghapus edge antara 1 dan 2:\n");
//     printGraph(&g);

//     return 0;
// }