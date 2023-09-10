#include "graph.h"

int main(void){
    printf("Begin\n");

    FILE *file;

    file = fopen("file.txt", "rt");

    Graph graph;

    startGraph(&file, &graph);

    printf("End\n");

    fclose(file);

    return 0;
}