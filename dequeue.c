#include<stdio.h>
#define Max 5
int dq[Max];
int f=-1,r=-1;
void insert_rear(int x){
    if(r==Max-1){
        printf("Overflow\n");
        return;
    }
    if(f==-1) f=0;
    dq[++r]=x;
}
void delete_front(){
    if(f==-1){
        printf("underflow");
        return;
    }
    int x = dq[f];
    printf("deleted=%d\n",x);
    if(f==r){
        f=r=-1;
    }else{
        f++;
    }
}
void insert_fr(int x){
    if(f==0){   
        printf("full\n");
        return;
    }
    else{
        f--;
    }
    dq[f]=x;
}
void delete_r(){
    if(f==-1){
        printf("Queue is empty");
        return;
    }
    int x= dq[r];
    printf("deleted=%d\n",x);
    if(f==r){
        f=r=-1;
    }else{
        r--;
    }
}
void display(){
    if(f==-1){
        printf("queue is empty");
        return;
    }
    printf("\nQueue element\n");
    for(int i=f;i<=r;i++){
        printf("%d ",dq[i]);
    }
}
void main(){
    // insert_fr(10);
    // insert_rear(20);
    // insert_fr(30);
    // display();
    // delete_r();
    // delete_front();
    // display();
    insert_rear(10);
    insert_rear(20);
    insert_rear(30);
    insert_rear(40);
    insert_rear(50);
    display();
    delete_front();
    display();
    insert_fr(5);
    display();
}