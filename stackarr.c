#include<stdio.h>
#include<stdlib.h>
#define Max 5
int st[Max];
int top=-1;
void push(int x){
    if(top==Max-1){
        printf("Overflow\n");
        exit(0);
    }
    st[++top]=x;
}
void pop(){
    if(top==-1){
        printf("Underflow\n");
        exit(0);
    }
    printf("Popped = %d\n", st[top--]);
}
int peek(){
    if(top!=-1){
        printf("Top= %d",st[top]);
    }else{
        printf("stack is empty");
    }
}
void display(){
    if(top==-1){
        printf("Satck is empty");
        exit(0);
    }
    printf("\nstack element\n");
    while(top!=-1){
        printf("%d ",st[top--]);
    }
}
void main(){
    push(20);
    push(10);
    push(30);
    push(40);
    push(50);
    pop();
    peek();
    display();
    
}