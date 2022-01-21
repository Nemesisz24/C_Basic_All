#include<stdio.h>
#include<stdlib.h>
int n;
typedef struct node {
    int data;
    struct node *next;
} node;
node *phead,*ptail;// phead là node chỉ vào đầu danh sách, ptail là node chỉ vào cuối danh sách
void khoitaods(){// khởi tạo danh sách
    phead = phead = NULL;
}
node* khoitaonode(int x){//khởi tạo 1 node
    node *temp=(node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void themvaodau(node *temp){// thêm node mới vào đầu danh sách
    if (phead == NULL){
        phead=ptail=temp;
    }
    else{
        temp->next = phead;
        phead=temp;
    }
}
void themvaocuoi(node *temp){// thêm node mới vào cuối danh sách
    if(phead == NULL){
        phead=ptail=temp;
    } else{
        ptail->next=temp;
        ptail=temp;
    }
}
void themnodesau(node *p){// thêm node mới p vào sau 1 node bất kì  có giá trị là y
    printf("Nhap data can duyet:");
    int y;
    scanf("%d",&y);
    if (phead->next == NULL && phead->data==y){
        themvaocuoi(p);
    } else {
        node *k;
        for (k=phead; k!=NULL; k=k->next){
            node *k1=khoitaonode(p->data);
            if (k->data==y){
                k1->next=k->next;
                k->next=k1;
            }
        }
    }

}
void themnodetruoc(node *p){// thêm node mới p vào trước 1 node bất kì  có giá trị là y
    printf("Nhap data can duyet:");
    int y;
    scanf("%d",&y);
    if (phead->data == y ){
        themvaodau(p);
    } else {
        node *k,*k1,*k2;
        for (k=phead;k!=NULL;k=k->next){
            k2=khoitaonode(p->data);
            if (k->data == y){
                k2->next=k;
                k1->next=k2;
            }
            k1=k;
        }
    }
}
int kichthuoc(){
    int kt=0;
    node *k;
    for (k=phead;k!=NULL;k=k->next){
        kt++;
    }
    return kt;
}
void themvitri(node *p){
    int dem=0,y,dt;
    printf("Nhap vi tri muon them:");
    scanf("%d",&y);
    if (y > kichthuoc())
        printf("Khong the them!");
        else{
            node *k,*k1;
            for (k=phead;k!=NULL;k=k->next){
                dem++; 
                if (dem == y){
                    p->next=k;
                    k1->next=p;
                }
                k1=k;
            }
        }
    
}
int vitri(int x){// Tìm vị trí của 1 node khi biết số data
    int dem=0;
    node *p;
    for (p=phead;p!=NULL;p=p->next){
        dem++;
        if (p->data==x)
            return dem;
            else return -1;
    }
}

void xuatds(){// xuất dữ liệu danh sách các phần tử ra màn hình
    node*k;
    for (k=phead;k != NULL;k=k->next){
        printf("%d ",k->data);
    }
}
void xoanode(){// xóa 1 node ở vị trí bất kì 
    int x;
    printf("nhap vi tri can xoa:");
    scanf("%d",&x);
    node *k,*k1;
    int dem =0;
    if (x < 1 && x > n) printf("Khong co vi tri nay!");
        else if (x == 1){
            phead=phead->next;
        }
        else if (x == n){
            for (k=phead;k != NULL; k=k->next){
                if (k->next->next == NULL )
                    k->next=NULL;
            }
        }
        else if ( x >1 && x < n ){
            for (k = phead;k != NULL; k=k->next){
                dem++; 
                if (dem == x ){
                    k1->next = k->next;
                    k->next=NULL;
                    break;
                }
                k1=k;
            }
        }
}
int main(){
    khoitaods();
    int x;
    printf("Nhap so data:");
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++){
        printf("Nhap du lieu :");
        scanf("%d",&x);
        node *p=khoitaonode(x);
        themvaocuoi(p);
    }
    xoanode();
    xuatds();
    return 0;
}
