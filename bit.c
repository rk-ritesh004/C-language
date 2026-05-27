#include<stdio.h>
void main(){
    // int arr[]={1,2,3,4,5,6};
    // int newar[]={1,2,3,4,5};
    // int x=0;
    // for(int i=0;i<6;i++){
    //     x=x^arr[i];
    // }
    // int missing=0;
    // for(int i=0;i<6;i++){
    //     missing=x^newar[i];
    // }
    // printf("Missing=%d",missing);
    int num = 20;
    // checking third bit is set or not
    if((num>>2)&1 == 1)
        printf("Bit is set\n");
    else
        printf("not\n");
    int bin[5],i=4;
    while(num>0){
        bin[i]=num&1;
        i--;
        num=num>>1;
    }
    for(int j=0;j<5;j++){
        printf("%d",bin[j]);
    }
 
}