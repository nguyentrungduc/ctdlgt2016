#include<iostream>
using namespace std;
int a[100],n;
void nhap(){
	cout<<"Nhap n :";
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
}

int sequentialSearch(int x){
    for(int i=0;i<n;i++){
        if(x==a[i]){ 
            return i;
        }
    }
    return -1;
}

main()
{
	nhap();
	cout<<sequentialSearch(2);
}
