#include<iostream>
#include<fstream>

const int maxc=10000;
using namespace std;

int a[100][100],d[100][100],s[100][100],u,v,n;
void docFile(){
	fstream fdoc("floy.txt");
	fdoc>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			fdoc>>a[i][j];
			if(a[i][j]==0)   a[i][j]=10000;
		}
	}
}

void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=a[i][j];
			s[i][j]=i;// sau i la j
		}
	}
}

void result(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<"Duong di nho nhat tu "<<i<<" den "<<j<<" la :"<<d[i][j]<<endl;
		}
	} 
}

void floy(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=a[i][j];
			if(d[i][j]==maxc)   s[i][j]=0;
			else  a[i][j]=j;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][k]!=maxc&&d[i][j]>(d[i][k]+d[k][j])){
					d[i][j]=d[i][k]+d[k][j];
					s[i][j]=s[i][k];// sau i la k chu ko phai j
				}
			}
		}
	}
}

main(){
	docFile();
	init();
    floy();
    result();
}
