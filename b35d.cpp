#include<iostream>
#include<math.h>

using namespace std;

main(){
	int n,k,a[100];
	cout<<"Nhap n :";
	cin>>n;
	cout<<"Nhap k :";
	cin>>k;
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=n+1;i++){
	    if (i<=k) a[i]=2*a[i-1];// khi do n van be hon k nen lay sau tuy y
        else a[i]=2*a[i-1]-2*a[i-k-1]+pow(2,i-k-1);
    }
    cout<<a[n+1];
}
