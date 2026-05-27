#include<stdio.h>
#define Max 5
int q[Max];
int f=-1,r=-1;
void enqueue(int x){
    if(r==Max-1){
        printf("overflow");
        return;
    }
    if(f==-1) f=0;
    q[++r]=x;
}
void dequeue(){
    if(f==-1){
        printf("underflow");
        return;
    }
    int x=q[f];
    printf("deleted = %d\n ",x);
    if(f==r){
        f=r=-1;
    }else{
        f++;
    }
}
void display(){
    if(f==-1){
        printf("queue is empty");
        return;
    }
    for(int i=f;i<=r;i++){
        printf("%d ",q[i]);
    }
}
void main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    enqueue(50);
    display();
    enqueue(55);
}