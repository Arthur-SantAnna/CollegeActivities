#include "graph.h"

/*  Grupo:
    Arthur Sant'Anna
    Bernardo Serravalle Resende
    Gabriel Souza Dunkel
 */

int main(void){
    printf("Begin\n");

    FILE *file1, *file2;

    file1 = fopen("file1.txt", "rt");
    file2 = fopen("file2.txt", "rt");

    Graph graph1, graph2;

    startGraph(&file1, &graph1);
    startGraph(&file2, &graph2);

    //printGraph(&graph);

    if(verifyIsomorfism(&graph1, &graph2)){
        printf("Sao isomorfos \n:)\n");
    }else{
        printf("Nao sao isomorfos \n:(\n");
    }

    printf("End\n");

    fclose(file1);
    fclose(file2);

    return 0;
}