#include<iostream>
#include<fstream>

using namespace std;
int **a, *chuaxet, n, *d, dem1 = 0, dem2 = 0;

void docFile(){
	fstream f("dothi5.txt",ios::in);
	f>>n;
	a = new int *[n];
	for(int i = 1; i <= n; i++){
		a[i] = new int [n];
		for(int j = 1; j <= n; j++)
		f>>a[i][j];
	}
	f.close();
}

void xuatDoThi(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
} 

void init(){
	chuaxet = new int [n];
	d = new int [100];
	for(int i = 1; i <= n; i++)
	chuaxet[i] = 1;
}

void result1(){
	for(int i = 1; i <= n+1; i++){
		if(i <= n)    cout<<d[i]<<"->";
		else cout<<d[i];
	}
	cout<<endl;
	dem1++;
}

void result2(){
	for(int i = 1; i <= n; i++){
		if(i < n)    cout<<d[i]<<"->";
		else cout<<d[i];
	}
	dem2++;
	cout<<endl;
}

void cCHamilton(int k){
	for(int i = 1; i <= n; i++){
		if(a[d[k-1]][i] == 1 && chuaxet[i] == 1){
			d[k] = i;
			chuaxet[i] = 0;
			if(k <= n )   cCHamilton(k + 1);
			else if(d[k] == d[1] && k == n + 1)   result1();
			chuaxet[i] = 1;
		}
	}
}

void dDHamilton(int k){
	chuaxet[d[k - 1]] = 0;
	for(int i = 1; i <= n; i++ ){
		if(a[d[k-1]][i] == 1 && chuaxet[i] == 1){
			d[k] = i;
			chuaxet[i] = 0;
			if(k < n )   dDHamilton(k+1);
			else   result2();
			chuaxet[i] = 1;
		}
	}
}
  
main(){
	docFile();
	init();
	int choice;
	do{
		cout<<endl<<endl<<endl<<"        ******************************";
		cout<<endl << "Nhap 0: Ket thuc chuong trinh"<<endl;
		cout<<"Nhap 1: Xuat do thi trong file"<<endl;
		cout<<"Nhap 2: Tim chu trinh hamilton"<<endl;
		cout<<"Nhap 3: Tim duong di hamilton"<<endl;
		cout<<"Chon: "; cin>>choice; cin.ignore();
	switch (choice){
			case 1:{
				system("cls");
				init();
				xuatDoThi();
				break;
			}
			case 2:{
				system("cls");
				for(int i = 1; i <= n; i++){
		            init();
		            d[1] = i;
		            cCHamilton(2);
	            }
	            if(dem1 == 0)   cout<<"Do thi khong co chu trinh Hamilton"<<endl;
				break;
			}
			case 3:{
				system("cls");
				for(int i = 1; i <= n; i++){
		            init();
		            d[1] = i;
		            dDHamilton(2);
	            }
	            if(dem2 == 0)   cout<<"Do thi khong co duong di Hamilton"<<endl;
				break;
			}
    }
	}while(choice != 0);
}
	
	
	

			
	
	


	

			
	
	


