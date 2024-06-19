#include <stdio.h>
#include <stdlib.h>

typedef struct Dnode {
    struct Dnode *prev;
    int data;
    struct Dnode *next;
} Dnode;

typedef struct Queue {
    struct Dnode *front;
    struct Dnode *rear;
} Queue;

void enQueue(Queue *q, int data) {
    Dnode *current = (Dnode *)malloc(sizeof(Dnode));
    current->data = data;
    current->prev = NULL;
    current->next = NULL;

    if (q->front == NULL) {
        q->front = current;
        q->rear = current;
    } else {
        q->rear->next = current;
        current->prev = q->rear;
        q->rear = current;
    }
}

void deQueue(Queue *q) {
    if (q->front != NULL) {
        Dnode *temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
    }
}

void printQueue(Queue *q){
    printf("Current Queue: [ ");
    Dnode *current = q->front;
    while (current != NULL) {
        printf("%i ", current->data);
        current = current->next;
    }
    puts("]");
}
