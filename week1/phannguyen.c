#include<stdio.h>
void para(double *a,int *a1,double *a2){
    *a1=(int)*a;
    *a2=*a-(int)*a;
}
int main(){
    printf("Nhap so:");
    double n;
    int n1;
    double n2;
    scanf("%lf",&n);
    para(&n,&n1,&n2);
    printf("n1=%d\n",n1);
    printf("n2=%lf",n2);
}