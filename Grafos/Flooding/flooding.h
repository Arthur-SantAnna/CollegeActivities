#ifndef FLOODING
#define FLOODING

#include "graph.h"
#include "queue.h"

// function that returns the index of a graphs certain node 
int findNodeIndex(Graph *graph, Node *currentNode){
    for(int i = 0; i < graph->numNodes; i++){
        //searching for index
        if(&graph->root[i] == currentNode) return i;
    }
    //if not found
    return -1;
}
// function that checks every connected node in a graph using a queue
void exploreConnectedNodes(int *floodVector, int currentNode, Graph *graph){
    floodVector[currentNode] = 1;// check this position as verified
    Queue queue;
    startQueue(&queue);// create a queue to store the index of nodes
    insertIntoQueue(&queue, currentNode); // insert the current node in queue
    while(queueEmpty(&queue) == 0){
        int n;
        removeFromQueue(&queue, &n);// takes an index and puts it in a variable
        Adj *aux = graph->root[n].adjList;// creates an auxiliar adjacenty with the adjacenty list of the node in this position
        for(int i = 1; i <= graph->root[n].edges; i++){// verify every adjacenty node
            aux = aux->nextNode;
            int r = findNodeIndex(graph, aux->node);// find the index of the node
            if(floodVector[r] == 0){// if the node related to this index has not been verified
                floodVector[r] = 1;// check this position
                insertIntoQueue(&queue, r);// add this index to queue to verify 
            }
        }
    }
}
// function to count the number of related components
int countConnectedComponents(Graph *graph){
    int floodVector[graph->numNodes];
    // create a vector with size equal to the number of nodes.
    // each position corresponds to a node. 
    // 0 means that the node has not been checked, 1 means that it has already been checked 
    memset(floodVector, 0, sizeof(floodVector));// initialize vector with 0 in every position
    int connections = 0;
    for(int n = 0; n <= graph->numNodes; n++){// verify every position of this vector
        if(floodVector[n] == 0){// if this position has not been verified
            exploreConnectedNodes(floodVector, n, graph);// call the function to verify the current position
            connections = connections + 1; // increment 1 to related components 
        }
        if(n == graph->numNodes) return connections;// if every node has been verified, returns the number of related components
    }
}
#endif