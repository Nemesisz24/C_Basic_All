#include<stdio.h>
int binsearch(int a[],int n, int k){
    int l=0,r=n-1;
    int mid = (r+l)/2;
    while (l < r){
        if (a[mid] < k){
            l = mid + 1;
            mid = (r+l)/2;
        }
        else if (a[mid] > k){
            r = mid;
            mid = (r+l)/2;
        }
        else if (a[mid] == k)
            return mid;
    }
    return -1;
}
int main(){
    int i,n,s[100];
    printf("Nhap so phan tu mang:");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Nhap phan tu thu %d: ",i);
        scanf("%d",&s[i]);
    }
    int k;
    printf("Nhap gia tri can tim:");
    scanf("%d",&k);
    printf("Vi tri: %d",binsearch(s,n,k));
    return 0;
}