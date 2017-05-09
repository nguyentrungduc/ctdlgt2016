#include <iostream>
#include<fstream>
using namespace std;

struct canh{
	int dau;
	int cuoi;
	int trongso;
};

int n,k;
canh c[100];
int a[100][100];

void nhap()
{
	fstream f("ckhung.txt");
	f>>n>>k;
	for(int i = 1; i<=n;i++){
		for(int j = 1; j <=n;j++){
			a[i][j]=0;
		}
	}
	for(int i = 1; i <= k; i++){
		f>>c[i].dau;
		f>>c[i].cuoi;
		f>>c[i].trongso;
		a[c[i].dau][c[i].cuoi] = c[i].trongso;
		a[c[i].cuoi][c[i].dau] = c[i].trongso;
	}
}

void prim()
{
	int s=1;
	bool check[100];
	for( int i = 1; i <= n; i++)
	check[i] = true;
	check[s] = false;
	int v[100], vs = 1;
	v[vs] = s;
	while(1)
	{
		int min = 1000;
		int chon = 0;
		bool dau = true;
		for(int i = 1;i<= vs;i++)
		{
			for(int j=1;j<=k;j++)
			{
				if(c[j].dau==v[i]&check[c[j].cuoi])
				{
					if(c[j].trongso<min)
					{
						min=c[j].trongso;
						chon = j;
						dau = true;
					}
				}
				else if(c[j].cuoi==v[i]&check[c[j].dau])
				{
					if(c[j].trongso<min)
					{
						min=c[j].trongso;
						chon=j;
						dau=false;
					}
				}
			}
		}
		if(dau)
		{
			vs++;
			check[c[chon].cuoi] = false;
			v[vs] = c[chon].cuoi;
			a[c[chon].dau][c[chon].cuoi] = 1;
			a[c[chon].dau][c[chon].cuoi] = 1;
		}
		else
		{
			vs++;
			check[c[chon].dau] = false;
			v[vs] = c[chon].dau;
			a[c[chon].dau][c[chon].cuoi] = 1;
			a[c[chon].dau][c[chon].cuoi] = 1;
		}
		if( min==1000)
			break;
	}
}

void in( )
{
	for(int i=1;i<=n;i++){
		for( int j=i+1;j<=n;j++){
			if(a[i][j]==1){
				cout<<i<<" "<<j<<endl;
			}
		}
	}
}

main(){
	nhap();
	prim();
	in();
	return 0;
}

