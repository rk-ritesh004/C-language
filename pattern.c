#include<stdio.h>
void main()
{
    int i,j,k,r=5;
    for(i = 1;i<=r;i++){
        for(j = 1;j<i;j++){
            printf(" ");
        }
        for(j = 1;j<=r-(i-1);j++){
            printf("%d",j);
        }
        for(j = r-(i-1)-1;j>0;j--){
            printf("%d",j);
        }
        printf("\n");
    }
    for(i = r-1;i>0;i--){
        for(j = 1;j<i;j++){
            printf(" ");
        }
        for(j =1;j<=r-(i-1);j++){
            printf("%d",j);
        }
        for(j=r-(i-1)-1;j>0;j--){
            printf("%d",j);
        }
        printf("\n");
    }
}