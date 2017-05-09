#include<iostream>
#include<stack> 

using namespace std;

int n,s[100],f[100],c[100],truoc[100],l[100];

void nhap()
{
	cout<<"Nhap so khach hang muon thue :";
	cin>>n;
	cout<<"Nhap thoi gian bat dau va ket thuc va gia thue cua tung khach hang :";
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		cin>>f[i];
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(f[i]>f[j]){
				swap(s[i],s[j]);
				swap(f[i],f[j]);
				swap(c[i],c[j]);
			}
		}
	}
}

void thuemay(){
	l[1]=1;
	truoc[1]=0;
	for(int i=2;i<=n;i++){
		l[i]=c[i];
		truoc[i]=0;
		for(int j=i-1;j>=1;j--){
			  if(f[j]<=s[i]&&l[i]<l[j]+c[i]){
			      l[i]=l[j]+c[i];
			      truoc[i]=j;
              }
        }
    }
    cout<<"Khoan tien lon nhat co the nhan duoc la :"<<l[n];
    cout<<"Cac khach hanh lan luot duoc thue la :";
    stack<int> s;
    int i=n;
    for(int j=n-1;j>=1;j--)
    if(l[j]>l[i]) i=j;
    while(i>0)
    {
    	s.push(i);
        i=truoc[i];
    }
    while(!s.empty()){
    	int x=s.top();
    	cout<<x<<" ";
    	s.pop();
    }
}

main(){
	nhap();
	thuemay();
}
