#include<iostream>
using namespace std;

int fib[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,
377, 610, 98,1597, 2584, 4181, 6765, 10946, 17711,
28657, 46368, 75025, 121393, 196418, 317811,
514229, 832040, 1346269, 2178309, 3524578,
5702887, 9227465, 14930352, 24157817,
39088169, 63245986, 102334155, 165580141
};
int a[100],n;

void nhap(){
	cout<<"Nhap n :";
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
}

int fibSearch(int x){
    int inf=0,pos,k;
    int kk=-1,nn=-1;
    if(nn!=n){ 
	    k=0;
        while(fib[k]<n) 
        k++;   //k la vi tri so Fibonacci nho hon n
    }
    else k=kk; 
    while(k>0){ 
        pos=inf+fib[--k]; 
        if((pos>=n)||(x<a[pos]));
        else if(x>a[pos]){
            inf=pos+1;
			k--;
        }
        else
        return pos; 
    }
    return -1; 
}

main(){
	nhap();
	cout<<fibSearch(3);
}
