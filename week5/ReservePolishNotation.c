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
    node *k;
    k=l->ptail;
    l->ptail=l->ptail->prev;
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
    int i;
    for (i=0;i<n;i++){
        if (s[i] >= '0' && s[i] <= '9'){
            node *p=makenode(s[i]);
            themvaocuoi(p,&l1);
        } else if ( s[i] == '('){
            node *p=makenode(s[i]);
            themvaocuoi(p,&l2);
        } else if ( s[i] == '^'){
            node *p=makenode(s[i]);
            themvaocuoi(p,&l2);
        } else if (s[i] == '*'){
            if (l2.ptail->data == '/' || l2.ptail->data == '^'|| l2.ptail->data == '*'){
                node *p=pop(&l2);
                themvaocuoi(p,&l1);
                node *p1=makenode(s[i]);
                themvaocuoi(p1,&l2);
            } else {
                node *p=makenode(s[i]);
                themvaocuoi(p,&l2);
            }
        } else if (s[i] == '/'){
            if (l2.ptail->data == '*' || l2.ptail->data == '^'|| l2.ptail ->data == '/'){
                node *p=pop(&l2);
                themvaocuoi(p,&l1);
                node *p1=makenode(s[i]);
                themvaocuoi(p1,&l2);
            } else {
                node *p=makenode(s[i]);
                themvaocuoi(p,&l2);
            }
        } else if (s[i] == '+'){
            if (l2.ptail->data == '*' || l2.ptail->data == '^' || l2.ptail->data == '/'|| l2.ptail->data == '-'|| l2.ptail->data == '+'){
                node *p=pop(&l2);
                themvaocuoi(p,&l1);
                node *p1=makenode(s[i]);
                themvaocuoi(p1,&l2);
            } else {
                node *p=makenode(s[i]);
                themvaocuoi(p,&l2);
            }
        } else if (s[i] == '-'){
            if (l2.ptail->data == '*' || l2.ptail->data == '^' || l2.ptail->data == '/'|| l2.ptail->data == '+'|| l2.ptail->data == '-'){
                node *p=pop(&l2);
                themvaocuoi(p,&l1);
                node *p1=makenode(s[i]);
                themvaocuoi(p1,&l2);
            } else {
                node *p=makenode(s[i]);
                themvaocuoi(p,&l2);
            }
        } else if ( s[i] == ')' ){
                node *k=l2.ptail;
                while ( k->data != '(' ){
                    node *p= pop(&l2);
                    themvaocuoi(p,&l1);
                    k=k->prev;
                }
        } 
        if (i == n-1){
            while (l2.ptail != NULL){
                themvaocuoi(pop(&l2),&l1);
            }
        }
    }
    node *x;
    for (x=l1.phead;x!=NULL;x=x->next){
        printf("%c",x->data);
    }
    return 0;
}