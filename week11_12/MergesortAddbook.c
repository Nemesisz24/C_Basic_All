#include<iostream>
void merge(int a[],int l,int m,int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int a1[n1],b1[n2];
    int i,j;
    for (i=0;i<n1;i++) 
        a1[i] = a[l+i];
    for (i=0;i<n2;i++)
        a2[i] = a[m+1+i];
    i = 0;
    j = 0;
    int k = l;
    while (i < n1 && j < n2){
        if (a1[i] < a2[j]){
            a[k] = a1[i];
            i++;k++;
        }
        else if (a1[i] > a2[j]){
            a[k] = a2[j];
            j++;k++;
        }
        while (i < n1){
            a[k] = a1[i];
            k++;i++;
        }
        while (j < n2){
            a[k] = a2[j];
            k++;j++;
        }
    }
}
int main(){
    int a[1000];
    int n;
    cout<<"Nhap n: ";
    cin>>n;
    for (int i = 0;i<n;i++){
        cout<<"Nhap pt: ";
        cin>>a[i];
    }
    merge(a,0,(n-1)/2,n-1);
}