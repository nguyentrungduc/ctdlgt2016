#include<iostream>
#include<fstream>

using namespace std;
int **a, *chuaxet, n, *d, *dmin, t = 0, m = 100000;

void docFile(){
	fstream f("dothi6.txt",ios::in);
	f>>n;
	a = new int *[n];
	for(int i = 1; i <= n; i++){
		a[i] = new int [n];
		for(int j = 1; j <= n; j++)
		f>>a[i][j];
	}
	f.close();
}

void xuatDoThi(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
} 

void init(){
	chuaxet = new int [n];
	d = new int [100];
	for(int i = 1; i <= n; i++)
	chuaxet[i] = 1;
}

void doicho(){
	for(int i = 1; i <= n + 1; i++){
		dmin[i] = d[i];
	}
} 

void result(){
	for(int i = 1; i <= n+1; i++){
		if(i <= n)    cout<<dmin[i]<<"->";
		else cout<<dmin[i];
	}
	cout<<endl;
}

void dulich(int k){
	for(int i = 1; i <= n; i++){
		if(a[d[k-1]][i] != 0 && chuaxet[i] == 1){
			d[k] = i;
			chuaxet[i] = 0;
			t = t + a[d[k - 1]][d[k]];
			if(k <= n )   dulich(k + 1);
			else if(d[k] == d[1] && k == n + 1){
				if(t < m){
					doicho();
					m = t;
				}
			}
			chuaxet[i] = 1;
			t = t - a[d[k - 1]][d[k]];
		}
	}
}
  
main()
{
	docFile();
	xuatDoThi();
	dmin = new int [100];
	init();
	for(int i = 1; i <= n; i++){
		init();
		d[1] = i;
		dulich(2);
	}
	cout<<"Hanh trinh co chi phi nho nhat : "<<m<<endl;
	cout<<"Duong di do la :";
	result();
}
