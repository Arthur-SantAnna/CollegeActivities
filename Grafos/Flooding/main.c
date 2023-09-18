#include <stdio.h>
#include "graph.h"
#include "flooding.h"

/* 
    Arthur Sant'Anna de Carvalho Santos
    Bernardo Serravalle Resende
    Gabriel Souza Dunkel
 */

int main(){
    printf("\nBegin\n");
    FILE *file;

    file = fopen("file1.txt", "rt");

    Graph graph;

    startGraph(&file, &graph);

    //printGraph(&graph);

    printf("\nNumber of related components: %d\n", countConnectedComponents(&graph));

    fclose(file);

    printf("\nEnd\n");
    return 0;
}