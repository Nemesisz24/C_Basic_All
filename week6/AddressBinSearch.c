#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct add{
    char name[30];  
    int age;
    char email[50];
} add;
int binsearch(add a[],int n, char name[]){
    int l,r,mid;
    l=0;
    r=n-1;
    while (l < r){
        mid = (l+r)/2;
        if (strcmp(a[mid].name,name)==0)
            return mid;
        else if (strcmp(a[mid].name,name) > 0)
            r = mid -1;
        else if (strcmp(a[mid].name,name) < 0)  
            l = mid + 1;    
    }
    return -1;
}
int main(){
    add s[100];
    int i,n;
    char name[100];
    FILE *f1 = fopen("addressbinsearch.dat","w+b");
    if (f1 == NULL){
        printf("Error opening address");
        exit(1);
    }
    printf("Nhap so phan tu cua mang address: ");
    scanf("%d",&n);
    add x;
    for (i=0;i<n;i++){
        printf("Nhap thong tin nguoi thu %d: \n",i);
        printf("Nhap ten: ");
        fflush(stdin);
        gets(x.name);
        printf("Nhap tuoi:");
        scanf("%d",&x.age);
        printf("Nhap email: ");
        fflush(stdin);
        gets(x.email);
        fwrite(&x,sizeof(add),1,f1);
    }
    fclose(f1);
    FILE *f2 = fopen("addressbinsearch.dat","rb");
    FILE *f3 = fopen("addressBinSearchResult.dat","w+b");
    if (f2 == NULL){
        printf("Error");
        exit(1);
    }
    if (f3 == NULL){
        printf("Error");
        exit(1);
    }
    fread(s,sizeof(add),n,f2);
    printf("Nhap ten muon tim kiem: ");
    fflush(stdin);
    gets(name);
    int kq = binsearch(s,n,name); 
    printf("Thong tin nguoi can tim:\n Ten: %s\n Tuoi: %d\n Email: %s\n",s[kq].name,s[kq].age,s[kq].email);
    fwrite(&s[kq],sizeof(add),1,f3);
    fclose(f2);
    fclose(f3);
    return 0;
}