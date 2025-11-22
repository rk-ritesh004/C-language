#include<stdio.h>
int sum(int n){
    if(n<10)
        return n;
    return sum(n/10 + n%10);
}
void main(){
    int number;
    printf("Enter a number: ");
    scanf("%d",&number);
    int result = sum(number);
    printf("Sum of digits: %d\n", result);
}