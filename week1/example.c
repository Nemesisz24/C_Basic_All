#include<stdio.h>
int main(){
    int i, s[10];
    printf("Nhap phan tu cua mang:\n"); 
    for (i=0;i<10;i++){
        scanf("%d",&s[i]);
    }
    printf("Phan tu mang in nguoc lai:");
    for (i=9;i>=0;i--){
        printf("%d ",s[i]);
    }
    return 0;
}