#include<stdio.h>
void display(int[],int);
void rev(int a[],int s){
    for(int i = 0; i<s/2;i++){
        int t = a[i];
        a[i]=a[s-i-1];
        a[s-i-1] = t;
    }
    display(a,7);
}
void display(int arr[],int s){
    for(int i=0;i<s;i++){
        printf("%d\t",arr[i]);
    }
}
void main(){
    int arr[]={1,2,3,4,5,6,7};
    rev(arr,7);
   
}