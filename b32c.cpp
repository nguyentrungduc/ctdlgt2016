#include<iostream>
using namespace std;
int a[100],n,chuaxet[100];
void Init()
{
	cout<<"Nhap n:";
	cin>>n;
	for(int j=1;j<=n;j++)
	chuaxet[j]=1;
}
void Result()
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
}
void Try(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(chuaxet[j]==1)
		{
			a[i]=j;   chuaxet[j]=0;
			if(i==n)  Result();
			else   Try(i+1);
			chuaxet[j]=1;
		}
    }
}
main()
{
	Init();
	Try(1);
}

