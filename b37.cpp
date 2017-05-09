#include<iostream>
#include<fstream>
#include "stdlib.h"

using namespace std;
int **a, *chuaxet, *truoc, n;

struct stack{
    int info;
    stack *next;
};

stack *push(stack *a, int  x){
    stack *temp = new stack;
    temp -> info = x;
    temp -> next = NULL;
    if(a == NULL){
        return temp;
    }
    temp -> next = a;
    return  temp;
}

stack *pop(stack *a){
    stack *temp;
    if(a == NULL) {
        cout<<"Stack rong"; 
        return NULL;
    }
    temp = a -> next;
    delete a;
    return  temp;
}

void docFile(){
	fstream f("dothi1.txt",ios::in);
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
	truoc = new int [n];
	for(int i = 1;i <= n; i++){
		chuaxet[i] = 1;
		truoc[i] = 0;
	}
}

void dFS(int u){
	chuaxet[u] = 0;
	for(int v = 1;v <= n; v++){
		if(chuaxet[v] == 1 && a[u][v] == 1){
			truoc[v] = u;
			dFS(v);
		}
	}
}

int dFS1(int u){
	stack *s = NULL;
	s = push(s,u);
	chuaxet[u] = 0;
	while(s != NULL){
		u = s -> info;
		s = pop(s);
		for(int v = 1; v <= n; v++){
			if(a[u][v] == 1 && chuaxet[v] == 1){
				s = push(s,v);
				chuaxet[v] = 0;
				truoc[v] = u;
			}
		}
	}
}	

int demTPLT(){
	init();
	int d = 0;
	for(int i = 1; i <= n; i++){
		if(chuaxet[i] == 1)
		    d++;
		    dFS(i);
	}
	return d;
}

void kiemTraLT(){
	if(demTPLT() == 1)  cout<<"Do thi lien thong "<<endl;
	else   cout<<"Do thi khong lien thong "<<endl;
}

int dinhTru(int u){
	init();
	int d = demTPLT(); 
	init();
	chuaxet[u] = 0;
	int d1 = 0;
    for (int i = 1; i <= n; i++){
        if(chuaxet[i] == 1){
        	dFS(i);
			d1++;
        }
    }
    if (d1 > d)   return 1;
    else return 0;
}	

void lietKeDT(){
	cout<<"Cac dinh tru cua do thi la : ";
	for(int i = 1; i <= n; i++){
		if(dinhTru(i) == 1)   cout<<i<<" ";
	}
	cout<<endl;
}

int canhCau(int u ,int v){
	init();
	int d = demTPLT(); 
	init();
	a[u][v] = 0;
	a[v][u] = 0;
	int d1 = demTPLT();    
	a[u][v] = 1;
    a[v][u] = 1;
	if(d1 > d)   return 1;
	else   return 0;
}

void lietKeCC(){
	cout<<"Cac canh cau co trong do thi la :";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 1 && canhCau(i,j) == 1)
			    cout<<"("<<i<<", "<<j<<")";
		}
	}
	cout<<endl;
}

void duongDi(int u,int v){
	init();
	dFS1(v);
	if(truoc[u] == 0)
	{
		cout<<"Khong ton tai duong di ";
	}
	else
	{
		cout<<"Duong di tu :"<<u<<" den "<<v<<" la ";
		cout<<u<<"-> ";
		int j = u;
		while(truoc[j] != v)
		{
			cout<<truoc[j]<<"-> ";
			j = truoc[j];
		}
		cout<<v;
	}
}

void dinhThat(int u, int v)
{
	cout<<"Cac dinh that khi di tu "<<u<<" den "<<v<<" la :";
	for(int i = 1; i <= n; i++)
	{
		init();
		if(i != u && i != v)
		{
			chuaxet[i] = 0;
			dFS1(v);
	        if(truoc[u] == 0)   cout<<i<<"   ";
	    }
	}
}	

void dinhChieu()
{
	int d = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 1 && canhCau(i,j) == 1)
			    d++;
		}
	}
	if(demTPLT() == 1 && d == 0){
		cout<<"Do thi dinh chieu duoc \n";   
		init();
		int u = 1;
	    stack *s = NULL;
	    s = push(s,u);
	    chuaxet[u] = 0;
	    cout<<"Chieu xuoi :";
	    cout<<u;
	    while(s != NULL){
		    u = s -> info;
		    s = pop(s);
		    for(int v = 1; v <= n;v++){
			    if(a[u][v] == 1 && chuaxet[v] == 1){
				    s = push(s,v);
				    chuaxet[v] = 0;
				    truoc[v] = u;
				    cout<<"->"<<v;
				    a[u][v] = 0;
				    a[v][u] = 0;
			    }
		    }
	    }
	    cout<<"\nChieu nguoc :";
	    for(int i = 1; i <= n; i++)
	    {
		    for(int j = i + 1; j <= n; j++)
		    {
			    if(a[i][j] == 1)
			    {
				    cout<<j<<"->"<<i<<" ";
				    a[i][j] = 0;
				    a[j][i] = 0;
			    }
		    }
	    }
    }  
	else{
		cout<<"Do thi khong dinh chieu duoc \n"; 
	}
} 

main()
{
	docFile();
	init();
	int choice;
	do{
		cout<<endl << "Nhap 0: Ket thuc chuong trinh"<<endl;
		cout<<"Nhap 1: Xuat do thi trong file"<<endl;
		cout<<"Nhap 2: Kiem tra do thi co lien thong khong"<<endl;
		cout<<"Nhap 3: Dem so thanh phan lien thong cua do thi"<<endl;
		cout<<"Nhap 4: Liet ke cac dinh tru cua do thi"<<endl;
		cout<<"Nhap 5: Liet ke cac canh cau cua do thi"<<endl;
		cout<<"Nhap 6: Tim duong di tu a den b" << endl;
		cout<<"Nhap 7: Tim dinh that trong doan tu a den b"<<endl;
		cout<<"Nhap 8: Kiem tra dinh chieu, neu dinh chieu duoc thi tim chieu do thi "<<endl;
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
				init();
				kiemTraLT();
				break;
			}
			case 3:{
				system("cls");
				init();
				cout<<"So thanh phan lien thong la :"<<demTPLT();
				break;
			}
			case 4:{
				system("cls");
				init();
				lietKeDT();
				break;
			}
			case 5:{
				system("cls");
				init();
				lietKeCC();
				break;
			}
			case 6:{
				system("cls");
				int u,v;
				init();
				cout<<"Nhap dinh dau :\n ";  cin>>u;
				cout<<"Nhap dinh dich :\n ";  cin>>v;
				duongDi(u,v);
				break;
			}
			case 7:{
				system("cls");
				int u,v;
				init();
				cout<<"Nhap dinh dau :\n ";  cin>>u;
				cout<<"Nhap dinh dich :\n ";  cin>>v;
				dinhThat(u,v);
				break;
			}
			case 8:{
				system("cls");
				init();
				dinhChieu();
				break;
			}
		}
	}while(choice != 0);
}
	
	
	
