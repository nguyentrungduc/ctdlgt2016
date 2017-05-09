#include<iostream>
using namespace std;  
int n,a[100],k,ok=1;
void Init()
{
	cout<<"Nhap n :";
	cin>>n;
	k=1;
	a[k]=n;
}
void Result()
{
	for(int i=1;i<=k;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void Next()
{
	int i=k,R,D,S;
	while(i>0&&a[i]==1)   i--;
	if(i>0)
	{
		a[i]=a[i]-1;   D=k-i+1;
		R=D/a[i];
		S=D%a[i];
		k=i;
		if(R>0)
		{
			for(int j=i+1;j<=i+R;j++)
			a[j]=a[i];
			k=k+R;
		}
		if(S>0)
		{
			k=k+1;
			a[k]=S;
		}
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
