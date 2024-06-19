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
  struct Node *bottom;
} Stack;

void push (Stack *s, int data)
{
  Node *current = (Node *) malloc (sizeof (Node));
  current->data = data;
  current->next = NULL;
  if (s->top == NULL)
	{
	  s->top = current;
	  s->bottom = current;
	}
  else
	{
	  s->top->next = current;
	  s->top = current;
	}
}

void pop (Stack *s)
{
  Node *temp = s->bottom;
  while (temp->next->next != NULL)
	{
	  temp = temp->next;
	}
   s->top = temp;
   temp->next = NULL;
   temp = NULL;
   free (temp);
}

void printStack (Stack *s)
{
  printf ("Current Stack: [ ");
  Node *current = s->bottom;
  while (current != NULL)
	{
	  printf ("%i ", current->data);
	  current = current->next;
	}
  puts ("]");
}
