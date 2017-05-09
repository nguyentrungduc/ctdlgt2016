#include<iostream>
using namespace std;
int n,k,a[100],b[100],ok=1,s;
void Init()
{
	cout<<"Nhap n :"; 
	cin>>n;
	cout<<"Nhap s :";
	cin>>s;
	cout<<"Nhap k :";
	cin>>k;
	for(int i=1;i<=k;i++)
	a[i]=i;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
}
void Result()
{
	int t=0;
	for(int i=1;i<=k;i++)
	{
		t=t+b[a[i]];
	}
	if(t==s)
	{
		for(int i=1;i<=k;i++)
		{
			cout<<b[a[i]]<<" ";
		}
		cout<<endl;
	}
}
void Next()
{
	int i=k;
	while(i>0&&a[i]==n-k+i)    i--;
	if(i>0)
	{
		a[i]=a[i]+1;
		for(int j=i+1;j<=k;j++)
		a[j]=a[i]+j-i;
	}
	else ok=0;
}
main()
{
	Init();
	while(ok==1)
	{
		Result();
		Next();
	}
}
