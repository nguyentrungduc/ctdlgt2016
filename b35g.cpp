#include<iostream>

using namespace std;
int  a[100],c[100],f[100][100],n,b;

void nhap(){
    cout<<"Nhap so do vat :";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Khoi luong cua vat thu "<<i<<" la :";
        cin>>a[i];
        cout<<"Gia tri cua vat thu "<<i<<" la :";
        cin>>c[i];
    }
    cout<<"Kich thuoc cai tui :"; 
    cin>>b;
}

void caitui() {
     for (int i=1;i<=n;i++){
         for(int j=0;j<=b;j++){//f[i][j] la gia tri lon nhat co the mang bang cach chon cac goi tu 1 den i, voi trong luong toi da la j
             f[i][j]=f[i-1][j];
             if(j>=a[i]&&f[i][j]<f[i-1][j-a[i]]+c[i]) 
                 f[i][j]= f[i-1][j-a[i]]+c[i];        
         }
    } 
}

void xuat(){
     cout<<"Gia tri lon nhat:"<<f[n][b]<<endl;
     cout<<"Do vat dem theo:"<<endl;
     while(n!=0) {
         if(f[n][b]!=f[n-1][b]) {
             cout<<n<<"   ";
             b=b-a[n];
         }
         n--;
     }                           
}

main(){	
    nhap();
	caitui(); 
	xuat();
}
