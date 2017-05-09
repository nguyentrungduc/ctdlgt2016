#include<iostream>
using namespace std;
int n,a[100],ok=1,m=0,gt=0,x[100],c[100],b,xmax[100]={0},t=0;
void Init()
{
	for(int i=1;i<=n;i++)
	{
		x[i]=0;
	}
}
void Result()
{

	for(int i=1;i<=n;i++)
	{
		m=m+a[i]*x[i];
	}
	if(m<=b)
	{
		for(int i=1;i<=n;i++)
		gt=gt+c[i]*x[i];
	}
	else  gt=0;
	if(gt>t)
	{
		t=gt;
		for(int i=1;i<=n;i++)
		xmax[i]=x[i];
	}
	gt=0,m=0;
}
void Next()
{
	int i=n;
	while(x[i]!=0&&i>0)
	{
		x[i]=0;
		i--;
	}
	if(i>0)x[i]=1;
	else ok=0;
}
main()
{
	cout<<"Nhap so vat :";
	cin>>n;
	cout<<"Nhap khoi luong lon nhat ma cai tui chua duoc :"; 
	cin>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	Init();
	while(ok==1)
	{
		Result();
		Next();
	}
	cout<<t<<endl;
	for(int i=1;i<=n;i++)
	cout<<xmax[i]<<" ";
}
