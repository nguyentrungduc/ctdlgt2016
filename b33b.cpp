#include<iostream>
using namespace std;
int n,s[100],f[100],OPT[100];
void Init()
{
	cout<<"Nhap so hoat dong :";
	cin>>n;
	cout<<"Nhap thoi gian bat dau cua tung hoat dong :";
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	cout<<"Nhap thoi gian ket thuc cua tung hoat dong :";
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(f[i]>f[j])  {
				swap(s[i],s[j]);
				swap(f[i],f[j]);
			}
		}
	}
}
void Delete(int a[],int n,int vt)
{
	for(int i=vt;i<=n;i++)
	{
		a[i]=a[i+1];
		n=n--;
	}
}
void Greedy()
{
	int d=1;  //d la so hoat dong co the lam dc
	OPT[1]=1;    
	for(int j=2;j<=n;j++)
	{
		if(s[j]>=f[d])
		{
			OPT[++d]=j;
			d=j;
		}
	}
	cout<<"Cach chon cong viec toi uu la :";
	for(int i=1;i<=d;i++)
	{
		cout<<OPT[i]<<" ";
	}
}
main()
{
	Init();
	Greedy();
}
