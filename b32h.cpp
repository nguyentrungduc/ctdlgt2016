#include<iostream>
#include<math.h>

using namespace std;

int n,a[100],x[100],xopt[100],k,c=1000;

void nhap(){
	cout<<"Nhap n :";
	cin>>n;
	k=n/2;
	for(int i=1;i<=n;i++)
	cin>>a[i];
}

int tong(){
	int s=0;
	for(int i=1;i<=n;i++){
		s=s+a[i];
	}
	return s;
}

void init(){
	for(int i=1;i<n;i++){
		x[i]=i;
	}
}

void xuli(){
	int s=0;
	for(int i=1;i<=k;i++){
		s=s+a[x[i]];
	}
	if(fabs(s-(tong()-s))<c){
		c=fabs(s-(tong()-s));
		for(int i = 1; i <= k; i++){
		    xopt[i] = a[x[i]];
	    }
    }
}

void Try(int i)
{
	for(int j=x[i-1]+1;j<=n-k+i;j++)
	{
		x[i]=j;
		if(i==k)   xuli();
		else  Try(i+1);
	}
}

main()
{
	nhap();
	init();
	Try(1);
	for(int i=1;i<=k;i++){
		cout<<xopt[i]<<" ";
	}
}
	
