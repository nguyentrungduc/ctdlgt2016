#include<iostream>
using namespace std;

void nhap(int a[],int&n){
	cout<<"nhap so phan tu :";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}

void xuat(int a[],int n){
	for(int i=0;i<n; i++)
	cout<<a[i]<<" ";
	cout<<endl;
}

void sort(int a[],int i,int n){
	if(i>=n-1)    return ;
	int vt=i;
	for(int j=i+1;j<n;j++){
		if(a[j]<a[vt]){
			vt=j;
		}
	}
	swap(a[i],a[vt]);
	sort(a,i+1,n);
}
	
main(){
	int a[100],n;
	nhap(a,n);
	sort(a,0,n);
	xuat(a,n);
}
