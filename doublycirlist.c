#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
struct node *head=NULL;
struct node *tail=NULL;
void create(){
    NODE *ptr;
    int n;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL){
        printf("\nMemory not allocated");
        exit(0);
    }
    printf("\nEnter num:");
    scanf("%d",&n);
    ptr->data=n;
    if(head==NULL){
        ptr->next=ptr;
        ptr->prev=ptr;
        head=tail=ptr;
    }else{
        ptr->next=head;
        head=ptr;
        head->prev=tail;
        tail->next=head;
    }
}
void display(){
    NODE *temp;
    if(head==NULL){
        printf("\nList is empty");
        return;
    }else{
        temp=head;
        printf("\nElements in the list:");
        while(temp!=tail){
            printf("%d-> ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}
void insert_at_first(){
    NODE *ptr;
    int n;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL){
        printf("\nMemory not allocated");
        exit(0);
    }
    printf("\nEnter num:"); 
    scanf("%d",&n);
    ptr->data=n;
    if(head==NULL){
        ptr->next=ptr;
        ptr->prev=ptr;
        head=tail=ptr;
    }else{
        ptr->next=head;
        head=ptr;
        tail->next=head;
        head->prev=tail;
    }
}
void insert_at_last(){
    NODE *ptr;
    int n;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL){
        printf("\nMemory not allocated");
        exit(0);
    }
    printf("\nEnter num:");
    scanf("%d",&n);
    ptr->data=n;
    if(head==NULL){
        ptr->next=ptr;
        ptr->prev=ptr;
        head=tail=ptr;
    }else{
        tail->next=ptr;
        ptr->prev=tail;
        tail=ptr;
        tail->next=head;
        head->prev=tail;
    }
}
// void insert_at_pos(){
//     NODE *ptr,*temp;
//     int n,pos,i=1;
//     ptr=(NODE*)malloc(sizeof(NODE));
//     if(ptr==NULL){
//         printf("\nMemory not allocated");
//         exit(0);
//     }
//     printf("\nEnter num:");
//     scanf("%d",&n);
//     ptr->data=n;
//     if(head==NULL){
//         ptr->next=ptr;
//         ptr->prev=ptr;
//         head=tail=ptr;
//         return;
//     }
//     printf("\nEnter position:");
//     scanf("%d",&pos);
//     if(pos<1){
//         printf("\nInvalid position");
//         return;
//     }
//     if(pos==1 && head!=NULL){
//         ptr->next=head;
//         head=ptr;
//         tail->next=head;
//         head->prev=tail;
//     }else{
//         temp=head;
//         while(i<pos-1 && temp!=tail){
//             temp=temp->next;
//             i++;
//         }
//         if(temp==tail){
//             tail->next=ptr;
//             ptr->prev=tail;
//             tail=ptr;
//             tail->next=head;
//             head->prev=tail;
//         }else{
//             ptr->next=temp->next;
//             temp->next=ptr;
//             ptr->prev=temp;
//             ptr->next->prev=ptr;
//         }
//     }
// }
void insert_at_pos(){
    NODE *ptr,*temp;
    int n,pos,i=1;

    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL){
        printf("\nMemory not allocated");
        exit(0);
    }

    printf("\nEnter num:");
    scanf("%d",&n);
    ptr->data=n;

    if(head==NULL){
        if(pos==1){
            ptr->next=ptr;
            ptr->prev=ptr;
            head=tail=ptr;
        }else{
            printf("\nInvalid position");
        }
        return;
    }

    printf("\nEnter position:");
    scanf("%d",&pos);

    if(pos<1){
        printf("\nInvalid position");
        free(ptr);
        return;
    }

    // 🔹 Insert at beginning
    if(pos==1){
        ptr->next=head;
        // ptr->prev=tail;
        // head->prev=ptr;
        // tail->next=ptr;
        // head=ptr;
        head->prev=ptr;head=ptr;
        tail->next=head;
        head->prev=tail;
        return;
    }

    temp=head;

    while(i<pos-1){
        temp=temp->next;
        if(temp==head){
            printf("\nInvalid position");
            free(ptr);
            return;
        }
        i++;
    }

    // 🔹 Insert at end
    if(temp==tail){
        ptr->next=head;
        ptr->prev=tail;
        tail->next=ptr;
        head->prev=ptr;
        tail=ptr;
    }
    else{
        ptr->next=temp->next;
        ptr->prev=temp;
        temp->next->prev=ptr;
        temp->next=ptr;
    }
}
void delete_first(){
    NODE *ptr;
    if(head==NULL){
        printf("\nList is empty");
        return;
    }
    if(head==tail){
        printf("\nDeleted element is:%d",head->data);
        free(head);
        head=tail=NULL;
    }else{
        ptr=head;
        head=head->next;
        tail->next=head;
        head->prev=tail;
        printf("\nDeleted element is:%d",ptr->data);
        free(ptr);
    }
}
void delete_last(){
    NODE *ptr;
    if(head==NULL){
        printf("\nList is empty");
        return;
    }
    if(head==tail){
        printf("\nDeleted element is:%d",head->data);
        free(head);
        head=tail=NULL;
    }else{
        ptr=tail;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        printf("\nDeleted element is:%d",ptr->data);
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
    if(head==tail){
        printf("\nDeleted element is:%d",head->data);
        free(head);
        head=tail=NULL;
        return;
    }
    
    printf("\nEnter position:");
    scanf("%d",&pos);
    if(pos<1){
        printf("\nInvalid position");
        return;
    }
    if(pos==1){
        ptr=head;
        head=head->next;
        tail->next=head;
        head->prev=tail;
        printf("\nDeleted element is:%d",ptr->data);
        free(ptr);
    }else{
        temp=head;
        while(i<pos-1 && temp!=tail){
            temp=temp->next;
            i++;
        }
        if(temp==tail){
            printf("\nInvalid position");
            return;
        }
        ptr = temp->next;

    if(ptr == tail){
        tail = temp;
        tail->next = head;
        head->prev = tail;
    }
    else{
        temp->next = ptr->next;
        ptr->next->prev = temp;
    }

    printf("\nDeleted element is:%d",ptr->data);
    free(ptr);
    }
}
int main(){
    create();
    insert_at_first();
    insert_at_last();
    insert_at_pos();
    display();
    delete_pos();
    display();
    return 0;
}