#include<iostream>
#include<queue>
using namespace std;
int n,l[100],OPT=0;
queue<int> q;
void Init()
{
	cout<<"Nhap so day :";
	cin>>n;
	cout<<"Nhap do dai cua tung doan day :";
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
	}
}
void Sort()
{
	for(int i=1;i<=n;i++)
    {
    	for(int j=i+1;j<=n;j++)
    	{
    		if(l[i]>l[j])   swap(l[i],l[j]);
    	}
    }
}
void Greedy()
{
	for(int i=1;i<n;i++)
	{
		l[i+1]=l[i]+l[i+1];
		l[i]=0;
		OPT=OPT+l[i+1];
		Sort();
	}
	cout<<"Chi phi noi day nho nhat la :"<<OPT<<endl;
}
main()
{
	Init();
	Greedy();
}
			
