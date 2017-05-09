#include<iostream>
using namespace std;
int n,a[100],ok=1;
void Init()
{
	cout<<"Nhap n:"; 
	cin>>n;
	for(int i=1;i<=n;i++)
	a[i]=i;
}
void Result()
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void Next()
{
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
		
