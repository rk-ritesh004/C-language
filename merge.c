#include<stdio.h>
void merge(int arr[],int l,int m,int r){
    int i=l,j=m+1,k=0;

    int merged[r-l+1];
    while(i<=m && j<=r){
        if(arr[i]<arr[j]){
            merged[k]=arr[i];
            k++;
            i++;
        }else{
            merged[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=m){
        merged[k]=arr[i];
        k++;
        i++;
    }
    while(j<=r){
        merged[k]=arr[j];
        k++;
        j++;
    }
    for(int a=0;a<r-l+1;a++){
        arr[l+a]=merged[a];
    }
}
void divide(int arr[],int l,int r){
    if(l<r){
        // for(int i=l;i<=r;i++){
        //     printf("%d",arr[i]);
        // }
        // printf("\n");
        int mid =(l+r)/2;
        divide(arr,l,mid);
        divide(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

void main(){
    int arr[] = {2,8,6,3,4,1,7};
    divide(arr,0,6);
    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
}
