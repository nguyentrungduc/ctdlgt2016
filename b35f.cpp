#include<iostream>

using namespace std;
 
int a[100],n,k;
void nhap(){
	cout<<"Nhap k :";    cin>>k;
	cout<<"Nhap n :";    cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}

int kt(){
    int f[k+1][n+1];// f[i][j] =1 neu trong day tu 0 den j co the tao ra tong i 
    for (int i = 0; i <= n; i++)
        f[0][i] = 1;
    for (int i = 1; i <= k; i++)
        f[i][0] = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i][j-1];
            if (i >= a[j-1])
            f[i][j] = f[i][j] || f[i - a[j-1]][j-1];
        }
    }
    return f[k][n];
}
 
main()
{
	nhap();
	if(kt()==1)   cout<<"Trong day co day con tao ra tong bang "<<k<<endl;
	else    cout<<"Trong day khong co day con tao ra tong bang "<<k<<endl;
 
}
