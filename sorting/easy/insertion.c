#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 8

void print(int *a){
    for(int i = 0; i < LEN; i++){
        printf("%i ",*(a+i));
    }
    puts("");
}

void insertion(int *a){
    for(int i = 1; i < LEN; i++){
        int key = *(a+i);
        int j = i-1;
        while ((j >= 0) && (key < *(a+j))){
            *(a+j+1) = *(a+j);
            j--;
        }
        *(a+j+1) = key;
    }
}

int main(){
    int *arr = (int *)malloc(LEN * sizeof(int));
    memcpy(arr, (int[LEN]){1,-2,5,6,-3,0,-1,4}, LEN * sizeof(int));
    printf("Unsorted Array: ");
    print(arr);
    insertion(arr);
    printf("Sorted Array: ");
    print(arr);
    free(arr);
    return 0;
}
