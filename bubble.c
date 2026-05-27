#include<stdio.h>
void main(){
    int n=5;
    int arr[]={1,2,5,6,7};
    // for(int i=1;i<n;i++){
    //     for(int j=1;j<=n-i;j++){
    //         if(arr[j]<arr[j-1]){
    //             int t=arr[j];
    //             arr[j] = arr[j-1];
    //             arr[j-1]=t;
    //         }
    //     }
    // }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n-i;j++){
            if(arr[i]>arr[j]){
                int t=arr[i];
                arr[i] = arr[j];
                arr[j]=t;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}