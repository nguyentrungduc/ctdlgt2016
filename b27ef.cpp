#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int n, canh;

struct node{
	node *next;
	int dinh;
	int ke[10];
};

typedef node *list;

node *createNode( int x, int a[], int n ){
	node *p = new node;
	p->dinh = x;
	p->next = NULL;
	for( int i = 1; i<= n; i++ )
		p->ke[i] = a[i];
	return p;
}

void addTail( list &l, node *p ){
	if(!l) l = p;
	else{
		node *q = l;
		while(q->next) q = q->next;
		q->next = p;
		q = p;
	}
}

void xuatMTK(list l ){
	cout<<n<<endl;
	while(l){
		for( int i=1;i<=n;i++ )
			if(l->ke[i]) cout<<1<< " ";
			else cout<<0<<" ";
		cout<<endl;
		l = l->next;
	}
}

void xuatDSC(list l ){
	cout << n << "\t" << canh << endl;
	while(l){
		for( int i = 1; i<= n; i++ )
			if(l->ke[i]) cout<<l->dinh<<" "<<l->ke[i]<<endl;
		l = l->next;
	}
}

void nhap(list &l ){
	canh = 0;
	fstream fdoc("b27ef.txt");
	string str;
	int count = 0;
	while(!fdoc.eof()){
		getline(fdoc, str );
		int val;
		istringstream buffer(str);
		if(count==0) buffer>>n;
		else{
			int a[10] = {0};
			while(!buffer.eof()){
				buffer>>val;
				a[val]=val;
				canh++;
			}
			node *p=createNode(count,a,n);
			addTail(l,p);
		}
		count++;
	}
}

int main(){
	list l = NULL;
	nhap(l); 
	xuatMTK(l); 
	xuatDSC(l); 
}

