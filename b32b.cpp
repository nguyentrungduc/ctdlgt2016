#include<iostream>
using namespace std;
int n,k,a[100];
void Init()
{
	cout<<"Nhap n :";
	cin>>n;
	cout<<"Nhap k :";
	cin>>k;
}
void Result()
{
	for(int i=1;i<=k;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
}
void Try(int i)
{
	for(int j=a[i-1]+1;j<=n-k+i;j++)
	{
		a[i]=j;
		if(i==k)  Result();
		else  Try(i+1);
	}
}
main()
{
	Init();
	Try(1);
}
