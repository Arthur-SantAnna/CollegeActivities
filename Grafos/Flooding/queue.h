#ifndef QUEUE
#define QUEUE

#include <stdio.h>


typedef struct{
    int content[100];
    int start;
    int end;
}Queue;

void startQueue(Queue *queue){
    queue->start = queue->end = 99;
}

int next(int position){
    if(position == 99) return 0;
    return ++position;
}

int queueFull(Queue *queue){
    if (next(queue->end) == queue->start) return 1;
    return 0;
}

int queueEmpty(Queue *queue){
    if(queue->start == queue->end) return 1;
    return 0;
}

int insertIntoQueue(Queue *queue, int in){
    if(queueFull(queue)) return 0;  

    queue->end = next(queue->end);
    queue->content[queue->end] = in;
    return 1;
}

int removeFromQueue(Queue *queue, int *out){
    if (queueEmpty(queue)) return 0;

    queue->start = next(queue->start);
    *out = queue->content[queue->start];

    return 1;
}

void printQueue(Queue *queue){
    int i;
    while(!queueEmpty(queue)){
        removeFromQueue(queue, &i);
        printf("%d ", i);
    }
}

int queueLength(Queue *queue){
    if(queueEmpty(queue)) return 0;
    if(queue->start < queue->end) return queue->end - queue->start;
    return 99 - queue->start + queue->end;
}

#endif