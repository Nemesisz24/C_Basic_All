#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
} node;
node *phead=NULL;
node *makenode(int x){
    node *p=(node *)malloc(sizeof(node));
    p->data = x;
    p->next =NULL;
    return p;
}
void themvaocuoi(node *p,node *q){
    node *k;
    k=p;
    while (k->next != NULL)
        k=k->next;
    k->next=q;
}
int main(){
    int k;
    printf("Nhap data phead: "); 
    scanf("%d",&k);
    node *sd=makenode(k);
    phead=sd;
    int i,n;
    printf("Nhap so data:");
    scanf("%d",&n);
    int x;
    for (i=0; i<n; i++){
        printf("NHap data:");
        scanf("%d",&x);
        themvaocuoi(phead,makenode(x));
    }
    node *k1;
    for (k1=phead;k1!= NULL;k1=k1->next)
        printf("%d ",k1->data);
    return 0;
}