#include<stdio.h>
int main(int argc, char* argv[]) {
    double a,b;
    if (argc != 3){
        printf("Wrong number!");
        return 1;
    }
    a=atof(argv[1]);
    b=atof(argv[2]);
    printf("Chu vi hinh chu nhat la: %lf",2*(a+b));
    printf("Dien tich hinh chu nhat la: %lf",a*b);
    return 0;
}