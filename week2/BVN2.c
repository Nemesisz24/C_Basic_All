#include<stdio.h>
#include<stdlib.h>
int *p;
int tong(int n){
    int m=0;
    for(int i=1;i<=n;i++){
        m=m+p[i];
    }
    return m;
}
int main(){
    FILE *f1,*f2;
    int n,i;
    p=(int *)malloc(sizeof(int)*n);
    if (p == NULL){
        printf("Error malloc");
        return 1;
    }
    f1=fopen("hw2.txt","r");
    f2=fopen("hw2w.txt","w");
    if(f1==NULL){
        printf("Error");
        return 1;
    }
    if (f2==NULL){
        printf("Error");
        return 1;
    }
    fscanf(f1,"%d",&n);
    p[0]=n;
    for (i=1;i<=n;i++){
        fscanf(f1,"%d",&p[i]);
    }
    for(i=n;i>=1;i--){
        fprintf(f2,"%d ",p[i]);
    }
    fprintf(f2,"%d",tong(n));
    free(p);
    fclose(f1);
    fclose(f2);
    return 0;
}