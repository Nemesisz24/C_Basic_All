#include<stdio.h>
#include<stdlib.h>
typedef struct address{
    char name[30]; 
    int age;
    char gmail[50];
} add;
typedef struct node{
    add data;
    struct node* next;
} node;
typedef struct stack{
    node * root;
} stack;
void makestack(stack *l){
    l->root = NULL;
}
node *Cnode(add x){
    node *p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}
int empty(stack *l){
    if (l->root == NULL)
        return 1;
        else return 0;
}
void push(node *p, stack *l){
    if (l->root == NULL){
        l->root = p;
    }
    else{
        p->next = l->root;
        l->root = p;
    }
}
void pop(stack *l){
    l->root = l->root->next;
}
add top(stack *l){
    return l->root->data;
}
int size(stack *l){
    int dem  = 0;
    node *k;
    for (k=l->root; k!= NULL; k=k->next){
        dem++;  
    }
    return dem;
}
int main(){
    stack l1;
    makestack(&l1);
    FILE *f1 = fopen("address.bin", "rb");
    FILE *f2 = fopen("addresscopy.bin", "wb");
    if (f1 == NULL){
        printf("Error opening file f1");
        exit(1);
    }
    if (f2 == NULL){
        printf("Error creating file f2");
        exit(1);
    }
    add x;
    while (!feof(f1)){
        fread (&x,sizeof(add),1,f1);
        node *p = Cnode(x);
        push(p,&l1);
    }
    add x1;
    while (!empty(&l1)){
        x1 = top(&l1);
        fwrite(&x1,sizeof(add),1,f2);
        pop(&l1);
    }
    fclose(f1);
    fclose(f2);
    FILE *f3 = fopen("addresscopy.bin","rb");
    add arr[2];
    fread(arr,sizeof(add),2,f3);
    for (int j =0;j<2;j++){
        printf("thong tin nguoi thu %d: ",j+1);
        printf("Name: %s\n",arr[j].name);
        printf("Age: %d\n",arr[j].age);
        printf("Gmail: %s\n",arr[j].gmail);
    }
    return 0;
}