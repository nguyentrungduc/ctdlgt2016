#include<iostream>

using namespace std;

int n,a[100];
void nhap(){
	cout<<"Nhap so phan tu :";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}

void sort(){
    for (int gap=n/2;gap>0; gap/= 2){
        for (int i=gap; i<n;i++){
            int temp=a[i];         
            int j;
            for(j=i; j>=gap&&a[j-gap]>temp;j -= gap){
                a[j]=a[j-gap];
            }
            a[j]=temp;
        }
    }
}

void xuat(){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

main(){
	nhap();
	sort();
	xuat();
}
