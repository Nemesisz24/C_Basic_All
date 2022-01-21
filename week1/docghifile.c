#include<stdio.h>
/* De bai:
Create a text file name lab1.txt with the content as you want.
Write a program to read from a text file one character at a time, 
then write it to a new file with the name lab1w.txt */
int main(){
    FILE *fptr1,*fptr2;
    fptr1=fopen("lab1.txt","r");
    fptr2=fopen("lab1w.txt","w");
    if (fptr1==NULL){
        printf("loi moi file!");
        return 1;
    }
    if (fptr2==NULL){
        printf("loi moi file!");
        return 1;
    }
    char c;
    while (!feof(fptr1)){
        c=fgetc(fptr1);
        fputc(c,fptr2);
        putchar(c);
    }
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}