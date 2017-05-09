#include<iostream>
#include<fstream>

using namespace std;

struct canh{
	int dau;
	int cuoi;
	int trongso;
	int danhdau;
}; 
int a[100][100],n,k,father[100];
canh c[100];

void readFile(){
	fstream f("ckhung.txt");
	f>>n>>k;
	for(int i = 1; i <=n;i++){
		for(int j = 1; j <=n;j++){
			a[i][j]=0;
		}
	}
	for(int i = 1;i <=n;i++)
	father[i]= -1;
	for(int i = 1; i <= k; i++){
		f>>c[i].dau;
		f>>c[i].cuoi;
		f>>c[i].trongso;
		c[i].danhdau=1;
		a[c[i].dau][c[i].cuoi] = c[i].trongso;
		a[c[i].cuoi][c[i].dau] = c[i].trongso;
	}
}

void sort(){
	for(int i = 1;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			if(c[i].trongso>c[j].trongso){
				canh temp=c[i];
				c[i]=c[j];
				c[j]=temp;
			}
		}
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

int find(int x){
	while(father[x]!=-1){
		x=father[x];
	}
	return x;
}

void connect(int i,int j){
	int x = father[i]+father[j];
    if(father[i]>father[j])
    {
        father[i]=j;
        father[j]=x;
    }
    else{
        father[j]=i;
        father[i]=x;
    }
}

void kruskal(){
	int ncanh=0,minl=0;
    for(int i=1;i<=k;i++){
    	int a=find(c[i].dau);  
    	int b=find(c[i].cuoi);  
    	if(a!=b){
    		ncanh++;
    		//connect(a,b);
    		c[i].danhdau=1;
    		minl=minl+c[i].trongso;
    		cout<<c[i].dau<<" "<<c[i].cuoi<<endl;
    	}
    	if(ncanh==k-1)   break;
    }
    cout<<"Cay khung nho nhat co gia tri "<<minl<<endl;
}
	
main(){
	readFile();
	sort();
	inMaTran();
	kruskal();
}
