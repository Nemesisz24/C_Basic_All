#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;   
    struct node *left;
    struct node *right;
} node;
node *makenode(int x){
    node *temp=(node*)malloc(sizeof(node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}
void themnode(int x,node *proot){
    node *p=makenode(x);
    if (proot == NULL) 
        proot=p;
    else if (proot->data > x){
        if (proot -> left == NULL)
            proot->left = p;
            else themnode(x,proot->left);
    }
    else if (proot->data < x){
        if (proot -> right == NULL)
            proot->right = p;
            else themnode(x,proot->right);
    }
}   
void taocay(node *proot){
    int n,x;
    printf("Nhap so gia tri can them:");
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        printf("Nhap gia tri can them:");
        scanf("%d",&x);
        themnode(x,proot);
    }
}
void incay(node *proot){
    printf("%d ",proot->data);
}
int main(){
    node *root=NULL;
    int chucnang,x;
    int n;
    while(1){
        printf("Nhap chuc nang: ");
        scanf("%d",&chucnang);
        switch (chucnang){
            case 1: taocay(root); break;
            case 2: incay(root); break;
        }
        if (chucnang == 0)
            break;
    }
    if (root==NULL)
        printf("Sai?");
    return 0;
}