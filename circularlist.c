#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL,*tail=NULL;
typedef struct node NODE;
void create()
{
    NODE *ptr;
    int num;
    ptr=malloc(sizeof(NODE));
    if(ptr==NULL){
        printf("\nMemory is not allocated");
        exit(0);
    }
    printf("\nEnter a number: ");
    scanf("%d",&num);
    ptr->data=num;
    if(head==NULL){
        head=ptr;
        tail=ptr;
        ptr->next=head;
    }else{
        tail->next=head;
        tail->next=ptr;
        tail=ptr;
    }
}
void display(){
    NODE *temp;
    if(head==NULL){
        printf("\nList is empty");
        exit(0);
    }
    temp=head;
    // while(temp->next!=head)
    while(temp!=tail){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
}
void insert_at_first(){
    NODE *ptr;
    int num;
    ptr=malloc(sizeof(NODE));
    if(ptr==NULL){        
        printf("\nMemory is not allocated");
        exit(0);
    }
    printf("\nEnter a number: ");
    scanf("%d",&num);
    ptr->data=num;
    if(head==NULL){
        head=ptr;
        tail=ptr;
        ptr->next=head;
    }else{
        ptr->next=head;
        head=ptr;
        tail->next=head;
    }
}
void insert_at_last(){
    NODE *ptr;
    int num;
    ptr=malloc(sizeof(NODE));
    if(ptr==NULL){        
        printf("\nMemory is not allocated");
        exit(0);
    }
    printf("\nEnter a number: ");
    scanf("%d",&num);
    ptr->data=num;
    if(head==NULL){
        head=ptr;
        tail=ptr;
        ptr->next=head;
    }else{
        tail->next=ptr;
        tail=ptr;
        tail->next=head;
    }
}
void insert_at_position(){
    NODE *ptr,*temp;
    int num,pos,i=1;
    ptr=malloc(sizeof(NODE));
    if(ptr==NULL){        
        printf("\nMemory is not allocated");
        exit(0);
    }
    printf("\nEnter a number: ");
    scanf("%d",&num);
    ptr->data=num;
    printf("\nEnter a position: ");
    scanf("%d",&pos);
    if(pos==1){
        ptr->next=head;
        head=ptr;
        tail->next=ptr;
        
    }else{
        temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        ptr->next=temp->next;
        temp->next=ptr;
        if(temp==tail){
            tail=ptr;
        }
    }
}
void delete_first(){
    NODE *ptr;
    ptr=head;
    if(head==NULL){
        printf("\nEmpty");
        exit(0);
    }
    if(head==tail){
        printf("\ndeleted=%d",ptr->data);
        free(ptr);
        head=tail=NULL;
    }
    head=head->next;
    printf("\ndeleted=%d\n",ptr->data);
    tail->next=head;
    free(ptr);
}
void delete_last(){
    NODE *ptr,*temp;
    ptr=head;
    if(head==NULL){
        printf("\nEmpty");
        exit(0);
    }
    if(head==tail){
        printf("\ndeleted=%d",ptr->data);
        free(ptr);
        head=tail=NULL;
    }else{
        while(ptr->next!=head){
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=head;
        tail=temp;
        printf("\ndeleted=%d\n",ptr->data);
        free(ptr);
    }
}
void delete_pos(){
    NODE *ptr, *temp;
    int pos, i = 1;

    if(head == NULL){
        printf("\nEmpty");
        return;
    }

    printf("\nEnter position: ");
    scanf("%d", &pos);

    if(pos < 1){
        printf("\nInvalid");
        return;
    }

    ptr = head;

    if(head == tail && pos == 1){
        printf("\nDeleted = %d\n", ptr->data);
        free(ptr);
        head = tail = NULL;
        return;
    }
    if(pos == 1){
        head = head->next;
        tail->next = head;
        printf("\nDeleted = %d\n", ptr->data);
        free(ptr);
        return;
    }

    while(i < pos - 1 && ptr->next != head){
        ptr = ptr->next;
        i++;  
    }

    if(ptr->next == head){
        printf("\nOut of range");
        return;
    }

    temp = ptr->next;

    if(temp == tail){
        tail = ptr;
    }

    ptr->next = temp->next;
    printf("\nDeleted = %d\n", temp->data);
    free(temp);
}

// int main()
// {
    
//     create();
//     insert_at_first();
//     insert_at_last();
//     display();
//     delete_pos();
//     display();
//     return 0;
// }
int main(){
    int choice;
    while(1){
        printf("\n1.Create\n2.Insert at first\n3.Insert at last\n4.Insert at position\n5.Display\n6.Search\n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: create(); break;
            case 2: insert_at_first(); break;
            case 3: insert_at_last(); break;
            case 4: insert_at_position(); break;
            case 5: display(); break;
            case 6: delete_first(); break;
            case 7: delete_last(); break;
            case 8: delete_pos(); break;
            case 9: exit(0);
            default: printf("\nInvalid choice");
        }
    }

}