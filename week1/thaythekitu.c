#include<stdio.h>
#include<string.h>
#define max 100
int main(){
    char s[max];
    char a,b;
    printf("Nhap ki tu can thay the:");
    scanf("%c",&a);
    printf("Nhap ki tu de thay the:");
    fflush(stdin);
    scanf("%c",&b);
    printf("Nhap chuoi:");
    fflush(stdin);
    gets(s);
    int i;
    for (i=0;i<strlen(s);i++){
        if (s[i]=='a')
            s[i]=b;
    }
    printf("chuoi sau khi sua la: %s",s);
    return 0;
}