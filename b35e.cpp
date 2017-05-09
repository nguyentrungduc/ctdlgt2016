#include<iostream>

using namespace std;
	
main(){
	int n,k,a[100][100]={0};
	for(int i=1;i<=100;i++){
		a[i][0]=1;
		a[i][1]=i;
	}
	for(int j=1;j<=100;j++){
	    a[1][j]=1;
	}
	for(int i=2;i<=100;i++){
		for(int j=2;j<=100;j++){
			a[i][j]=a[i-1][j]+a[i][j-1];
		}
	}
	cout<<"Nhap n :";  cin>>n;
	cout<<"Nhap k :";  cin>>k;
	cout<<a[n][k];
}
	
