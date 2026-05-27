#include<stdio.h>
void dos(int n){
    if(n>50)
        return;
    printf("%d ",n);
    dos(n+10);
}
void main(){
    int a=10;
    dos(a);
}b