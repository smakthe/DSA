#include<stdio.h>
#define NUM 10

int fib(int n){
    if(n==0||n==1) return n;
    return fib(n-1)+fib(n-2);
}

void main(){
    for(int i=0;i<NUM;i++){
        printf("%i ",fib(i));
    }
    puts("");
}
