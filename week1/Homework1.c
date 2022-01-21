#include<stdio.h>
/* De bai:
Write a program to read a text file created with emacs.
 Put a line number to the head of the line and output the 
 contents of the file to the standard output. A text file 
 name can be specified as the argument to the program.*/
int main(){
    FILE *f1=fopen("lab1.txt","r");
    FILE *f2=fopen("lab1w.txt","w");
    if (f1==NULL){
        printf("Error");
        return 1;
    }
    if (f2==NULL){
        printf("Error");
        return 1;
    }
    int dem = 1;
    char text[100];
    while (fgets(text,100,f1)!=NULL){
        fprintf(f2,"%d ",dem);
        fputs(text,f2);
        dem++;
    }
    fclose(f1);
    fclose(f2);
    return 0;
}