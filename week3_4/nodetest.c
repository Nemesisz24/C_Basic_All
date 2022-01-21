#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* pNext;
};
typedef struct node NODE;
struct list{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;
void khoitao(LIST *l){
    l->pHead = l->pTail  =NULL;
}
NODE* khoitaonode(int x){
    NODE *p=(NODE *)malloc(sizeof(NODE));
    if (p==NULL){
        printf("Khong du bo nho");
        return NULL;
    } 
    p->data=x;
    p->pNext=NULL;
    return p;
}
void themvaodau(LIST *l,NODE *p){
    if (l->pHead==NULL){
        l->pHead = l->pTail = p;
    }
    else{
        p->pNext=l->pHead;
        l->pHead=p;
    }

}
/*void themvaocuoi(LIST *l,NODE *p){
    if (l->pHead==NULL){
        l->pHead = l->pTail = p;
    }
    else{
        l->pTail->pNext=p;
        l->pTail=p;
    }
}*/
void xuatds(LIST *l){
    NODE *k;
    for (k=l->pHead;k!=NULL;k=k->pNext){
        printf("%d ",k->data);
    }
}
int main(){
    LIST l;
    khoitao(&l);
    int n;
    printf("Nhap so luong node can them:");
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i++){
        int x;
        printf("Nhap gia tri so nguyen:");
        scanf("%d",&x);
        NODE *p=khoitaonode(x);
        themvaodau(&l,p);
    }
    xuatds(&l);
    return 0;
}