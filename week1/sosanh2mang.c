#include<stdio.h>
#include<string.h>
#define max 100
int ss(int arr1[],int arr2[],int n,int m){
    if (n != m)
        return 0;
    int i;
    for (i=0;i<strlen(arr1);i++)
        if (arr1[i] != arr2[i])
            return 0;
    return 1;
}
int main(){
    int n,m,arr1[max],arr2[max],i;
    printf("Nhap so phan tu mang 1:");scanf("%d",&n);
    printf("Nhap so phan tu mang 2:");scanf("%d",&m);
    printf("Nhap tung phan tu mang 1:\n");
    for ( i=0;i<n;i++)
        scanf("%d",&arr1[i]);
    printf("Nhap tung phan tu mang 2:\n");
    for ( i=0;i<m;i++)
        scanf("%d",&arr2[i]);
    if (ss(arr1,arr2,n,m) == 1) 
        printf("2 mang bang nhau!");
        else printf("2 mang khac nhau!");
    return 0;
}