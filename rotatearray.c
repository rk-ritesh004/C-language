#include<stdio.h>
int rotateright(int arr[],int n,int p){
   
    for(int i = 0;i<2;i++){
         int l = arr[n-1];
        for(int j = n-1;j>0;j--){
            arr[j]=arr[j-1];
        }
       arr[0] = l;
    }
}
int rotateleft(int arr[],int n,int p){
   
    for(int i = 0;i<2;i++){
         int f = arr[0];
        for(int j = 0;j<n-1;j++){
            arr[j] = arr[j+1]; 
        }
       arr[n-1] = f;
    }

}

void main(){
    int arr[5];
    printf("Enter elements\n");
    for(int i = 0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    rotateleft(arr,5,2);
    printf("Rotated\n");
     for(int i = 0;i<5;i++){
        printf("%d",arr[i]);
    }
}