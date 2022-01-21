#include<iostream>
using namespace std;
void mergesort(int a[],int l,int r){
    int m;
    if ( l < r){
        m = (l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        int i,j,k;
        i=l;j=m+1;k=l;
        while (k < r){
            while (i < m && j < r){
                if (a[i] < a[j]){
                    a[k] = a[i];
                    k++;
                    i++;
                }
                else if (a[j] < a[i]){
                    a[k] = a[j];
                    k++;
                    j++;
                }
            }
            while (i < m){
                a[k] = a[i];
                i++;k++;
            }
            while (j < r){
                a[k] = a[j];
                j++;k++;
            }
        }
    }   
}
int main(){
    int a[100],n,i;
    cin>>n;
    for (i=0;i<n;i++)
        cin>>a[i];
    mergesort(a,0,n-1);
    for (i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}