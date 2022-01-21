#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node;
void makehead(node *head){
    head = NULL;
}
node* makenode(int x){
    node *p=(node *)malloc(sizeof(node));
    p->data = x;
    return p;
}
void themnode(node *head, int x){
    node *p=makenode(x);
    if (head == NULL )
        head = p; 
        else head ->next = p;
}
void inds(node *head){
    printf("%d %d ",head->data,head->next->data);
}
int main(){
    node *head;
    head=NULL;
    int n,i,x;
    printf("Nhap so node:");
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        printf("Nhap x:");
        scanf("%d",&x);
        themnode(head,x);
    }
    if (head==NULL) printf("sai!");
    return 0;
}