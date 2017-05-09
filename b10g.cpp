#include<iostream>
#include <cstdlib>
#include<stack>
using namespace std;
int so(char s)
{
    if((int(s)>=48&&int(s)<=57)) return 1;
    else  return 0;
}
int toantu(char s)
{
    if(s=='+'||s=='-'||s=='*'||s=='/'||s=='%'||s=='^') return 1;
    else return 0; 
}
int tinhgiatri(char a[])
{
	stack <int> s;
	int m,n,k,x1;
	for(int i=0;i<strlen(a);i++)
	{
		char x=a[i];
		if(so(x)==1) {
			x1=x-'0';   s.push(x1);
		}
		switch(x)
		{
			case'+':
				{
					m=s.top();
					s.pop();
					n=s.top();
					k=m+n;
					s.push(k);
				}break;
			case'-':
				{
					m=s.top();
					s.pop();
					n=s.top();
					k=m-n;
					s.push(k);
				}break;
			case'*':
				{
					m=s.top();
					s.pop();
					n=s.top();
					k=m*n;
					s.push(k);
				}break;
			case'/':
				{
					m=s.top();
					s.pop();
					n=s.top();
					k=m/n;
					s.push(k);
				}break;
			case'%':
				{
					m=s.top();
					s.pop();
					n=s.top();
					k=m%n;
					s.push(k);
				}break;
			case'^':
				{
					m=s.top();
					s.pop();
					n=s.top();
					for(int i=0;i<n;i++)
					{
					    k=m*m;
					}
					s.push(k);
				}break;
		}
	}
	return s.top();
}
main()
{
	char a[100];
	cout<<"Nhap vao mot bieu thuc hau to :";
	cin>>a;
	cout<<"Gia tri la : " <<tinhgiatri(a);
}
					
