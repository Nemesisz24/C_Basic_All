#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
typedef struct node{
    char data;
    struct node *next;
    struct node *prev;
} node;
typedef struct linkedlist{
    node *phead;
    node *ptail;
} linkedlist;
void makelist(linkedlist *l){
    l->phead = l->ptail = NULL;
}
node* makenode(char c){
    node *p = (node*)malloc(sizeof(node));
    p->data= c;
    p->next=p->prev=NULL;
    return p;
}
void themvaodau(node *p,linkedlist *l){
    if (l->phead == NULL && l->ptail == NULL){
        l->phead=l->ptail=p;
    }   else {
        p->next=l->phead;
        l->phead->prev=p;
        l->phead=p;
    }
}
void themvaocuoi(node *p,linkedlist *l){
    if (l->phead == NULL && l->ptail == NULL){
        l->phead=l->ptail=p;
    }
    else{
        l->ptail->next=p;
        p->prev=l->ptail;
        l->ptail=p;
    }
}
node* pop(linkedlist *l){// pop chinh la lay ra va xoa phan tu o dau (ptail)
    node *k,*k1;
    k=l->ptail;
    l->ptail=l->ptail->prev;
    l->ptail->next=NULL;
    return k;
}
int main(){
    linkedlist l1,l2;
    makelist(&l1);// chuoi ket qua
    makelist(&l2);// stack dung de chua dau toan tu 
    char s[100];
    printf("Nhap s:");
    fflush(stdin);
    gets(s);
    int n;
    n=strlen(s);
    for (int i=0;i<n;i++) {
        node*p=makenode(s[i]);
        themvaocuoi(p,&l1);
    }
    node *k;
    printf("%c",pop(&l1)->data);
    printf("\n");
    for (k=l1.phead;k!=NULL;k=k->next){
        printf("%c",k->data);
    }
    return 0;
}