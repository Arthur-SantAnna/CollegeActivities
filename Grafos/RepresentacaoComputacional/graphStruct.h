#ifndef GRAPHSTRUCT
#define GRAPHSTRUCT

//struct to define a list of adjacenty nodes
typedef struct Adj {
    struct Node* node;
    struct Adj* nextNode;
} Adj;

//struct to define a node
typedef struct Node {
    char label[100];
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

#endif
