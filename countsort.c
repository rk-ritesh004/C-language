#include<stdio.h>
void count_sort(int a[],int n){
    int b[n];
    int k=0;
    for(int i=0;i<n;i++){
        if(a[i]>k){
            k=a[i];
        }
    }
    int count[k+1];
    for(int i=0;i<=k;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    for(int i=1;i<=k;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        b[--count[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}
int main(){
    int a[]={6,3,2,1,2,3,6,2,1};
    int n=sizeof(a)/sizeof(a[0]);
    
    printf("\nBefore sort : ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    count_sort(a,n);
    printf("\nAfter sort : ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}