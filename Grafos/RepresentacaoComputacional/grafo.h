#ifndef GRAPH
#define GRAPH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct to define a list of adjacent nodes
typedef struct {
    struct Node *node;
    struct Adj *nextNode;
} Adj; //adjacency

//struct to define a vertice
typedef struct {
    char label;
    int edges;
    int degree;
} Node;

//struct to define a graph
typedef struct {
    int numNodes;
    int numEdge;
    struct Node *root;
} Graph;

//function to 
void startGraph(FILE **file, Graph *graph){
    rewind(*file);
    
    char aux[100]; // Assuming a maximum result string length of 100 characters
    char *entry;
    entry = fgets(aux, 100, *file);

    int lgt = strlen(aux);
    
    char resultLabel[100];  // Assuming a maximum result string length of 100 characters
    int j;
    for (int i = 0; i < strlen(entry); i++) {
        if (entry[i] != ' ') {  // Removes the " "
            resultLabel[j++] = entry[i];
        }
    }
    resultLabel[j] = '\0';  // Null-terminate the result string

    graph->numNodes = strlen(resultLabel);
}

Adj *allocAdj();

void printGraph(Graph *graph);



Adj *allocAdj(){
    Adj *newAdj;
    newAdj = (Adj*)malloc(sizeof(Adj));
    return newAdj;
}




#endif