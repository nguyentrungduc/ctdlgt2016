#include<iostream>
#include<fstream>

using namespace std;
struct dinh{
	int s;
	int dd;
	int xet;
};
int a[100][100],n,b[100]={0};
dinh d[100];

void docfile(){
	fstream fdoc("Graphcoloring.txt");
	fdoc>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			fdoc>>a[i][j];
		}
	}
}

void inmatran(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void init(){
	for(int i=1;i<=n;i++){
		d[i].s=i;
		d[i].dd=0;
		d[i].xet=0;	
	}
}

int tinhbac(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[i]=b[i]+a[i][j];
		}
	}
}

void sort(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(b[i]<b[j]){
				swap(b[i],b[j]);
				swap(d[i].s,d[j].s);
				swap(d[i].dd,d[j].dd);
			}
		}
	}
}

void xuat(){
	for(int i=1;i<=n;i++){
		cout<<d[i].s<<" ";
	}
}

void graphcoloring(){
	int k=1;
	for(int i=1;i<=n;i++){
		if(d[i].dd==0&&d[i].xet==0){
		    d[i].dd=k;     
			for(int j=1;j<=n;j++){
			    if(a[d[i].s][d[j].s]==0&&d[j].xet==0)
			    {
			    	//int t=d[j].s;
				    d[j].dd=k;
				    d[j].xet=1;
			    }
		    }
		    k++;
	    }
	}
}
				   
void xuat1(){
	for(int i=1;i<=n;i++){
		cout<<d[i].s<<" "<<d[i].dd<<endl;
	}
}
main(){
	docfile();
	init();
	tinhbac();
	sort();
	graphcoloring();
	xuat1();
}
