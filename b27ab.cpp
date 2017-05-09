#include<iostream>
using namespace std;

int a[100][100],n;
void nhap(){
	cout<<"Nhap so dinh :";
	cin>>n;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
		    cout<<"a["<<i<<"]["<<j<<"] ="; 
			cin>>a[i][j];
		}
	}
}

void danhsachcanh(){
    for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
		    if(a[i][j]==1){
			    cout<<i<<" "<<j<<endl;
			}
		}
	}
}

void danhsachke(){
	for(int i=1;i<=n;i++){
		cout<<"list("<<i<<") =";
		for(int j=1;j<=n;j++){
			if(a[i][j]==1){
			   cout<<j<<" ";
			}
		}
		cout<<endl;
	}
}
	
main(){
    nhap();
	danhsachcanh();
	danhsachke();
} 
