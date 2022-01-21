#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char data;
    struct node* next;
} node;
typedef struct stack{
    node * headst;
} stack;
void makest(stack *l){
    l->headst = NULL;
}
node * Cnode(char c){
    node *p = (node*)malloc(sizeof(node));
    p->data = c;
    p->next = NULL;
    return p;
}
void pushst(node *p, stack *l){
    if (l->headst == NULL)
        l->headst = p;
        else {
            p->next = l->headst;
            l->headst = p;
        }
}
void popst(stack *l){
    if (l->headst->next == NULL)
        l->headst = NULL;
        else
            l->headst = l->headst->next;
}
char topst(stack *l){
    return l->headst->data;
}
int emptyst(stack *l){
    if (l->headst == NULL) 
        return 1;
        else return 0;
}
int sizest(stack *l){
    node *k;
    int dem = 0;
    for (k=l->headst;k!=NULL;k=k->next){
        dem++; 
    }
    return dem;
}
int main(){
    stack st;
    makest(&st);
    char s[100];
    char s1[100];
    printf("Nhap bieu thuc hau to: ");
    fflush(stdin);
    gets(s);
    int i,i1;
    for (i=0;i<strlen(s);i++){
        if (s[i] >= '0' && s[i] <= '9'){
            s1[i1] = s[i];
            i1++;
        }
        else if (s[i] == '('){ 
            node *p1 = Cnode(s[i]);
            pushst(p1,&st);
        }
        else if (s[i] == '+' || s[i] == '-'|| s[i] == '*'|| s[i] == '/'){
            if (emptyst(&st) == 1){
                node *p = Cnode(s[i]);
                pushst(p,&st);
            }
            else{
                if (topst(&st) == '('){ 
                    node *p = Cnode(s[i]);
                    pushst(p,&st);
                }
                else if(topst(&st) == '+'|| topst(&st) == '-'|| topst(&st) == '*'|| topst(&st) =='/'){
                    if (s[i] == '+' || s[i] == '-'){
                        while(emptyst(&st)  != 1 ){
                            s1[i1] = topst(&st);
                            i1++;
                            popst(&st);
                        }
                        node *p = Cnode(s[i]);
                        pushst(p,&st);
                    }
                    else if (s[i] == '*'|| s[i] == '/'){
                        if (topst(&st) == '+'|| topst(&st) =='-'){
                            node *p = Cnode(s[i]);
                            pushst(p,&st);
                        }
                        else if (topst(&st) == '*' || topst(&st)=='/'){
                            if (sizest(&st) != 1){
                                while(sizest(&st) != 1){
                                    if(topst(&st) == '*' || topst(&st) =='/'){
                                        s1[i1] = topst(&st);
                                        i1++;
                                        popst(&st);
                                    }
                                    else if (topst(&st) =='+'|| topst(&st) == '-'|| topst(&st)=='('){
                                        node *p =Cnode(s[i]);
                                        pushst(p,&st);
                                    }
                                }
                            }
                            else if (sizest(&st) == 1){
                                if(topst(&st) == '*' || topst(&st) == '/'){
                                    s1[i1] = topst(&st);
                                    i1++;
                                    popst(&st);
                                    node *p3 = Cnode(s[i]);
                                    pushst(p3,&st);
                                }
                                else if (topst(&st) == '+'|| topst(&st) == '-'|| topst(&st) =='('){
                                    node *p = Cnode(s[i]);
                                    pushst(p,&st);
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (s[i] == ')'){
            while(topst(&st) != '('){
                s1[i1] = topst(&st);
                i1++;
                popst(&st);
            }
            popst(&st);
        }
        if (i == strlen(s)-1){
            while(emptyst(&st) != 1){
                s1[i1] = topst(&st);
                i1++;
                popst(&st);
            }
        }
    }
    for (i1 = 0;i1<strlen(s1);i1++){
        printf("%c ",s1[i1]);
    }
    return 0;
}
 