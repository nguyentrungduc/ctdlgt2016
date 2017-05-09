#include<iostream>

using namespace std;

int a[100],n,ok=1;

void nhap(){
	cout<<"Nhap n :";
	cin>>n;
}

void init(){
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
}

int kt(){
	for( int i=1;i<n;i++) {
		int p=n-i+a[i];
		int e=i+a[i]-1;
		for( int j=i+1;j<=n;j++) {
			int p2=n-j+a[j];
			int e2=j+a[j]-1;
			if( p2 == p | e2 == e)
				return 0;
		}
	}
	return 1;
}

void next(){
	int i=n-1;
	while(i>0&&a[i]>a[i+1])
	{
		i--;
	}
	if(i>0)
	{
		int j=n;
		while(a[i]>a[j])   j--;
		swap(a[i],a[j]);
		int s=n,r=i+1;
		while(r<=s)
		{
			int t;
	        swap(a[r],a[s]);
			r++;
			s--;
		}
	}
	else ok=0;
}

void result(){
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

main(){ 
    nhap();
    init();
    while(ok==1)
	{
		if(kt()==1)   result();
		next();
	}
}
