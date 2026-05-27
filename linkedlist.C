#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL;

typedef struct node NODE;

void create();
void insert_first();
void insert_last();
void insert_pos();
void display();
void search();
void delete_first();
void delete_last();
void delete_pos();

int main(){
    int choice;
    while(1){
        printf("\n1.Create\n2.Insert at first\n3.Insert at last\n4.Insert at position\n5.Display\n6.Search\n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: create(); break;
            case 2: insert_first(); break;
            case 3: insert_last(); break;
            case 4: insert_pos(); break;
            case 5: display(); break;
            case 6: search(); break;
            case 7: exit(0);
            default: printf("\nInvalid choice");
        }
    }

}

void create(){
    NODE *ptr,*temp;
    int num;

    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL){
        printf("\nMemory is not allocated");
        return;
    }
    printf("\nEnter a number: ");
    scanf("%d",&num);

    ptr->data=num;
    ptr->next=NULL;

    if(head==NULL)
        head=ptr;
    else{
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=ptr;
    }
}

void insert_first(){
    NODE *ptr;
    int num;

    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL){
        printf("\nMemory is not allocated");
        return;
    }
    printf("\nEnter a number: ");
    scanf("%d",&num);

    ptr->data=num;
    if(head==NULL){
        ptr->next=NULL;
        head=ptr;
    }else{
        ptr->next=head;
        head=ptr;
    }
}

void insert_last(){
    NODE *ptr,*temp;
    int num;

    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL){
        printf("\nMemory is not allocated");
        return;
    }
    printf("\nEnter number: ");
    scanf("%d",&num);

    ptr->data=num;
    ptr->next=NULL;

    if(head==NULL){
        head=ptr;
        return;
    }

    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=ptr;
}

void insert_pos(){
    NODE *ptr,*temp;
    int num,i,pos;

    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL){
        printf("\nMemory not allocated");
        return;
    }

    printf("\nEnter number: ");
    scanf("%d",&num);
    ptr->data=num;
    if(head==NULL){
        ptr->next=NULL;
        head=ptr;
        return;
    }
    printf("\nEnter position: ");
    scanf("%d",&pos);

    if(pos<1){
        printf("\nInvalid position");
        return;
    }

    if(pos==1){
        ptr->next=head;
        head=ptr;
        return;
    }

    temp=head;
    // for(i=1;i<pos-1 && temp!=NULL;i++)
    //     temp=temp->next;
    i=1;
    while(i<pos-1 && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
        printf("\nOut of range");
        return;
    }

    ptr->next=temp->next;
    temp->next=ptr;
}


void display(){
    NODE *temp=head;

    if(head==NULL){
        printf("\nEmpty Linked List");
        return;
    }

    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

void search(){
    NODE *temp=head;
    int num,c=0;

    if(head==NULL){
        printf("\nList is empty");
        return;
    }

    printf("\nEnter number to search: ");
    scanf("%d",&num);

    while(temp!=NULL){
        c++;
        if(temp->data==num){
            printf("\nFOUND at position: %d",c);
            return;
        }
        temp=temp->next;
    }

    printf("\nNOT FOUND");
}
void delete_first(){
    NODE *ptr;
    if(head==NULL){
        printf("\nList is empty");
        return;
    }
    ptr=head;
    if(ptr->next==NULL){
        printf("\nDeleted: %d",ptr->data);
        free(ptr);
        head=NULL;
    }else{
        head=head->next;
        printf("\nDeleted: %d",ptr->data);
        free(ptr);
    }
}
void delete_last(){
    NODE *ptr,*temp;
    if(head==NULL){
        printf("\nList is empty");
        return;
    }
    ptr=head;
    if(ptr->next == NULL){
        printf("\nDeleted: %d",ptr->data);
        free(ptr);
        head=NULL;
    }else{
        while(ptr->next!=NULL){
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        printf("\nDeleted: %d",ptr->data);
        free(ptr);
    }
}
void delete_pos(){
    NODE *ptr,*temp;
    int pos,i=1;
    if(head==NULL){
        printf("\nList is empty");
        return;
    }
    // if(ptr->next==NULL){
    //     printf("%d",ptr->data);
    //     free(ptr);
    //     head=NULL;
    //     return;
    // }
    printf("\nEnter position: ");
    scanf("%d",&pos);
    if(pos<1){
        printf("\nInvalid position");
        return;
    }   
    if(pos==1){
        ptr=head;
        head=head->next;
        printf("\nDeleted: %d",ptr->data);
        free(ptr);
        return;
    }else{
        for(i=1,ptr=head;i<pos && ptr!=NULL;i++){
            temp=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL){
            printf("\nOut of range");
            return; 
        }
        temp->next=ptr->next;
        printf("\nDeleted: %d",ptr->data);
        free(ptr);
    }
}