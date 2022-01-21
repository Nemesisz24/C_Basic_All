#include<stdio.h>
int search(int a[],int n,int k){
    for (i=0;i<n;i++){
        if (a[i] == k)
            return i+1;
    }
    return 0;
}
int main(){
    int a[10];
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d",&n); 
    int i;
    for (i=0;i<n;i++){
        printf("Nhap phan tu thu %d: ",i+1);
        scanf("%d",&a[i]);
    }
    int k;
    printf("Nhap phan tu can tim: ");
    scanf("%d",&k);
    printf("Vi tri phan tu %d la %d.",k,search(a,n,k));
    return 0;
}