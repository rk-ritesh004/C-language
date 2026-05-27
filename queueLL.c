#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* f=NULL;
struct Node* r=NULL;
typedef struct Node NODE; 

void insert(int x){
    NODE* ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    ptr->data = x;
    ptr->next=NULL;
    if(r==NULL){
        f=r=ptr;
    }else{
        r->next=ptr;
        r=ptr;
    }
}
void delete(){
    if(f==NULL){
        printf("empty");
        return;
    }
    NODE* temp=f;
    printf("\n deleted=%d\n",temp->data);
    f=f->next;
    if(f==NULL) r=NULL;
    free(temp);
}
void display(){
    if(f==NULL){
        printf("empty");
        return;
    }
    NODE* temp=f;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void main(){
    insert(10);
    insert(20);
    insert(30);
    display();
    delete();
    display();
    insert(40);
    insert(50);
    display();

}