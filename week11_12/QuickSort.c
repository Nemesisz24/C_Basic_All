#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct add{
    char name[30];
    char phone[10];
    char email[50];
} add;
void quicksort(add x[],int l, int r){
    int i,j;
    char pivot[30];
    add temp;
    if (l < r){
        i = l;
        j = r + 1;
        strcpy(pivot,x[l].name);
        do i++;
            while (strcmp(x[i].name,pivot) < 0);
        do j--;
            while (strcmp(x[j].name,pivot) > 0);
        if (i < j){
            temp = x[i];
            x[i] = x[j];
            x[j] = temp;
        }
        quicksort(x,l,j-1);
        quicksort(x,j+1,r);
    }
}
int main(){
    FILE *f1 = fopen("addbook.dat","w+b");
    if (f1 == NULL){
        printf("Error: Could not open file");
        exit(1);
    }
    add arr[100];
    int i,n;
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Nhap tt nguoi thu %d: \n",i);
        printf("Nhap ten: ");
        fflush(stdin);
        gets(arr[i].name);
        printf("Nhap sdt: ");
        fflush(stdin);
        gets(arr[i].phone);
        printf("Nhap email: ");
        fflush(stdin);
        gets(arr[i].email);
    }
    quicksort(arr,0,n-1);
    for (i=0;i<n;i++){
        printf("%s ",arr[i].name);
        fwrite(&arr[i],1,sizeof(add),f1);
    }
    fclose(f1);
    return 0;
}