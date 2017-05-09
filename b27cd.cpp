#include<iostream>
#include<fstream>
#include<stack>

using namespace std;

struct canh{
	int dau;
	int cuoi;
}; 
int a[100][100],n,k;
canh c[100];

void nhap(){
	cout<<"So dinh :";  cin>>n;
	cout<<"So canh :";  cin>>k;
	for(int i = 1; i <=n;i++){
		for(int j = 1; j <=n;j++){
			a[i][j]=0;
		}
	}
	for(int i = 1; i <= k; i++){
		cin>>c[i].dau;
		cin>>c[i].cuoi;
		a[c[i].dau][c[i].cuoi] = 1;
	}
}

void inMaTran(){
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void danhsachke(){
		for(int i=1;i<=n;i++){
		cout<<"list("<<i<<") =";
		for(int j=1;j<=n;j++){
			if(a[i][j]==1){
			   cout<<j<<" ";
			}
		}
		cout<<endl;
	}
}

main(){
	nhap();
	inMaTran();
	danhsachke();
}
