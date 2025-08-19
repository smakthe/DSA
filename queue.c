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

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enQueue(Queue *q, int data) {
    Dnode *newNode = (Dnode *)malloc(sizeof(Dnode));
    if (newNode == NULL) {
        puts("Error: Memory allocation failed");
        return;
    }
    
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        newNode->prev = q->rear;
        q->rear = newNode;
    }
}

int deQueue(Queue *q) {
    if (isEmpty(q)) {
        puts("Error: Cannot dequeue from empty queue");
        return -1;
    }
    
    Dnode *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    } else {
        q->front->prev = NULL;
    }
    
    free(temp);
    return data;
}

void printQueue(Queue *q) {
    printf("Current Queue (front to rear): [ ");
    Dnode *current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}

void printQueueReverse(Queue *q) {
    printf("Current Queue (rear to front): [ ");
    Dnode *current = q->rear;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("]\n");
}

void freeQueue(Queue *q) {
    while (!isEmpty(q)) {
        deQueue(q);
    }
}

void main() {
    Queue myQueue;
    myQueue.front = NULL;
    myQueue.rear = NULL;
    printQueue(&myQueue);
    
    puts("Enqueuing elements:");
    enQueue(&myQueue, 10);
    printQueue(&myQueue);
    enQueue(&myQueue, 20);
    printQueue(&myQueue);
    enQueue(&myQueue, 30);
    printQueue(&myQueue);
    printQueueReverse(&myQueue);
    
    puts("Dequeuing elements:");
    printf("Dequeued: %d\n", deQueue(&myQueue));
    printQueue(&myQueue);
    printf("Dequeued: %d\n", deQueue(&myQueue));
    printQueue(&myQueue);
    printf("Dequeued: %d\n", deQueue(&myQueue));
    printQueue(&myQueue);
    
    puts("Trying to dequeue from empty queue:");
    deQueue(&myQueue);
    
    puts("Enqueuing more elements:");
    enQueue(&myQueue, 100);
    enQueue(&myQueue, 200);
    enQueue(&myQueue, 300);
    printQueue(&myQueue);
    
    puts("Freeing remaining queue:");
    freeQueue(&myQueue);
}