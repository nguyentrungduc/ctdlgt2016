#include<iostream>
using namespace std;

void nhap(int a[],int&n){
	cout<<"nhap so phan tu :";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}

void sort( int a[], int n ){
	if(n>1) sort(a,n-1);
	int i;	
	int x=a[n];
	i=n-1;
	while(i>=0&&a[i]>x){
		a[i+1]=a[i];
		i--;
	}
	a[i+1]=x;
}

void xuat(int a[],int n){
	for(int i=0;i<n; i++)
	cout<<a[i]<<" ";
	cout<<endl;
}

main(){
	int a[100],n;
	nhap(a,n);
	sort(a,n-1);
	xuat(a,n);
}
