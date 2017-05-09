#include<iostream>

using namespace std;
 
int a[100],n;

void nhap(){
	cout<<"Nhap n :";   cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
}

int getMax(){
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
 
void countSort(int exp){
    int output[n]; 
    int i, count[10] = {0};
    for (i = 0; i < n; i++){
        count[ (a[i]/exp)%10 ]++;
    }
    for (i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--){
        output[count[ (a[i]/exp)%10 ] - 1] = a[i];//gan vi tri sau sx
        count[ (a[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        a[i] = output[i];
}
 
void xuat(){
    for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void radixsort(){
    int m = getMax();
    for (int exp = 1; m/exp > 0; exp *= 10){
        countSort(exp);
        xuat();
    }
}
 
main()
{
    nhap();
    radixsort();
    //xuat
}

