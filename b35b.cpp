#include<iostream>

using namespace std;

main(){
	int  F[100][100],n;
	cout<<"Nhap n :"; cin>>n; 
	for ( int j=0;j<=n;j++) F[0][j]=0; 
	F[0][0]=1;
	for (int m=1;m<=n;m++){
		for(int v=0;v<=n;v++){ // f[v][m] la cach phan tich so v thanh cac so nguyen nho hon hoac bang m
			if (m>v) F[m][v]=F[m-1][v];
			else F[m][v]=F[m-1][v]+F [m][v-m];
		}
	}
	cout<<"Ket qua :"<<F[n][n]<<endl;
}
