#include<iostream>

using namespace std;

int a[100],n;

int max(int a,int b,int c){
	if(a>b&&a>c)   return a;
	else if(b>a&&b>c)   return b;
	else  return c;
}

void nhap(){
	cout<<"Nhap n :"; 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}

int maxCrossingSum(int arr[], int l, int m, int h) {
    int sum = 0, left_sum = INT_MIN, right_sum = INT_MIN;
    for (int i = m; i >= l; i--) { 
         sum = sum + arr[i];
         if (sum > left_sum) left_sum = sum;
    }
    sum = 0;
    for (int i = m+1; i <= h; i++) { 
        sum = sum + arr[i];
        if (sum > right_sum) right_sum = sum;
    } 
    return left_sum + right_sum; 
}

int maxSubArraySum(int a[], int l, int h) {
    if (l == h) return a[l];
    int m = (l + h)/2; 
    return max(maxSubArraySum(a, l, m),maxSubArraySum(a, m+1, h),maxCrossingSum(a, l, m, h));
}

main(){
	nhap();
	cout<<"Day con lon nhat la "<<maxSubArraySum(a,0,n)<<endl;
}
