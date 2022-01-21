#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct add{
    char name[20];
    int age;
    char sdt[20];
}add;
void quicksort(add a[],int l,int r){
    int i,j;
    add pivot;
    if (l < r){
        i = l;
        j = r+1;
        pivot = a[l];
        while (i < j){
            do i++;
                while (strcmp(a[i].name,pivot.name) < 0);
            do j--;
                while (strcmp(a[j].name,pivot.name) > 0);
            if (i < j){
                add t;
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        add temp;
        temp = a[l];
        a[l] = a[j];
        a[j] = temp;
        quicksort(a,l,j-1);
        quicksort(a,j+1,r);
    }
}
int main(){
    add a[100];
    int n,i;
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    FILE *f = fopen("addressbook.dat","w+b");
    if (f == NULL){
        printf("Error");
        exit(1);
    }
    for (i=0;i<n;i++){
        printf("Nhap thong tin nguoi thu %d: \n",i+1);
        printf("Nhap ten: ");
        fflush(stdin);
        gets(a[i].name);
        printf("Nhap tuoi: ");
        scanf("%d",&a[i].age);
        printf("Nhap sdt: ");
        fflush(stdin); 
        gets(a[i].sdt);
        fwrite(&a[i],1,sizeof(add),f);
    }
    fclose(f);
    quicksort(a,0,n-1);
    //FILE *f1 = fopen("addressbook.dat","rb");
    FILE *f2 = fopen("addressbookSORT.dat","w+b");
    if ( f2 == NULL){
        printf("Error");
        exit(1);
    }
    fwrite(a,n,sizeof(add),f2);
    /*for (i=0;i<n;i++){
        printf("Thong tin nguoi thu %d: \n",i+1);
        printf("Name: %s\n",a[i].name);
        printf("Age: %d\n",a[i].age);
        printf("Phone: %s\n",a[i].sdt);
    }*/
    
    return 0; 
}
