#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,n,*p;
    printf("Nhap n:");
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int));
    if (p==NULL){
        printf("Memory allocation failure");
        return 1;
    }
    printf("Nhap so :");
    for (i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("mang sau khi in nguoc:\n");
    for (i=n-1;i>=0;i--){
        printf("%d ",p[i]);
    }
    free(p);
    return 0;
}