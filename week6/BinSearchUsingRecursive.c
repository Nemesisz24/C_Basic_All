#include<stdio.h>
int binsearch(int a[],int l,int r,int k){
    int mid;
    mid = (l+r)/2;
    if (a[mid] == k) return mid;
    if (a[mid] < k){
        return binsearch(a,mid+1,r,k);
        }
    else if (a[mid] > k){
        return binsearch(a,l,mid,k);
        }
    return -1;

}
int main(){
    int n,i,a[100];
    printf("Nhap so phan tu mang: "); 
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("Nhap phan tu thu %d: ",i);
        scanf("%d",&a[i]);
    }
    printf("Nhap phan tu can tim: ");
    int k;
    scanf("%d",&k);
    printf("Vi tri phan tu can tim: %d",binsearch(a,0,n-1,k));
    return 0;
}