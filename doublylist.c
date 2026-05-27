#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} NODE;

NODE *head = NULL;
NODE *tail = NULL;

void create(){
    NODE *ptr;
    int num;

    ptr = (NODE*)malloc(sizeof(NODE));
    if(ptr==NULL){
        printf("\nMemory not allocated");
        exit(0);
    }

    printf("\nEnter the data: ");
    scanf("%d",&num);

    ptr->data = num;
    ptr->prev = NULL;
    ptr->next = NULL;

    if(head==NULL){
        head = ptr;
        tail = ptr;
    }
    else{
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
    }
}

void display(){
    NODE *temp=head;
    int c=0;
    if(temp==NULL){
        printf("\nList is empty");
        exit(0);
    }
    while(temp!=NULL){
        c++;
        printf("%d<->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    printf("Number of nodes: %d\n",c);
}
void disreverse(){
    NODE *temp=tail;
    int c=0;
    if(head==NULL){
        printf("\nList is empty");
        exit(0);
    }
    while(temp!=NULL){
        c++;
        printf("%d<->",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
    printf("Number of nodes: %d\n",c);
}
void insert_at_first(){
    NODE *ptr;
    int num;
    ptr = (NODE*)malloc(sizeof(NODE));
    if(ptr==NULL){  
        printf("\nMemory not allocated");
        exit(0);
    }
    printf("\nEnter the data: ");
    scanf("%d",&num);
    ptr->data=num;
    ptr->prev=NULL;
    if(head==NULL){
        head=ptr;
        tail=ptr;
        tail->next=NULL;
    }
    ptr->next=head;
    head->prev=ptr;
    head=ptr;
}
void insert_at_last(){
    NODE *ptr;
    int num;
    ptr = (NODE*)malloc(sizeof(NODE));
    if(ptr==NULL){  
        printf("\nMemory not allocated");
        exit(0);
    }
      printf("\nEnter the data: ");
    scanf("%d",&num);
    ptr->data=num;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        tail=ptr;
        tail->prev=NULL;
    }
    ptr->prev=tail;
    tail->next=ptr;
    tail=ptr;
}
void insert_at_position(){
    NODE *ptr,*temp;
    int num,pos,i=1;
    ptr = (NODE*)malloc(sizeof(NODE));
    if(ptr==NULL){  
        printf("\nMemory not allocated");
        exit(0);
    }
    printf("\nEnter the data: ");
    scanf("%d",&num);
    ptr->data=num;
    ptr->prev=NULL;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        tail=ptr;
        return;
    }
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    temp=head;
    if(pos<1){
        printf("\nInvalid position");
        exit(0);
    }
    if(pos==1){
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
        return;
    }
    while(i<pos-1 && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
        printf("\nPosition out of range");
        exit(0);
    }
    ptr->next = temp->next;
    ptr->prev = temp;

    if(temp->next != NULL){
        temp->next->prev = ptr;
    }
    else{
        tail = ptr;   // update tail if inserted at end
    }
    temp->next = ptr;

}
void delete_first(){
    NODE *ptr;
    if(head==NULL){
        printf("\nList is empty");
        exit(0);
    }
    ptr=head;
    if(head==tail){
        printf("\ndeleted element: %d",ptr->data);
        head=NULL;
        tail=NULL;
        free(ptr);
        return;
    }
    head=head->next;
    head->prev=NULL;
    printf("\ndeleted element: %d",ptr->data);
    free(ptr);
}
void delete_last(){
    NODE *ptr;
    if(tail==NULL){
        printf("\nList is empty");
        exit(0);
    }
    ptr=tail;
    if(head==tail){
    printf("\ndeleted element: %d",ptr->data);
        head=NULL;
        tail=NULL;
        free(ptr);
        return;
    }
    tail=tail->prev;
    tail->next=NULL;
    printf("\ndeleted element: %d",ptr->data);
    free(ptr);
}
void delete_pos(){
    NODE *ptr,*temp;
    int pos,i=1;
    if(head==NULL){
        printf("\nList is empty");
        exit(0);
    }
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    if(pos<1){
        printf("\nInvalid position");
        exit(0);
    }
    if(head==tail){
        printf("\ndeleted element: %d",head->data);
        head=NULL;
        tail=NULL;
        return;
    }
    if(pos==1){
        head=head->next;
        head->prev=NULL;
        printf("\ndeleted element: %d",ptr->data);
        free(ptr);
    }else{
        temp=head;
        while(i<pos-1 && temp!=NULL){
            temp=temp->next;
            i++;
        }
        if(temp==NULL || temp->next==NULL){
            printf("\nPosition out of range");
            exit(0);
        }
        ptr=temp->next;
        temp->next=ptr->next;
        if(ptr->next!=NULL){
            ptr->next->prev=temp;
        }
        if(ptr==tail){
            tail=temp;
        }
        printf("\ndeleted element: %d",ptr->data);
        free(ptr);
    }
}
int main(){
    create();
    insert_at_first();
    insert_at_last();
    insert_at_position();
    display();
    delete_pos();
    display();
    // disreverse();
    return 0;
}
