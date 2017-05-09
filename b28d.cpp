#include<iostream>
using namespace std;  
int a[100],n;
void swap(int* a, int* b){
    int t = *a; *a = *b; *b = t;
}

void nhap(int a[],int&n){
	cout<<"Nhap n :";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}

int partition (int a[],int l,int h){
    int x=a[h];    
    int i=l-1;  
    for (int j=l;j<=h-1;j++) { 
        if (a[j]<=x){
            i++;    
            swap(&a[i],&a[j]);  
        }
    }
    swap(&a[i+1],&a[h]);  
    return (i + 1);
}

void quickSort(int a[], int l, int h){
    if (l<h){
        int p=partition(a,l,h); 
        quickSort(a,l,p-1);
        quickSort(a,p+1,h);
    }
}
 
void xuat(int a[],int n){
    for(int i=0;i<n;i++){
    	cout<<a[i]<<" ";
    }   
}
 
int main(){
    int n,a[100];
    nhap(a,n);
    quickSort(a,0,n-1);
    xuat(a,n);
}
