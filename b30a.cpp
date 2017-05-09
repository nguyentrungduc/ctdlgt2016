#include<iostream>
using namespace std;
int n,a[100],ok=1;
void Init()
{
	cout<<"Nhap n :";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=0;
	}
}
void Result()
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
}
void Next()
{
	int i=n;
	while(a[i]!=0&&i>0)
	{
		a[i]=0;
		i--;
	}
	if(i>0)a[i]=1;
	else ok=0;
}
main()
{
	int n,a[100];
	Init();
	while(ok==1)
	{
		Result();
		Next();
	}
}
