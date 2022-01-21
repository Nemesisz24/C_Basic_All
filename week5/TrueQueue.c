#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
} node;
typedef struct queue{
    node *head;
} queue;
void makequeue(queue *l){
    l->head = NULL;
}
node *Cnode(int x){
    node *p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}
int size(queue *l){
    node *k;
    int dem = 0;
    for (k=l->head; k!=NULL; k=k->next){
        dem++;
    }
    return dem;
}
void sizequeue(queue *l){
    printf("Size of queue = %d\n",size(l));
}
int empty(queue *l){
    if (l->head == NULL)
        return 1;
        else return 0;
}
void checkempty(queue *l){
    if (empty(l) == 1) 
        printf("Queue rong!\n");
        else printf("Queue khong rong!\n");
}
void push(queue *l){
    int x;
    printf("Nhap phan tu can them: ");
    scanf("%d",&x);
    node *p = Cnode(x);
    if (l->head == NULL)
        l->head = p;
        else{
           p->next = l->head;
           l->head = p;
        }
}
void pop(queue *l){
    node *k;
    if (l->head->next == NULL){
        l->head = NULL;
    }
    else{
        for (k=l->head; k->next->next!=NULL; k=k->next){
        ;;
            }
        k->next = NULL;
    }
    
}
int front(queue *l){
    node *k;
    for (k=l->head;k->next != NULL;k=k->next)
        ;;
    return k->data;
}
void phantudau(queue *l){
    printf("Phan tu dau queue la: %d",front(l));
}
int back(queue *l){
    return l->head->data;
}
void phantucuoi(queue *l){
    printf("Phan tu cuoi queue la: %d",back(l));
}
void printqueue(queue *l){
    node *k;
    for (k=l->head;k!=NULL;k=k->next)
        printf("%d ", k->data);
}
int main(){
    queue l1;
    makequeue(&l1);
    int cn;
    while(1){
        printf("\t\t\t---------------MENU---------------\n");
        printf("\t\t\t0: Thoat chuong trinh\n");
        printf("\t\t\t1: Them 1 phan tu vao queue\n");
        printf("\t\t\t2: Xoa phan tu dau queue\n");
        printf("\t\t\t3: Truy cap vao phan tu dau queue\n");
        printf("\t\t\t4: Truy cap vao phan tu cuoi queue\n");
        printf("\t\t\t5: Tra ve Size of queue\n");
        printf("\t\t\t6: Kiem tra xem queue rong hay khong\n");
        printf("\t\t\t7: In queue\n");
        printf("Nhap chuc nang: ");
        scanf("%d", &cn);
        switch(cn){
            case 1: push(&l1);break;
            case 2: pop(&l1);break;
            case 3: phantudau(&l1); break;
            case 4: phantucuoi(&l1); break;
            case 5: sizequeue(&l1); break;
            case 6: checkempty(&l1); break;
            case 7: printqueue(&l1); break;
        }
        if (cn == 0) break;
    }
    return 0;
}