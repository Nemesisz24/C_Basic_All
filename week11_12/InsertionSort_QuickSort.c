#include<stdio.h>
void insertionsort(int a[],int n){
    int i,j;
    for (i=1;i<n;i++){
        int c = a[i];
        j = i;
        while (j > 0 && c < a[j-1]){
            a[j] = a[j-1];
            j--;
        }
        a[j] = c;
    }
}
void quicksort(int a[],int l,int r){
    int pivot,i,j;
    int temp;
    if (l < r){
        i = l;
        j = r+1; 
        pivot = a[l];
        while(i<j){
            do i++;
                while (a[i] < pivot);
            do j--; 
                while (a[j] > pivot);
            if (i < j){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            } 
        }
        int t;
        t = a[l];
        a[l] = a[j];
        a[j] = t;
        quicksort(a,l,j-1);
        quicksort(a,j+1,r);
    }
}
int main(){
    int a[100],n;
    int i;
    printf("Nhap n:");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Nhap phan tu: ");
        scanf("%d",&a[i]);
    }
    int cn;
    printf("Nhap chuc nang sap xep: ");
    scanf("%d",&cn);
    if (cn == 1){
        insertionsort(a,n);
        for (i=0;i<n;i++){
            printf("%d ",a[i]);
        }
    }
    else if (cn == 2){
        quicksort(a,0,n-1);
        for (i=0;i<n;i++){
            printf("%d ",a[i]);
        }
    }
    return 0;
}