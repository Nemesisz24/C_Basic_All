#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* con;
    struct node* ae;
} node;
node *root=NULL;
node *makenode(int x){
    node *p=(node*)malloc(sizeof(node));
    p->data = x;
    p->con = p->ae = NULL;
    return p;
}
void themvaocuoi(node *p,node *q){
    node *k;
    k=p;
    while (k->ae != NULL)
        k=k->ae;
    k->ae=q;
}
void noidanhsach(node *p, node *q){
    p->con = q;
}
void taodscon(node *p, int n){//p la root
    node *phead=NULL;
    int l;
    printf("Nhap gia tri node con dau tien:");
    scanf("%d",&l);
    node *f1=makenode(l);
    phead=f1;
    int i;
    for (i=0;i<n-1;i++){
        printf("Nhap gia tri node con tiep theo: ");
        scanf("%d",&l);
        node *p1=makenode(l);
        themvaocuoi(phead,p1);
    }
    noidanhsach(p,phead);
}
void incay(node *p){
    
}
int main(){
    int n,x;
    printf("Nhap gia tri root: ");
    scanf("%d",&x);
    node *l1=makenode(x);
    root=l1;
    printf("Nhap so con cua root:");
    scanf("%d",&n);
    taodscon(root,n);
    return 0;

}