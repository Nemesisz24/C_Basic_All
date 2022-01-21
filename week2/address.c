#include<stdio.h>
#define max 100
typedef struct add{
    char name[max];
    char sdt[max];
    char email[max];
} add;
int main(){
    add s[max];
    int i;
    for (i=0;i<2;i++){
        printf("Nhap thong tin nguoi thu %d\n",i+1);
        printf("Nhap ten:");
        gets(s[i].name);
        fflush(stdin);
        printf("Nhap sdt:");
        gets(s[i].sdt);
        fflush(stdin);
        printf("Nhap email:");
        gets(s[i].email);
    }
    FILE *f1=fopen("add1.dat","w+b");
    if (f1==NULL){
        printf("Loi mo file: ");
        return 1;
    }
    fwrite(s,sizeof(add),3,f1);
    fclose(f1);
    FILE *f2=fopen("add1.dat","r+b");
    add a1;
    fread(&a1,sizeof(a1),1,f2);
    printf("So dien thoia la: %s",a1.sdt);
    fclose(f2);
    return 0;
}