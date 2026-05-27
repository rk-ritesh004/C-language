#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node NODE;
struct Node* top=NULL;

void insert(int x){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = x;
    newNode->next=top;
    top=newNode;
}
void push(int x){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if(newNode == NULL){
        printf("Memory not allocated");
        exit(0);
    }else if(top == NULL){
        newNode->data=x;
        newNode->next=NULL;
        top=newNode;
    }else{
        newNode->data = x;
        newNode->next = top;
        top=newNode;
    }
}
void pop(){
    if(top==NULL){
        printf("underflow\n");
        exit(0);
    }
    NODE* temp=top;
    printf("Popped = %d",temp->data);
    top=top->next;
    free(temp);
}
void peek(){
    if(top==NULL){
        printf("\nStack is empty\n");
        exit(0);
    }
    printf("\nTop = %d",top->data);
}
void display(){
    NODE* temp;
    if(top==NULL){
        printf("Stack is empty");
        exit(0);
    }
    temp=top;
    printf("\nStack element\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void main(){
    push(20);
    push(10);
    push(30);
    insert(40);
    pop();
    peek();
    display();
    pop();
    display();
}