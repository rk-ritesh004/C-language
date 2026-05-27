#include<stdlib.h>
#include<stdio.h>
struct node{
    int coeff;
    int exp;
    struct node *next;
};
struct node* insert(struct node* head,int co,int ex);
struct node* create(struct node* head){
    int coreff,exp,n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter Coefficient and exponent: ");
        scanf("%d%d",&coreff,&exp);
        head = insert(head,coreff,exp);
    }
    return head;
}
struct node* insert(struct node* head,int co,int ex){
    struct node *ptr,*temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->coeff=co;
    ptr->exp=ex;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        return head;
    }else if(ex>head->exp){
        ptr->next=head;
        head=ptr;
    }
    else{
        temp=head;
        while(temp->next!=NULL && temp->next->exp>ex){
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next=ptr;
    }
    return head;
}
void display(struct node* head){
    if(head==NULL){
        printf("Empty");
        return;
    }
    struct node* temp=head;

    while(temp!=NULL){
        printf("%dx^%d ",temp->coeff,temp->exp);
        temp=temp->next;
        if(temp!=NULL){
            printf("+ ");
        }else{
            printf("\n");
        }
    }
}
void addpoly(struct node* head1,struct node* head2){
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    while(ptr1 !=NULL && ptr2 !=NULL){
        if(ptr1->exp == ptr2->exp){
            head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->exp);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }else if(ptr1->exp > ptr2->exp){
            head3=insert(head3,ptr1->coeff,ptr1->exp);
            ptr1=ptr1->next;
        }else if(ptr1->exp < ptr2->exp){
            head3=insert(head3,ptr2->coeff,ptr2->exp);
            ptr2=ptr2->next;
        }
    }
    while(ptr1 != NULL){
        head3=insert(head3,ptr1->coeff,ptr1->exp);
        ptr1=ptr1->next;
    }
    while(ptr2 != NULL){
        head3=insert(head3,ptr2->coeff,ptr2->exp);
        ptr2=ptr2->next;
    }
    display(head3);
}
void multiply(struct node* head1, struct node* head2){
     struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    while(ptr1 != NULL){
        while(ptr2 != NULL){
            int co = ptr1->coeff*ptr2->coeff;
            int ex = ptr1->exp+ptr2->exp;
            head3 = insert(head3,co,ex);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    display(head3);
}
int  main(){
    struct node* head=NULL;
    head=create(head);
    printf("Polynomial: ");
    display(head);
    struct node* head2=NULL;
    head2=create(head2);
    printf("Polynomial 2: ");
    display(head2);
    printf("Sum: ");
    addpoly(head, head2);
    multiply(head,head2);
    return 0;

}