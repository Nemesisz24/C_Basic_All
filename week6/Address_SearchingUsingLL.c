#include<stdio.h>
#include<stdlib.h>
typedef struct address{
    char name[30];
    int age;
    char email[50];
}add;
typedef struct node{
    add data;
    struct node *next;
} node;
node *head;
node *Cnode(add x){
    node *p = (node *)malloc(sizeof(node));
    p->data = x;  
    p->next = NULL;
    return p;
}
void addnode(node *p){
    node *k;
    if (head == NULL)
        head = p;
        else{
            for (k=head;k->next != NULL;k=k->next)
                ;;
            k->next = p;
        }
}
void findnode(int x){
    node *k,*k1;
    for (k=head;k->next != NULL;k=k->next){
        if (k->data.age == x)
            break;
    }
    k1 = head;
    while(k1->next != k)
        k1=k1->next;
    k1->next = k->next;
    k->next = head;
    head =k;
}
int main(){
    add x;
    int i,n;
    head = NULL;
    FILE *f1 = fopen("add2.bin","w+b");
    if (f1 == NULL){
        printf("Error");
        exit(1);
    }
    printf("Nhap so phan tu can them: ");
    scanf("%d",&n); 
    for (i=0;i<n;i++){
        printf("Nhap thong tin nguoi thu %d: \n",i+1);
        printf("Nhap ten: ");
        fflush(stdin);
        gets(x.name);
        printf("Nhap tuoi: ");
        scanf("%d",&x.age);
        printf("Nhap email: ");
        fflush(stdin);
        gets(x.email);
        fwrite(&x,sizeof(add),1,f1);
        node *p = Cnode(x);
        addnode(p);
    }
    fclose(f1);
    FILE *f12 = fopen("add2.bin","rb");
    FILE *f2 = fopen("add2find.bin","w+b");
    if (f12 == NULL){
        printf("Error");
        exit(1);
    }
    if (f2 == NULL){
        printf("Error");
        exit(1);
    }
    add x1;
    int k;
    printf("Nhap tuoi cua nguoi can tim: ");
    scanf("%d",&k);
    findnode(k);
    fwrite(&head->data,sizeof(add),1,f2);
    fclose(f2);
    fclose(f12);
    return 0;
}