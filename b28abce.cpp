#include<bits/stdc++.h>
using namespace std;
void nhap(int a[],int&n)
{
	cout<<"Nhap so phan tu cua mang :"; 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void display(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}
}
void selectionsort(int a[],int n)
{
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;//min la vi tri phan tu nho nhat trong day con
		for(int j=i+1;j<n;j++)
		{
		    if(a[i]>a[j])   min=j;
		}
	    swap(a[i],a[min]);
	}
}
void bubblesort(int a[],int n)
{
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	if(a[i]>a[j])   swap(a[i],a[j]);
}
void insertionsort(int a[],int n)
{
	int key,j;
	for(int i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];   
			j=j-1;
		}
		a[j+1]=key;
	}
}
void merge(int a[],int l,int r,int m)
{
	int n1,n2;
    n1=m-l+1;
	n2=r-m;
	int L[n1];
	int R[n2];
	for(int i=0;i<n1;i++)    
	{
		L[i]=a[l+i];
	}
	for(int j=0;j<n2;j++)
	{
		R[j]=a[m+1+j];
	}
	int i=0,j=0,k=l;
	while(i<n1&&j<n2)
	{
		if(L[i]<=R[i])
		{
			a[k]=L[i];
			i++;
		}
		else{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}
void mergesort(int a[],int l,int r)
{
	int m;
	if(l<r)
	{
		m=(l+r-1)/2;
		mergesort(a,0,m);
		mergesort(a,m+1,r);
		merge(a,l,r,m);
	}
}
main()
{
	int a[100],n,m;
	nhap(a,n);
	mergesort(a,0,n-1);
	display(a,n);
}
