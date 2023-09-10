#ifndef GRAPH
#define GRAPH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//the following structs are part of the structure of a graph 
//struct to define a list of adjacenty nodes
typedef struct Adj {
    struct Node* node;
    struct Adj* nextNode;
} Adj;

//struct to define a node
typedef struct Node {
    char label;
    int edges;
    int degree;
    Adj *adjList;
} Node;

//struct to define a graph
typedef struct {
    int numNodes;
    int numEdges;
    struct Node* root;
} Graph;
//end

Graph *startGraph(FILE **file, Graph *graph);

void settingAdjList(FILE *arq, Graph *graph);

void insertNode(Graph *graph, char *insert, Node *currentNode);

Graph *startGraph(FILE **file, Graph *graph){

    graph->numEdges = 0;
    graph->numNodes = 0;
    graph->root = NULL;

    if(!file){
        printf("Error reading file.\n");
        exit(0);
    }

    char line[100];
    char *entry;
    entry = fgets(line, 100, *file);
    char *noSpaceLine = NULL;
    int lineSize = 0;
    int i = 0;

    //printf("Entry: %s\n", entry);

    if(entry == NULL){
        printf("Error reading line.\n");
    }

    //remove spaces of first line and count node number
    lineSize = strlen(line);
    noSpaceLine = (char *)malloc(lineSize * sizeof(char));
    int j = 0;
    for(i = 0; i < lineSize; i++){
        if(entry[i] != 32 && entry[i] != '\n'){
            noSpaceLine[j++] = entry[i];
        }
    }
    noSpaceLine[j] = '\0';

    printf("Line without spaces: %s\n", noSpaceLine);
    graph->numNodes = strlen(noSpaceLine);
    printf("Node number: %d\n", graph->numNodes);

    //Count numNodes and get labels  ^^^

    //Setting labels vvv
    
    graph->root = (Node *)malloc(graph->numNodes * sizeof(Node));

    graph->root = &graph->root[0];

    for(int i = 0; i < (graph->numNodes); i++){
        graph->root[i].edges = 0;
        graph->root[i].degree = 0;
        graph->root[i].label = noSpaceLine[i];
        //printf("Label: %c\n",graph->root[i].label);
    }

    settingAdjList(*file, graph);
    
    return graph;
}

void settingAdjList(FILE *file, Graph *graph){
    
    char line[100];
    char *entry;
    char *noSpaceLine = NULL;
    int lineSize = 0;
    int i = 0, j = 0, k = 0;

    while(!feof(file)){
        entry = fgets(line, 100, file);
        lineSize = strlen(line);
        noSpaceLine = (char *)malloc(lineSize * sizeof(char));
        for(i = 0; i < lineSize; i++){
            if(entry[i] != 32 && entry[i] != '\n'){
                noSpaceLine[j++] = entry[i];
            }
        }
        noSpaceLine[j] = '\0';
        //printf("Linha: %s\n", noSpaceLine);
        if(entry != NULL){
            insertNode(graph, noSpaceLine, &graph->root[k++]);
        }
        j = 0;
        entry = NULL;
        noSpaceLine = NULL;   
    }
    graph->numEdges /= 2;
    //printf("True Graph edges: %d\n", graph->numEdges);
}

Adj *createAdjList(){
    Adj *newList;
    newList = (Adj*) malloc(sizeof(Adj));
    return newList;
}

void insertNode(Graph *graph, char *insert, Node *currentNode){
    
    graph->root->adjList = createAdjList();
    Adj *list = (*graph->root).adjList;

    list->node = currentNode;
    int i = 0;

    for(i = 0; i < graph->numNodes; i++){

        if(insert[i] == '1'){
            list->node = currentNode;
            Adj *auxAdj = createAdjList();
            auxAdj->node = &graph->root[i];
            list->nextNode = auxAdj;
            list = auxAdj;
            currentNode->edges++;

            if(&graph->root[i] == currentNode){
                currentNode->degree += 2;
                graph->numEdges += 2;
            }else{
                currentNode->degree++;
                graph->numEdges++;
            }
        }

        /* printf("Node atual: %c\n", graph->root[i].label);
        printf("Node atual degree: %d\n", graph->root[i].degree);
        printf("Node atual edges: %d\n", graph->root[i].edges);
        printf("--------------------------------\n");
        printf("Node fixo: %c\n", currentNode->label);
        printf("Node fixo degree: %d\n", currentNode->degree);
        printf("Node fixo edges: %d\n", currentNode->edges);
        printf("Graph edges: %d\n", graph->numEdges);
        printf("\n\n"); */
    }
}

void printGraph(Graph *graph){
    
}

#endif