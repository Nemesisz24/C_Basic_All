#include<stdio.h>
/* De bai:
Write a program to read sentences from a specified file one character at a time. 
Each capital letter is converted into a lower-case letter, and each lower-case letter
is converted into a capital letter. The new sentence is then written into another file.
Note that you must output numbers, the signs as they are. 
*/
int main(){
    FILE *f1,*f2;
    f1=fopen("lab2.txt","r");
    f2=fopen("lab2w.txt","w+");
    if (f1==NULL){
        printf("loi mo file!");
        return 1;
    }
    if (f2==NULL){
        printf("loi mo file!");
        return 1;
    }
    char c;
    while (!feof(f1)){
        c=fgetc(f1);
        if (c >= 'A' && c <= 'Z')
             c=c+32;
            else if (c >= 'a' && c <= 'z')
                c=c-32;
        fputc(c,f2);
        putchar(c);
        
    }
   fclose(f1);
   fclose(f2);
   return 0;
}