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
    FILE *file1;
    FILE *file2;

    file1 = fopen("file1.txt", "rt");

    Graph graph1;

    startGraph(&file1, &graph1);

    //printGraph(&graph);

    printf("\nNumber of related components: %d\n\n", countConnectedComponents(&graph1));

    fclose(file1);

    file2 = fopen("file2.txt", "rt");

    Graph graph2;

    startGraph(&file2, &graph2);

    //printGraph(&graph);

    printf("\nNumber of related components: %d\n", countConnectedComponents(&graph2));

    fclose(file2);

    printf("\nEnd\n");
    return 0;
}