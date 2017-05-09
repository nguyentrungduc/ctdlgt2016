#include<iostream>
using namespace std;
int s,a[100],b[100],n,ok=1;
void Init1()
{
	cout<<"Nhap n :"; 
	cin>>n;
	cout<<"Nhap s :";
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
}
void Init2(int k)
{
	for(int i=1;i<=k;i++)
		a[i]=i;
}
void Result(int k)
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
void Next(int k)
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
	int k=1;
    Init1();
    for(int k=1;k<=n;k++)
    {
    	Init2(k);
	    while(ok==1)
	    {
		    Result(k);
		    Next(k);
	    }
	    ok=1;
    }
}
