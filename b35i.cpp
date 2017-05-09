#include<iostream>
#include<stack>
using namespace std;

main(){
	int a[100],l[100],n,truoc[100];
	cout<<"Nhap n :";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	l[1]=1;
	truoc[1]=0;
	for(int i=2;i<=n;i++){
		l[i]=1;
		truoc[i]=0;
		for(int j=i-1;j>=1;j--){
			  if (a[j]<=a[i]&&l[i]<=l[j]){
			      l[i]=l[j]+1;
			      truoc[i]=j;
              }
        }
    }
    cout<<"So phan tu day tang dai nhat la :"<<l[n]<<endl;
    for(int i=1;i<=n;i++){
    	cout<<l[i]<<" ";
    }
    cout<<endl;
    stack<int> s;
    int i=n;
    for(int j=n-1;j>=1;j--)
    if(l[j]>l[i]) i=j;
    while(i>0)
    {
    	s.push(a[i]);
        i=truoc[i];
    }
    while(!s.empty()){
    	int x=s.top();
    	cout<<x<<" ";
    	s.pop();
    }
}
