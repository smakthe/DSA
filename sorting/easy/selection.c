#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 8

void selection(int *a){
    for(int i=0;i<LEN-1;i++){
        int minValue = *(a+i);
        int minIndex = i;
        for(int j=i;j<LEN;j++){
            if(*(a+i)>*(a+j)){
                minValue = *(a+j);
                minIndex = j;
            }
        }
        int temp = *(a+i);
        *(a+i) = *(a+minIndex);
        *(a+minIndex) = temp;
    }
}

void print(int *a){
    for(int i=0;i<LEN;i++){
        printf("%i ",*(a+i));
    }
    puts("");
}

void main(){
    int *arr = (int *)malloc(LEN*sizeof(int));
    memcpy(arr, (int[LEN]){5,1,-6,7,3,0,2,4}, LEN * sizeof(int));
    printf("Unsorted Array: ");
    print(arr);
    selection(arr);
    printf("Sorted Array: ");
    print(arr);
    free(arr);
}
