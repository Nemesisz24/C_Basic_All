#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct add{
    char name[20];
    int age;
    char phone[20];
} add;
void merge(add a[],int l,int m,int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    add a1[100],a2[100];
    int i,j;
    for (i=0;i<n1;i++) 
        a1[i] = a[l+i];
    for (i=0;i<n2;i++)
        a2[i] = a[m+1+i];
    i = 0;
    j = 0;
    int k = l;
    while (i < n1 && j < n2){
        if (strcmp(a1[i].name,a2[j].name) < 0){
            a[k] = a1[i];
            i++;k++;
        }
        else if (strcmp(a1[i].name,a2[j].name) > 0){
            a[k] = a2[j];
            j++;k++;
        }
    }
    while (i < n1){
            a[k] = a1[i];
            k++;i++;
    }
    while (j < n2){
        a[k] = a2[j];
        k++;j++;
    }
}
void mergesort(add a[],int l,int r){
    int m;
    if (l < r){
        m = (l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main(){
    add a[100];
    int n,i;
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("nhap thong tin nguoi thu %d: \n",i+1);
        printf("Nhap ten: ");
        fflush(stdin);
        gets(a[i].name);
        printf("Nhap tuoi: ");
        scanf("%d",&a[i].age);
        printf("Nhap std: ");
        fflush(stdin);
        gets(a[i].phone);
    }
    mergesort(a,0,n-1);
    printf("Result: \n");
    for (i=0;i<n;i++){
        printf("Name: %s\n",a[i].name);
        printf("Age: %d\n",a[i].age);
        printf("Phone: %s\n",a[i].phone);
    }
    return 0; 
}