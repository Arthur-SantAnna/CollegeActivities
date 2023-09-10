#ifndef GRAPH
#define GRAPH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphStruct.h"

void startGraph(FILE **file, Graph *graph);

void startGraph(FILE **file, Graph *graph){

    graph->numEdges = 0;
    graph->numNodes = 0;
    graph->root = NULL;

    if(!file){
        printf("probleminhas de merda\n");
        exit(0);
    }

    char line[100];
    char *result;
    result = fgets(line, 100, *file);
    char *noSpaceLine = NULL;
    int lineSize = 0;
    int i = 0;
    char caractere[50];

    printf("resultado: %s\n\n", result);

    caractere[0] = fgetc(*file);
    printf("caractere capturado: %s\n\n", &caractere[0]);

   /*  while((caractere = fgetc(*file)) != EOF){
        putchar(caractere);
        printf("\n");
    } */

    printf("chegou aqui\n");
    if(result == NULL){
        printf("Error reading line\n");
    }

    lineSize = strlen(line);
    noSpaceLine = (char *)malloc(lineSize * sizeof(char));
    int j = 0;
    for(i = 0; i < lineSize; i++){
        if(result[i] != 32 && result[i] != '\n'){
            noSpaceLine[j++] = result[i];
        }
    }
    noSpaceLine[j] = '\0';

    printf("Line without spaces: %s\n", noSpaceLine);
    graph->numNodes = strlen(noSpaceLine);
    printf("Node number: %d\n", graph->numNodes);
    

}

#endif