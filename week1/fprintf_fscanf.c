#include<stdio.h>
#include<string.h>
/* De bai:
Write a program to read two or more lines into an array of 
character strings one by one from a specified file and find 
the length of each line. You must write the length of each 
line and character string in the file.
*/
int main(){
    FILE *f1,*f2;
    f1=fopen("lab1.txt","r");
    f2=fopen("lab1w.txt","w");
    if (f1==NULL){
        printf("Error");
        return 1;
    }
    char s[100];
    int l;
    while(fgets(s,100,f1) != NULL){
        l=strlen(s);
        fprintf(f2,"%d %s",l,s);
        printf("%s",s);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}