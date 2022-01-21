#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct address{
    char name[50];
    char phone[20];
    char mail[50];
}add;
int main(){
    FILE *f = fopen("address.bin","w+b");
    if (f == NULL){
        printf("Error");
        exit(1);
    }
    add s[100];
    int i,n;
    add x;
    printf("Nhap so phan tu mang address: ");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Nhap thong tin nguoi thu %d: \n",i+1);
        printf("Nhap ten: ");  
        fflush(stdin);
        gets(x.name);
        printf("Nhap sdt: "); 
        fflush(stdin);
        gets(x.phone);
        printf("Nhap email: "); 
        fflush(stdin);
        gets(x.mail);
        fwrite(&x,sizeof(add),1,f);
    }
    fclose(f);
    FILE *f1 = fopen("address.bin","rb");
    FILE *f2 = fopen("addressfind.bin","wb");
    if (f1 == NULL || f2 == NULL){
        printf("error: cannot open address");
        exit(1);
    }
    char arr[100];
    printf("Nhap ten nguoi can tim: ");
    fflush(stdin);
    gets(arr);
    add k;
    while(!feof(f1)){
        fread(&k,sizeof(add),1,f1);
        if (strcmp(k.name,arr) == 0){
            fwrite(&k,sizeof(add),1,f2);
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}