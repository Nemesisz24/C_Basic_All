#include<stdio.h>
typedef struct point{
    double x, y;
} point;
typedef struct cc{
    double r;
    point i;
} cc;
int test(point a, cc b){
    double x1,x2;
    x1=a.x - b.i.x;
    x2=a.y - b.i.y;
    if ( x1*x1+x2*x2 <= b.r * b.r  )
        return 1;
        else return 0;
}
int main(){
    point a;
    cc b;
    printf("Nhap toa do diem A:");
    scanf("%lf",&a.x);
    scanf("%lf",&a.y);
    printf("Nhap thong so duong tron:\n");
    printf("Nhap ban kinh:");scanf("%lf",&b.r);
    printf("Nhap toa do tam:");
    scanf("%lf",&b.i.x);
    scanf("%lf",&b.i.y);
    if (test(a,b) == 1) printf("Diem A nam trong duong tron");
        else printf("Diem A ko nam trong duong tron");
    return 0;
}