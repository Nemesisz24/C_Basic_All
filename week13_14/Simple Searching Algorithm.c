#include<stdio.h>
#include<string.h>
int find(char a[],char b[]){
    int m = strlen(a);
    int n = strlen(b);
    int i;
    for (i=0;i<n-m;i++){
        if (a[0] == b[i]){
            int j = 1;
            while (a[j] == b[j+i])
                j++;
            if (j == m) return i;
                else continue;
        }
    }
    return -1;
}
int main(){
    char a[1000],b[1000];
    printf("Nhap a: ");
    fflush(stdin);
    gest(a);
    printf("Nhap b: ");
    fflush(stdin);
    gets(b);
    printf("%d ",find(a,b));
    return 0;
}