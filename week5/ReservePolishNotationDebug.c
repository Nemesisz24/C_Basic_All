#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char data;
    struct node* next;
} node;
typedef struct stack{
    node * head;
} stack;
void makehead(stack *l){
    l->head = NULL;
}
node * Cnode(char c){
    node *p = (node*)malloc(sizeof(node));
    p->data = c;
    p->next = NULL;
    return p;
}
void push(node *p, stack *l){
    if (l->head == NULL)
        l->head = p;
        else {
            p->next = l->head;
            l->head = p;
        }
}
void pop(stack *l){
    node *p = l->head;
    l->head=l->head->next;
    free(p);
}
char top(stack *l){
    return l->head->data;
}
int empty(stack *l){
    if (l->head == NULL) 
        return 1;
        else return 0;
}
int main(){
    char s[100];// s la string chua bieu thuc ban dau ( trung to )
    printf("Nhap chuoi bieu thuc trung to: ");
    fflush(stdin);
    gets(s);
    char s1[100];
    //char *s1 = (char*)malloc(strlen(s)*sizeof(char)); // s1 la string chua bieu thuc hau to
    int i=0;
    stack l1;// l1 la stack de chua tam thoi toan tu cua bieu thuc trung to
    makehead(&l1);
    int j=0;
    for (i=0;i<strlen(s);i++){
        if (s[i] >= '0' && s[i] <= '9'){
            s1[j] = s[i];
            j=j+1;
        }
        else if (s[i] == '('){ 
            node *k = Cnode(s[i]);
            push(k,&l1);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*'|| s[i] =='/'){
            if (s[i] == '+' || s[i] == '-'){
                if (top(&l1) == '+' || top(&l1) == '-' || top(&l1) == '*'|| top(&l1) =='/'){
                    s1[j] = top(&l1);
                    j=j+1;
                    pop(&l1);
                    node *k = Cnode(s[i]);
                    push(k,&l1);
                }
                else{
                    node *k = Cnode(s[i]);
                    push(k,&l1);
                }
            }
            else if (s[i] == '*'|| s[i] == '/'){    
                if (top(&l1) == '*'|| top(&l1) =='/'){
                    s1[j] = top(&l1);
                    j=j+1;
                    pop(&l1);
                    node *k = Cnode(s[i]);
                    push(k,&l1);
                }
                else{
                    node *k = Cnode(s[i]);
                    push(k,&l1);
                }
            }
        }
        else if(s[i] == ')'){
            while (top(&l1) != '('){
                s1[j] = top(&l1);
                j=j+1;
                pop(&l1);
            }
            pop(&l1);
        }
    }
    while(empty(&l1) != 1){
        s1[j] = top(&l1);
        j=j+1;
        pop(&l1);
    }
    printf("postfix = %s",s1);
    return 0;
}