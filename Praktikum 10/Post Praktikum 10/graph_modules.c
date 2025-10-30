#include "graph_modules.h"
#include <stdlib.h>

void printGraph(Graph *graph){
    if(!graph){
        printf("Graph is NULL\n");
    }
    for(int i = 0; i < graph->numVertices; i++){
        printf("%d: ", i);
        Node* temp = graph->adjList[i];
        if(temp != NULL){
            while(temp != NULL){
                printf("%d", temp->vertex);
                if(temp->next != NULL){
                    printf(" -> ");
                }
                temp = temp->next;
            }
        } else{
            printf("Kosong");
        }
        printf("\n");
    }
}

void deleteEdge(Graph *graph, int v1, int v2){
    if(!graph || v1 < 0 || v1 >= graph->numVertices || v2 < 0 || v2 >= graph->numVertices){
        printf("Penghapusan edge gagal.\n");
        return;
    }
    Node** curr = &graph->adjList[v1];
    while(*curr != NULL && (*curr)->vertex != v2){
        curr = &(*curr)->next;
    }
    if(*curr != NULL){
        Node *temp = *curr;
        *curr = (*curr)->next;
        free(temp);
    } else{
        printf("Penghapusan edge gagal.\n");
        return;
    }
    curr = &graph->adjList[v2];
    while(*curr != NULL && (*curr)->vertex != v1){
        curr = &(*curr)->next;
    }
    if(*curr != NULL){
        Node *temp = *curr;
        *curr = (*curr)->next;
        free(temp);
    } else{
        printf("Penghapusan edge gagal.\n");
        return;
    }
}