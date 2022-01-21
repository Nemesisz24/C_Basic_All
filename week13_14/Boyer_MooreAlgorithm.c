#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void lastcharacter(char s[],int s1[]){
    int i,j;
    for (i=0;i<30;i++)
        s1[i] = 0;
    for (i=0;i<strlen(s);i++){
        if (i > s1[(int)s[i] - 97])
            s1[(int)s[i] - 97] = i;
    }
}
void BMsearching(char T[],char P[],int n,int m){
        // T la xau ban dau, P la xau can tim, n la chieu dai xau ban dau, m la chieu dai xau can tim
        int a[30];// a la mang chua he so last trong chuoi P
        int vitri[30];
        for (int vt = 0; vt<30;vt++)
            vitri[vt] = 0;
        int i,l=0;
        lastcharacter(P,a);
        int s = 0;
        while (s <= n-m){
            int j = m-1;
            while (P[j] == T[s+j])
                j--;
            if (j == -1){
                vitri[l] = s;
                l++;
                s++;
            }
            else{
                if (a[(int)T[j+s] - 97] < j )
                    s = s + j - a[(int)T[j+s] - 97];
                else if (a[(int)T[j+s] - 97] > j)
                    s = s + 1;
            }
        }
        for (i = 0;i < 30;i++){
                printf("%d ",vitri[i]);
        }
}
int main(){
    char T[1000],P[1000];
    printf("Nhap xau ban dau: ");
    fflush(stdin);
    gets(T);
    printf("Nhap xau mau: ");
    fflush(stdin);
    gets(P);
    BMsearching(T,P,strlen(T),strlen(P));
    return 0;
}