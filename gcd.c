#include<stdio.h>
int gcd(int a, int b)
{
    if(b==0)
    return a;
    return gcd(b, a%b);
}
void main(){
    int a=10, b=15;
    printf("GCD of %d and %d is %d\n", a, b, gcd(a,b));
}