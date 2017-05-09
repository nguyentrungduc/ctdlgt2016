#include<iostream>
using namespace std;
int fibo(int n){
	if(n<3)   return 1;
	else return(fibo(n-1)+fibo(n-2));
	}
int mu(int x,int n)
{
	if(n==0)    return 1;
	else   return(x*mu(x,n-1));
}
int giaithua(int n)
{
	if(n==0)   return 1;
	else   return(n*giaithua(n-1));
}  
int UCLN(int a,int b)
{
	if(a==b)   return a;
	if(a>b)   return(UCLN(a-b,b));
	if(a<b)   return(UCLN(a,b-a));
}
int tongcs(int n)
{
	if(n<10)   return n;
	else  return(n%10+tongcs(n/10));
}
void doi(int so, int coso) {
    if (so != 0) {
        doi(so / coso, coso);
        cout << "0123456789ABCDEF"[so % coso];
    }
}
void daoxau(char s[])
{
	if(strlen(s)==0)   return;
	else{
		cout<<s[strlen(s)-1];
		s[strlen(s)-1]=NULL;
	}
	daoxau(s);
}
int tongxau(int a[],int n)
{
	if(n==1)   return a[n-1];
	else     return tongxau(a,n-1)+a[n-1];
}
int tim(int a[],int n,int x)
{
	if(n==0)   return -1;
	if(x==a[n-1])    return n-1;
	else     return tim(a,n-1,x);
}
int tong(int n)
{
	if(n==1)   return 1;
	else  return(n+tong(n-1));
}

main()
{
	cout<<tong(9);
//	int a[100],n,x;
//	cin>>n;
//	cin>>x;
//	for(int i=0;i<n;i++)
//	{
//	    cin>>a[i];
//	}
//	cout<<tim(a,n,x);
//	cin>>s;
//	daoxau(s);
//	cout<<endl;
//	coso2(15);
//	cout<<endl;
//	cout<<tongcs(10)<<endl;
//	cout<<UCLN(39,13)<<endl;
//	cout<<fibo(9)<<endl;
//	cout<<mu(2,3)<<endl;
//	cout<<giaithua(4)<<endl;
}
