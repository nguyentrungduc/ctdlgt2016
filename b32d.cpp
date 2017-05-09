#include<iostream>
using namespace std;

int a[100],c[100],n,b,m[100],weight=0,cost=0,x[100],ma=0;
float d[100];
void nhap(){
	cout<<"So do vat ";
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<"Trong luong do vat thu "<<i<<" :";
		cin>>a[i];
		cout<<"Gia tri do vat thu "<<i<<" :";
		cin>>c[i];
	}
	cout<<"Khoi luong co the dung cua tui :";
	cin>>b;
}

void sort(){
	for(int i=1;i<=n;i++){
		d[i]=(float)c[i]/a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(d[i]<d[j]){
				swap(a[i],a[j]);
				swap(c[i],c[j]);
			}
	    }
    }
}
			
void update(){
	if(cost>ma){
		for(int i=1;i<=n;i++){
			m[i]=x[i];
		}
		ma=cost;
	}
}

void result(){
    cout<<"Ket qua :"<<ma<<endl;
    cout<<"Phuong an :"<<endl;
    for(int i=1;i<=n;i++){
    	cout<<m[i]<<" tui khoi luong "<<a[i]<<" gia tri "<<c[i]<<endl;
    }
}

void backtrack(int i){
	int t=(b-weight)/a[i];
	for(int j=t;j>=0;j--){
		x[i]=j;
		weight=weight+a[i]*x[i];
		cost=cost+c[i]*x[i];
		if(i==n)   update();
		else if(cost+c[i+1]*(b-weight)/a[i+1]>ma)
		backtrack(i+1);
		weight=weight-a[i]*x[i];
		cost=cost-c[i]*x[i];
	}
}

main(){
	nhap();
	sort();
	backtrack(1);
	result();
}
