#include<iostream>
using namespace std;
//tim luon gtnn va ggtnn trong 1 vong while 
void nhap(int a[],int&n)
{
	cout<<"Nhap so phan tu cua mang :"; 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}

void xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}
}

void shakersort(int a[],int n)
{
	int left=0;
	int right=n-1;
	int k=0;
	while(left<right)
	{
		for(int i=left;i<right;i++)
		{
			if(a[i]>a[i+1])
			{
				swap(a[i],a[i+1]);
				k=i;
			}
		}
		right=k;
		for(int i=right;i>left;i--)
		{
			if(a[i]<a[i-1])
			{
				swap(a[i],a[i-1]);
				k=i;
			}
		}
		left=k;
	}
}

main(){
	int a[100],n;
	nhap(a,n);
	shakersort(a,n);
	xuat(a,n);
}
