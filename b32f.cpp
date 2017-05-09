#include<iostream>
using namespace std;
int n,a[100],xuoi[100],nguoc[100],x[100];
void Init()
{
	cout<<"Nhap n :";
	cin>>n;
	for(int j=1;j<=n;j++)
	{
		a[j]=1;
	}
	for(int j=1;j<=2*n-1;j++)
	{
		xuoi[j]=1;
		nguoc[j]=1;
	}
}
void Result()
{
	for(int i=1;i<=n;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
void Try(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(a[j]==1&&xuoi[i-j+n]==1&&nguoc[i+j-1]==1)
		{
			x[i]=j;
		    a[j]=0;
			xuoi[i-j+n]=0;
			nguoc[i+j-1]=0;
			if(i==n)   Result();
			else Try(i+1);
			a[j]=1;
			xuoi[i-j+n]=1;
			nguoc[i+j-1]=1;
		}
	}
}
main()
{
	Init();
	Try(1);
}
