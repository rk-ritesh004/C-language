#include<stdio.h>

int sod(int n){
    if(n == 0)
    return 0;
    return (n % 10 + sod(n / 10));
}
void main(){
    int number;
    printf("Enter a number: ");
    scanf("%d",&number);
    int result = sod(number);
    printf("Sum of digits: %d\n", result);
}