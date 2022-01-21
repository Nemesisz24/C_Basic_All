#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node;
typedef node* nodeptr;
node *makenode(int x){
    node *temp=(node*)malloc(sizeof(node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}
void themnode(node *p,nodeptr &proot){
    if (proot == NULL) {
        proot = p;
    }
    else if (proot->data > p->data){
        themnode(p,proot->left);
    }
    else if (proot->data < p->data){
        themnode(p,proot->right);
    }
}
void taocay(nodeptr &proot){
    int n,x;
    printf("Nhap so gia tri can them:");
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        printf("Nhap gia tri can them:");
        scanf("%d",&x);
        themnode(makenode(x),proot);
    }
}
void incay(node *proot){
    if(proot == NULL) return;
        printf("%d ",proot->data);
    incay(proot->left);
    incay(proot->right);
}
int main(){
nodeptr root=NULL;
taocay(root);
incay(root);
return 0;
}