#include<stdio.h>
int main(){
    FILE *f1,*f2;
    f1=fopen("test1.txt","r");
    f2=fopen("test1w.txt","w+");
    if (f1==NULL){
        printf("Loi mo file");
        return 1;
    }
    if (f2==NULL){
        printf("Loi mo file");
        return 1;
    }
    char c;
    char c1='\n';
    while(!feof(f1)){
        c=fgetc(f1);
        fputc(c,f2);
        if (c=='\n')
           fputc(c1,f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}