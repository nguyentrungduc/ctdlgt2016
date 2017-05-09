#include<iostream>

using namespace std;

int n,a[100][100],x[100],fmin=10000,xopt[100],ok=1;

void nhap(){
	cout<<"Nhap n :";  cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
}

void init(){
	for( int i=1; i<=n;i++) {
		x[i] = i;
	}
}
	
void result(){
	int s = 0;
	for( int i = 1; i < n; i++) {
		s += a[x[i]][x[i+1]];
	}
	s += a[x[n]][x[1]];
	if( s < fmin) {
		fmin = s;
		for( int i = 1; i <= n; i++) {
			xopt[i] = x[i];
		}
	}
}

void next(){
	int i=n-1;
	while(i>1&&x[i]>x[i+1])
	{
		i--;
	}
	if(i>1)
	{
		int j=n;
		while(x[i]>x[j])   j--;
		swap(x[i],x[j]);
		int s=n,r=i+1;
		while(r<=s)
		{
			int t;
	        swap(x[r],x[s]);
			r++;
			s--;
		}
	}
	else ok=0;
}

main(){
	nhap();
	init();
	cout<<"Duong di ngan nhat co gia tri :"<<fmin<<endl;
	cout<<"Duong di la :";
	while(ok==1)
	{
		result();
		next();
	}
	for(int i=1;i<=n;i++){
		cout<<xopt[i]<<" ";
	}
	cout<<" "<<1;
}
