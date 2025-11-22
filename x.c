#include<stdio.h>
#include<conio.h>
int main(){
    int r = 5;
    for(int i =1;i<=r;i++){
        for(int j = 1;j<=r*2-1;j++){
            if(j == i || (i+j)==10)
                printf("%d",i);
            else
                printf(" ");
        }
        printf("\n");
    }
    for(int i = r-1;i>0;i--){
        for(int j=1;j<=r*2-1;j++){
            if(j == i || (i+j)==10)
                printf("%d",i);
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}