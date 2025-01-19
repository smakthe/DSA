#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void printList(Node *list) {
    Node *ptr = list;
    while (ptr != NULL) {
        printf("%i ", ptr->value);
        ptr = ptr->next;
    }
}

Node *reverseList(Node *list) {
    Node *curr = list, *prev = NULL, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *sortList(Node *list) {
    if (list == NULL || list->next == NULL) {
        return list;
    }

    bool swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do {
        swapped = false;
        ptr1 = list;

        while (ptr1->next != lptr) {
            if (ptr1->value > ptr1->next->value) {
                int temp = ptr1->value;
                ptr1->value = ptr1->next->value;
                ptr1->next->value = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return list;
}

Node *insert(Node *list, int value){
    Node *newHead = (Node *)malloc(sizeof(Node));
    newHead->value = value;
    newHead->next = list;
    return newHead;
}

Node *delete(Node *list, int value){
    Node *ptr = list;
    while(ptr->next->value != value){
        ptr = ptr->next;
    }
    Node *nodeToDelete = ptr->next;
    ptr->next = nodeToDelete->next;
    nodeToDelete = NULL;
    free(nodeToDelete);
    return list;
}

int main() {
    Node *lastNode = (Node *)malloc(sizeof(Node));
    lastNode->value = 27;
    lastNode->next = NULL;

    Node *midNode = (Node *)malloc(sizeof(Node));
    midNode->value = 8;
    midNode->next = lastNode;

    Node *head = (Node *)malloc(sizeof(Node));
    head->value = 13;
    head->next = midNode;

    printf("\nOriginal List: ");
    printList(head);

    Node *reversedList = reverseList(head);
    printf("\nReversed List: ");
    printList(reversedList);

    Node *sortedList = sortList(reversedList);
    printf("\nSorted List: ");
    printList(sortedList);

    Node *newList = insert(sortedList, 4);
    printf("\nAfter insertion: ");
    printList(newList);

    Node *newList2 = delete(newList,13);
    printf("\nAfter deletion: ");
    printList(newList2);

    free(lastNode);
    free(midNode);
    free(head);

    return 0;
}
