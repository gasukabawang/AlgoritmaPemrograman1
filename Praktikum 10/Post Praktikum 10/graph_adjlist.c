#include "graph_adjlist.h"
#include <stdlib.h>
#include <stdio.h>

Node *createNode(int v){
    Node* p = (Node*) malloc(sizeof(Node));
    if(p != NULL){
        p->vertex = v;
        p->next = NULL;
    }
    return p;
}

Graph *createGraph(int numVertices){
    Graph* q = (Graph*) malloc(sizeof(Graph));
    if(q != NULL){
        q->numVertices = numVertices;
        if(numVertices > 0){
            q->adjList = (Node **) malloc(numVertices * sizeof(Node *));
            if(q->adjList != NULL){
                for(int i = 0; i < numVertices; i++){
                    q->adjList[i] = NULL;
                }
            } else{
                free(q);
                return NULL;
            }
        }
    }
    return q;
}

void addEdge(Graph *graph, int v1, int v2){
    if(graph == NULL || v1 < 0 || v1 >= graph->numVertices || v2 < 0 || v2 >= graph->numVertices){
        printf("Penambahan edge gagal.\n");
        return;
    }
    Node* newNode1 = createNode(v2);
    Node* newNode2 = createNode(v1);

    if(newNode1 == NULL || newNode2 == NULL){
        printf("Penambahan edge gagal.\n");
        free(newNode1);
        free(newNode2);
        return;
    }

    if(graph->adjList[v1] == NULL){
        graph->adjList[v1] = newNode1;
    } else{
        Node* temp = graph->adjList[v1];
        while(temp->next != NULL){
            temp = temp->next;                  //cari node terakhir
        }
        temp->next = newNode1;
    }

    if(graph->adjList[v2] == NULL){
        graph->adjList[v2] = newNode2;
    } else{
        Node* temp = graph->adjList[v2];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode2;
    }
}

void freeGraph(Graph *graph){
    if(graph){
        if(graph->adjList != NULL){
            for(int i = 0; i < graph->numVertices; i++){
                Node* current = graph->adjList[i];
                while(current){
                    Node* next = current->next;
                    free(current);
                    current = next;
                }
            }
        }
        free(graph->adjList);
    }
    free(graph);
}