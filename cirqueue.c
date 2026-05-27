#include<stdio.h>
#define Max 5
int cq[Max];
int f=-1,r=-1;
void insert(int x){
    if(f==0 && r==Max-1){
        printf("full");
        return;
    }
    if(f==-1){
        f=0;
    }
    r=(r+1)%Max;
    cq[r]=x;
}
void delete(){
    if(f==-1){
        printf("Empty");
        return;
    }
    printf("deleted = %d\n",cq[f]);
    if(f==r){
        f=r=-1;
    }else{
        f=(f+1)%Max;
    }
}
void display(){
    if(f==-1){
        printf("Empty");
        return;
    }
    printf("\nElements\n");
    for(int i=f;i<=r;i++){
        printf("%d ",cq[i]);
    }
    if(f>r){
        for(int i=f;i<Max;i++){
            printf("%d ",cq[i]);
        }
        for(int i=0;i<=r;i++){
            printf("%d ",cq[i]);
        }
    }
}
void main(){
    insert(10);
    insert(20);
    insert(30);
    display();
    delete();
    display();
    insert(10);
    insert(50);
    display();
    insert(55);
    display();
}