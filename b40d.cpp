#include<iostream>
#include<fstream>

const int maxc=10000;
using namespace std;

int a[100][100],n,truoc[100],d[100],s,f;

void docFile(){
	fstream fdoc("bellman-ford.txt");
	fdoc>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			fdoc>>a[i][j];
			if(a[i][j]==0)   a[i][j]=10000;
		}
	}
}

void nhap(){
	cout<<"Nhap dinh s :";  cin>>s;
	cout<<"Nhap dinh cuoi :";   cin>>f;
}

void init(){
	for(int i=1;i<=n;i++){
		d[i]=a[s][i];
		truoc[i]=s;
	}
}

void result(){
	if(d[f]==maxc)   cout<<"Khong co duong di"<<endl;
	else{
		cout<<"Do dai duong di ngan nhat la :"<<d[f]<<endl;
		while(f!=s){
			cout<<f<<"<-";
			f=truoc[f];
		}
		cout<<s;
	}
}

void bellmanford(){
	d[s]=0;
	for(int k=1;k<=n-2;k++){
		for(int v=1;v<=n;v++){
			if(v!=s){
				for(int u=1;u<=n;u++){
					if(d[v]>d[u]+a[u][v]){
						d[v]=d[u]+a[u][v];
						truoc[u]=v;
					}
				}
			}
		}
	}
}

main(){
	docFile();
    nhap();
    init();
	bellmanford();
	result();
}	
