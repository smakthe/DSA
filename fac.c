#include<stdio.h>

int fac(int n){
    if(n==0||n==1) return 1;
    return n*fac(n-1);
}

void main(){
    int n;
    printf("Enter the value: ");
    scanf("%i",&n);
    printf("%i! = %i\n",n,fac(n));
}
