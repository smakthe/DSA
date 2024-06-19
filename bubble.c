#include<stdio.h>
#include<stdlib.h>
#define LEN 5

void bubble(int *a){
    for(int i=0;i<LEN;i++){
        for(int j=0;j<LEN-i-1;j++){
            if(*(a+j)>*(a+j+1)){
                int temp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1) = temp;
            }
        }
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
    *arr = 22;
    *(arr+2) = 54;
    *(arr+4) = -72;
    printf("Unsorted Array: ");
    print(arr);
    bubble(arr);
    printf("Sorted Array: ");
    print(arr);
}
