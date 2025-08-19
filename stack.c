#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    struct Node *top;
} Stack;

int isEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        puts("Error: Memory allocation failed");
        return;
    }
    
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        puts("Error: Cannot pop from empty stack");
        return -1;
    }
    
    Node *temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);    
    return data;
}

void printStack(Stack *s)
{
    printf("Current Stack (top to bottom): [ ");
    Node *current = s->top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}

void freeStack(Stack *s)
{
    while (!isEmpty(s))
    {
        pop(s);
    }
}

void main()
{
    Stack myStack;
    myStack.top = NULL;
    printStack(&myStack);
    
    puts("Pushing elements:");
    push(&myStack, 10);
    printStack(&myStack);
    push(&myStack, 20);
    printStack(&myStack);
    push(&myStack, 30);
    printStack(&myStack);
    
    puts("Popping elements:");
    pop(&myStack);
    printStack(&myStack);
    pop(&myStack);
    printStack(&myStack);
    pop(&myStack);
    printStack(&myStack);
    
    puts("Trying to pop from empty stack:");
    pop(&myStack);
    
    puts("Pushing more elements:");
    push(&myStack, 100);
    push(&myStack, 200);
    printStack(&myStack);
    
    puts("Freeing remaining stack:");
    freeStack(&myStack);
}