#include<iostream>
#include<fstream>

using namespace std;

int n,a[100][100],s,t,d[100],truoc[100],check[100];
void docFile(){
	fstream fdoc("dijkstra.txt");
	fdoc>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			fdoc>>a[i][j];
			if(a[i][j]==0)   a[i][j]=32000;
		}
	}
}

void kq(){
	cout<<"Duong di ngan nhat la :";
	int i=truoc[t];
	cout<<t;
	while(i!=s){
		cout<<i<<" ";
		i=truoc[i];
	}
	cout<<s;
	cout<<"Duong di co do dai la "<<d[t];
}
void dijkstra(){
	int u,min;
	cout<<"Duong di tu :";  cin>>s;
	cout<<"den ";  cin>>t;
	for(int v=1;v<=n;v++){
		d[v]=a[s][v];
		truoc[v]=s;
		check[v]=0;
	}//ham khoi tao
	check[s]=1;
	truoc[s]=0;
	d[s]=0;
	while(check[t]==0){
		min=2000;
		for(int v=1;v<=n;v++){
			if(check[v]==0&&min>d[v]){
				min=d[v];
				u=v;
			}
		}
		check[u]=1;
		if(check[u]==1){
			for(int v=1;v<=n;v++){
				if(check[v]==1&&d[u]+a[u][v]<d[v]){
					d[v]=d[u]+a[u][v];
					truoc[v]=u;
				}  
			}
		}
    }
}

main(){
	docFile();
	dijkstra();
	kq();
}
