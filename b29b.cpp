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

void sort(){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j])   
			    swap(a[i],a[j]);
		}
	}
}

int binarySearch(int x){
    int low=0;
    int hight=n-1;
    int mid=(low+hight)/2; 
    while(low<=hight){ 
        if(x>a[mid]) 
            low=mid+1; 
        else if (x<a[mid])
             hight=mid-1;
        else
             return mid; 
        mid=(low+hight)/2; 
    }
    return -1; 
}

main(){
	nhap();
	sort();
	cout<<binarySearch(3);
}
