#ifndef GRAPH
#define GRAPH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void *startGraph(FILE **file, Graph *graph);

void settingAdjList(FILE *arq, Graph *graph);

void insertNode(Graph *graph, char *insert, Node *currentNode);

void *startGraph(FILE **file, Graph *graph){ // function to start a Graph

    graph->numEdges = 0;
    graph->numNodes = 0;
    graph->root = NULL;     

    if(!file){
        printf("Error reading file.\n");
        exit(0);
    }

    /* 
    
        Read file.    
        Make a String without spaces of the first line and count them to set numNodes. 
    
    */

    char line[100];
    char *entry;
    entry = fgets(line, 100, *file);
    char *noSpaceLine = NULL;
    int lineSize = 0;
    int i = 0;

    if(entry == NULL){
        printf("Error reading line.\n");
    }

    lineSize = strlen(line);
    noSpaceLine = (char *)malloc(lineSize * sizeof(char));
    int j = 0;
    for(i = 0; i < lineSize; i++){
        if(entry[i] != 32 && entry[i] != '\n'){
            noSpaceLine[j++] = entry[i];
        }
    }
    noSpaceLine[j] = '\0';
    graph->numNodes = strlen(noSpaceLine);
    

    /* 

        Labels in the right place, using the string without spaces.

    */

    graph->root = (Node *)malloc(graph->numNodes * sizeof(Node));
    graph->root = &graph->root[0];

    for(int i = 0; i < (graph->numNodes); i++){
        graph->root[i].edges = 0;
        graph->root[i].degree = 0;
        graph->root[i].label = noSpaceLine[i];
        //printf("Label: %c\n",graph->root[i].label);
    }

    settingAdjList(*file, graph);
}

void settingAdjList(FILE *file, Graph *graph){
    
    /* 
        Fuction to set the Adjecent List.
    */

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
            insertNode(graph, noSpaceLine, &graph->root[k++]); //Actully setting the Adjecent List.
        }
        j = 0;
        free(entry);
        free(noSpaceLine);
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
            auxAdj->nextNode = NULL;
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
    printf("Total number of edges: %d\n\n", graph->numEdges);
    for(int i = 0; i < graph->numNodes; i++){ 
        Node *tempNode = &graph->root[i];
        Adj *tempAdj = tempNode->adjList;
        printf("Label: %c\n", tempNode->label);
        while(tempAdj->nextNode != NULL){
            printf("%c is adjacenty to: %c\n", graph->root[i].label, tempAdj->nextNode->node->label);
            printf("Degree: %d\n", tempNode->degree);
            printf("Edges number: %d\n", tempNode->edges);
            tempAdj = tempAdj->nextNode;
        }
        printf("\n");
    }
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
  
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

int verifyIsomorfism(Graph *graph1, Graph *graph2){

    if(!(graph1->numNodes == graph2->numNodes)) return 0;
    if(!(graph1->numEdges == graph2->numEdges)) return 0;

    int vectorDegree1[graph1->numNodes];
    memset(vectorDegree1, 0, sizeof(vectorDegree1));
    int vectorDegree2[graph2->numNodes];
    memset(vectorDegree2, 0, sizeof(vectorDegree2));
    int k;

    for(k = 0; k < graph1->numNodes; k++){
        vectorDegree1[k] = graph1->root[k].degree;
    }
    bubbleSort(vectorDegree1, graph1->numNodes);
    
    for(k = 0; k < graph2->numNodes; k++){
        vectorDegree2[k] = graph2->root[k].degree;
    }
    bubbleSort(vectorDegree2, graph2->numNodes);

    for(k = 0; k < graph1->numNodes; k++){
        printf("Ordem foda1: %d\n", vectorDegree1[k]);
    }
    for(k = 0; k < graph2->numNodes; k++){
        printf("Ordem foda2: %d\n", vectorDegree2[k]);
    }
    
    for(k = 0; k < graph1->numNodes; k++){
        if(vectorDegree1[k] != vectorDegree2[k]) return 0;
    }


    int vectorNgh1[graph1->numNodes];
    memset(vectorNgh1, 0, sizeof(vectorNgh1));
    int vectorNgh2[graph2->numNodes];
    memset(vectorNgh2, 0, sizeof(vectorNgh2));

    int i = 0, bigDegree1 = 0, aux1 = 0, bigDegree2, aux2;

    for(i = 0; i < graph1->numNodes; i++){
        if(graph1->root[i].degree > aux1){
            aux1 = graph1->root[i].degree;
            bigDegree1 = i;
        }
    }

    for(i = 0; i < graph2->numNodes; i++){
        if(graph2->root[i].degree > aux2){
            aux2 = graph2->root[i].degree;
            bigDegree2 = i;
        }
    }

    return 1;
}

#endif