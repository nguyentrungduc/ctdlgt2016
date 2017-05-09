#include<iostream>
using namespace std;

int a[100],c[100],n,m;
float d[100];
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
    cin>>m;
}

void sort(){
	for(int i=1;i<=n;i++){
		d[i]=(float)c[i]/a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(d[i]<d[j]){
				swap(d[i],d[j]);
				swap(a[i],a[j]);
				swap(c[i],c[j]);
			}
	    }
    }
}

void caitui(){
    sort();
    int kl=0,gt=0;
    for(int i=1;i<=n;i++){
        if(kl+a[i]<=m){
            cout<<"Chon vat co khoi luong "<<a[i]<<" gia tri"<<c[i]<<endl;
            kl=kl+a[i];
            gt=gt+c[i];
        }
    }
    cout<<"Khoi luong cai tui la :"<<kl<<endl;
    cout<<"Gia tri cua cai tui la :"<<gt<<endl;
}

main()
{
    nhap();
    sort();
    caitui();
}
