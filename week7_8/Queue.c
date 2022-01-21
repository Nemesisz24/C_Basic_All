#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node;
typedef struct stack{
    node *head;
}stack;
void makestack(stack *p){
    p->head = NULL;
}
node *Cnode(int x){
    node *p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}
int empty(stack *l){
    if (l->head == NULL )
        return 1;
        else return 0;
}
void checkempty(stack *l){
    if (empty(l) == 1)  printf("Stack rong!\n");
    else printf("Stack khong rong!\n");
}
void push(stack *l){
    int x;
    printf("Nhap phan tu can them:");
    scanf("%d",&x);
    node *p=Cnode(x);
    if (l->head == NULL)
        l->head = p;
    else{
        node *k;
        for (k=l->head; k->next!=NULL; k=k->next){
            ;;
        }
        k->next = p;
    }
}
void pop(stack*l){
    node *k;
    if (l->head->next == NULL )
        l->head == NULL;
    for (k=l->head; k->next->next!=NULL; k=k->next){
        ;;
    }
    k->next = NULL;
}
void top(stack*l){
    node *k;
    for (k=l->head; k->next!=NULL; k=k->next){
        ;;
    }
    printf("%d\n",k->data);
}
void size(stack*l){
    int dem = 1;
    node *k;
    for (k=l->head; k->next!=NULL; k=k->next){
        dem++;
    }
    printf("Size of stack: %d\n",dem);
}
void instack(stack*l){
    node *k;
    for (k=l->head; k!=NULL; k=k->next){
        printf("%d ",k->data);
    }
}
int main(){
    stack l;
    makestack(&l);
    int cn;
    while(1){
        printf("\t\t\t---------------MENU---------------\n");
        printf("\t\t\t0: Thoat chuong trinh\n");
        printf("\t\t\t1: Them 1 phan tu vao stack\n");
        printf("\t\t\t2: Xoa phan tu dau trong stack\n");
        printf("\t\t\t3: Truy cap vao phan tu dau trong stack\n");
        printf("\t\t\t4: So luong phan tu cua stack\n");
        printf("\t\t\t5: Kiem tra stack rong hay khong?\n");
        printf("\t\t\t6: In stack\n");
        printf("Nhap chuc nang: ");
        scanf("%d", &cn);
        switch(cn) {
            case 1: push(&l); break;
            case 2: pop(&l); break;
            case 3:top(&l); break;
            case 4: size(&l); break;
            case 5: checkempty(&l); break;
            case 6: instack(&l); break;
        }
        if (cn==0) break;
    }
    return 0;
}
