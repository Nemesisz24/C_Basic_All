#include<stdio.h>
#include<stdlib.h>
typedef struct address{
    char name[30]; 
    int age;
    char gmail[50];
} add;
int main(){
    int i,n;
    add x;
    FILE *f1 = fopen("address.bin","w+b");
    if (f1 == NULL){
        printf("Loi mo file !");
        return 1;
    }
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Nhap thong tin nguoi thu %d: \n",i+1);
        printf("Nhap ten: ");
        fflush(stdin); 
        gets(x.name);
        printf("Nhap tuoi: "); 
        scanf("%d",&x.age);
        printf("Nhap gmail: ");
        fflush(stdin);
        gets(x.gmail);
        fwrite(&x, sizeof(add),1,f1);
    }   
    fclose(f1);
    /*FILE *f2 = fopen("adress.bin", "rb");
    add k;
    if (f2 == NULL){
        printf("Loi moi file!");
        exit(1);
    }
        add k3[3];
        fread(&k3, sizeof(add),3,f2);
        for (i=0;i<3;i++){
            printf("Ten nguoi dung: %s\n",k3[i].name);
        }
    fclose(f2);*/
    return 0;
}