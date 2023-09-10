#include "graph.h"

/*  Grupo:
    Arthur Sant'Anna
    Bernardo Serravalle Resende
    Gabriel Souza Dunkel
 */

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