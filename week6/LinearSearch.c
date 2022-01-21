#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
} node;
node *head;
node* Cnode(int x){
    node *p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}
void addnode(node *p){
    if (head == NULL)
        head = p;
        else{
            node *k;
            for (k = head; k->next != NULL; k = k->next)
                ;;
            k->next = p;
        }
}
int search(int x){
    node *k;
    int i=0;
    for (k=head;k!=NULL;k=k->next){
        if  (k->data == x)
            return i;
        i++;
    }
    return -1;
}
int main(){
    int n,i,x;
    head = NULL;
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Nhap phan tu:");
        scanf("%d",&x);
        node *p = Cnode(x);
        addnode(p);
    }
    int k;
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d",&k);
    printf("Vi tri phan tu can tim kiem: %d",search(k));
    return 0;
}