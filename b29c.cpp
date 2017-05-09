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

int interpolationSearch(int x){ 
    int low=0,high=n-1,mid;
    while(a[low]<=x&&a[high]>=x){
        if(a[high]-a[low]==0)   return (low+high)/2;
        mid=low+((x-a[low])*(high-low))/(a[high]-a[low]);
        if(a[mid]<x)
		    low=mid+1;
        else if (a[mid]>x) 
		    high=mid-1;
        else return mid;
    }
    if(a[low]==x)
    return low;
    else return -1;
}

main(){
	nhap();
	cout<<interpolationSearch(3);
}
