#include <iostream>
#include<fstream>

using namespace std;

int **a, n, *chuaxet, *truoc;

struct node{
	int data ;
	node *next;
};
typedef node *queue;

int empty(queue q){
	return (q == NULL);
}

node *tao(int x){
	node *p;
	p = new node;
	p -> data = x;
	p -> next = NULL;
	return p;
}

void push(queue &q, int x){
	node *p = tao(x), *i = q ;
	if (q == NULL){
		q = p;
	} 
	else{
		while (i -> next != NULL){
			i = i -> next;
		}
		p -> next = i -> next;
		i -> next = p;
	} 
}

int pop(queue &q){
	node *p = q;
	if (!empty(q)){
		int x = p -> data;
		p = p -> next;
		q = p;
		return x;
	}
	return 0;
}

void docFile(){
	fstream f("dothi2.txt",ios::in);
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

int bFS(int u){
	queue q;
	q = NULL;
	push(q,u);
	while(!empty(q)){
		u = q -> data;
		pop(q);
		for(int v = 1; v <= n; v++){
			if(a[u][v] == 1 && chuaxet[v] == 1){
				push(q,v);
				chuaxet[v] = 0;
				truoc[v] = u;
			}
		}
	}
}	

int testLT(){
	for(int i = 1; i <= n; i++){
		if(chuaxet[i] == 1)   return 0;
	}
	return 1;
}

void kiemTraLTManh(){
	int kt = 1;
	for(int i = 1; i <= n; i++){
		init();
		bFS(i);
		if(testLT() == 0){
			kt = 0;
			break;
		}
		init();
	}
	if(kt = 1)   cout<<"Do thi lien thong manh ";
	else cout<<"Do thi khong lien thong manh ";
}

void kiemTraLTYeu(){
	int kt = 0;
	for(int i = 1; i <= n; i++){
		init();
		bFS(i);
		if(testLT() == 1){
			kt = 1;
			break;
		}
		init();
    }
    if(kt == 1)  cout<<"Do thi lien thong yeu ";
    else   cout<<"Do thi khong lien thong yeu ";
}

void duongDi(int u,int v){
	init();
	bFS(u);
	if(truoc[v] == 0)
	{
		cout<<"Khong ton tai duong di ";
	}
	else
	{
		cout<<"Duong di tu "<<u<<" den  "<<v<<" la ";
		cout<<v<<"<-";
		int j = v;
		while(truoc[j] != u)
		{
			cout<<truoc[j]<<"<-";
			j = truoc[j];
		}
		cout<<u;
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
			bFS(u);
	        if(truoc[v] == 0)   cout<<i<<"   ";
	    }
	}
}	

main()
{
	docFile();
	int choice;
	do{
		cout<<endl<<endl<<endl<<"        ******************************";
		cout<<endl << "Nhap 0: Ket thuc chuong trinh"<<endl;
		cout<<"Nhap 1: Xuat do thi trong file"<<endl;
		cout<<"Nhap 2: Kiem tra tinh lien thong manh"<<endl;
		cout<<"Nhap 3: Kiem tra tinh lien thong yeu"<<endl;
		cout<<"Nhap 4: Tim duong di tu a den b" << endl;
		cout<<"Nhap 5: Tim dinh that trong doan tu a den b"<<endl;
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
				kiemTraLTManh();
				break;
			}
			case 3:{
				system("cls");
				init();
				kiemTraLTYeu();
				break;
			}
			case 4:{
				system("cls");
				int u,v;
				init();
				cout<<"Nhap dinh dau :\n ";  cin>>u;
				cout<<"Nhap dinh dich :\n ";  cin>>v;
				duongDi(u,v);
				break;
			}
			case 5:{
				system("cls");
				int u,v;
				init();
				cout<<"Nhap dinh dau :\n ";  cin>>u;
				cout<<"Nhap dinh dich :\n ";  cin>>v;
				dinhThat(u,v);
				break;
			}
    }
	}while(choice != 0);
}
	
	
	

