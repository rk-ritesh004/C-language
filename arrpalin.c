#include<stdio.h>
int palindrome(int a[],int n){
    for(int i = 0;i<n/2;i++)
        if(a[i] != a[n-i-1])
            return 0;
    return 1;
    
}
void main(){
    int arr[]={1,2,3,2,1};
    if(palindrome(arr,5))
        printf("Palindrome");
    else
        printf("Not");
}