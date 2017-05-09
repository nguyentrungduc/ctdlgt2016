#include<iostream>
#include<fstream>
#include<stack>

using namespace std;

struct canh{
	int dau;
	int cuoi;
	int trongso;
}; 
stack<int> s;
int a[100][100],chuaxet[100],n,k,sk;
canh c[100],kh[100];

void readFile(){
	fstream f("ckhung.txt");
	f>>n>>k;
	for(int i = 1; i <=n;i++){
		for(int j = 1; j <=n;j++){
			a[i][j]=0;
		}
	}
	for(int i = 1;i <=n;i++)
	chuaxet[i] = 1;
	for(int i = 1; i <= k; i++){
		f>>c[i].dau;
		f>>c[i].cuoi;
		f>>c[i].trongso;
		a[c[i].dau][c[i].cuoi] = c[i].trongso;
		a[c[i].cuoi][c[i].dau] = c[i].trongso;
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

int DFScaykhung(int i){
	int u;
	chuaxet[i] = 0;
	s.push(i);
	while(s.empty()==0){
		u = s.top();
		s.pop();
		for(int v = 1;v <=n;v++){
			if(a[u][v]!=0&&chuaxet[v] == 1){
				sk++;
				kh[sk].dau= u;
				kh[sk].cuoi=v;
				kh[sk].trongso=a[u][v];
				chuaxet[v] = 0;
				s.push(u);
				s.push(v);
				break;
			}
		}
	}
}
				
void ghikq(){
    cout<<n<<"   "<<sk<<endl;
	for(int i = 1 ;i< n;i++){
	    cout<<kh[i].dau<<" "<<kh[i].cuoi<<" "<<kh[i].trongso<<endl;
	}
}
		
main(){
	readFile();
	inMaTran();
	DFScaykhung(1);
	ghikq();
}
