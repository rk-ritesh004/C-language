#include<stdio.h>
void input(int A[10][10],int r,int c){
    int i,j;
    for(i = 0;i<r;i++){
        for(j = 0;j<c;j++){
            scanf("%d",&A[i][j]);
        }
    }
}
void display(int A[10][10],int r,int c){
    int i,j;
    for(i = 0;i<r;i++){
        for(j = 0;j<c;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}
void sumofmatrix(){
    int r,c,sum=0;
    int A[10][10];
    printf("\nEnter row and col:");
    scanf("%d %d",&r,&c);
    input(A,r,c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            sum = sum + A[i][j];
        }
    }
    printf("Sum of elements of matrix is %d",sum);
}
void sumoftwomatrix(){
    int r,c,i,j;
    int A[10][10],B[10][10],R[10][10];
    printf("\nEnter row and col:");
    scanf("%d %d",&r,&c);
    printf("Enter elements of first matrix:");
    input(A,r,c);
    printf("Enter elements of second matrix:");
    input(B,r,c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            R[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("Resultant matrix after addition is:\n");
    display(R,r,c);
}
void multiply(){
    int r1,c1,r2,c2,i,j,k;
    int A[10][10],B[10][10],R[10][10];
    printf("\nEnter rows and columns of first matrix:");
    scanf("%d %d",&r1,&c1);
    printf("Enter rows and columns of second matrix:");
    scanf("%d %d",&r2,&c2);
    if(c1 != r2){
        printf("Matrix multiplication not possible");
        return;
    }
    printf("Enter elements of first matrix:");
    input(A,r1,c1);
    printf("Enter elements of second matrix:");
    input(B,r2,c2);
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            R[i][j] = 0;
            for(k=0;k<c1;k++){
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("Resultant matrix after multiplication is:\n");
    display(R,r1,c2);
}
void transpose(){
    int r,c,i,j;
    int A[10][10],T[10][10];
    printf("\nEnter row and col:");
    scanf("%d %d",&r,&c);
    input(A,r,c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            T[j][i] = A[i][j];
        }
    }
    printf("Transpose of matrix is:\n");
    display(T,c,r);
}
void primarydiag(){
    int r,c,i,j,sum=0;
    int A[10][10];
    printf("\nEnter row and col:");
    scanf("%d %d",&r,&c);
    input(A,r,c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(i == j){
                sum = sum + A[i][j];
            }
        }
    }
    printf("Sum of primary diagonal is %d",sum);
}
void secdiag(){
    int r,c,i,j,sum=0;
    int A[10][10];
    printf("\nEnter row and col:");
    scanf("%d %d",&r,&c);
    input(A,r,c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if((i + j) == (c - 1)){
                sum = sum + A[i][j];
            }
        }
    }
    printf("Sum of secondary diagonal is %d",sum);
}
int main(){
    int choice;
    char ch;
    do{
        printf("Select Operations on Matrix\n");
        printf("\n 1.Sum of elements of matrix.");
        printf("\n 2.Sum of two matrix.");
        printf("\n 3.Multiplication two of matrix.");
        printf("\n 4.Transpose of matrix.");
        printf("\n 5.Sum of primary diagonal of matrix.");
        printf("\n 6.Sum of secondary diagonal of matrix.\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            sumofmatrix();
            break;
        case 2:
            sumoftwomatrix();
            break;
        case 3:
            multiply();
            break;
        case 4:
            transpose();
            break;
        case 5:
            primarydiag();
            break;
        case 6:
            secdiag();
            break;
        default:
            printf("Invalid Choice");
            break;
        }
        printf("\nDo you want to continue(y/n):");
        scanf(" %c",&ch);
    }while(ch == 'Y' || ch == 'y');
    return 0;
}