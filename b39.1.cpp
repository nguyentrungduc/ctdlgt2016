#include<iostream>
#include<fstream>
#include "stdlib.h"

using namespace std;
int **a, *chuaxet, n, tcdt;

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
	fstream f("dothi4.txt",ios::in);
	f>>n;
	f>>tcdt;     //0 la vo huong 1 la co huong 
	a = new int *[n];
	for(int i = 1; i <= n; i++){
		a[i] = new int [n];
		for(int j = 1; j <= n; j++)
		f>>a[i][j];
	}
	f.close();
}

void xuatDoThi()
{
	if(tcdt == 0)   cout<<"Do thi vo huong \n";
	if(tcdt == 1)   cout<<"Do thi co huong \n";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
} 

void init()
{
	chuaxet = new int [n];
	for(int i = 1;i <= n; i++){
		chuaxet[i] = 1;
	}
}

int dFS(int u)
{
	stack *s = NULL;
	s = push(s,u);
	chuaxet[u] = 0;
	while(s != NULL){
		u = s -> info;
		s = pop(s);
		for(int v=1;v<=n;v++){
			if(a[u][v] == 1 && chuaxet[v] == 1){
				s = push(s,v);
				chuaxet[v] = 0;
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
	if(d == 1 )   return 1;
	else    return 0;
}

void euler(int u)
{
	int x,v;
	stack *s = NULL;
	int CE[100],dCE = 0;
	s = push(s, u);
	do{ 
		v = s -> info;
		x = 1;
		while(x <= n && a[v][x] == 0)   x++;
		if(x > n){
		    dCE++;
		    CE[dCE] = v;
		    s = pop(s);
		}
		else{
			s = push(s, x);
			if(tcdt == 0){
			   a[v][x] = 0;
			   a[x][v] = 0;
			}
			else if(tcdt == 1){
				a[v][x] = 0;
			}
		}
	}while(s != NULL);
	cout<<CE[dCE];
	for(x = dCE - 1; x > 0; x--){
		cout<<"->"<<CE[x];
	}
}

int voHuong()
{
	int s, d = 0, vt;
	for(int i = 1; i <= n; i++){
		s = 0;
		for(int j = 1; j <= n; j++){
			s = s + a[i][j];
		}
		if(s % 2 != 0)   {
			d++;
			vt = i;
		}
	}
	if(d == 0 && demTPLT() == 1){
	   cout<<"Do thi co chu trinh euler ";
	   euler(1);
	}
	else if(d == 2 && demTPLT() == 1){
	   cout<<"Do thi co duong di euler";
	   euler(vt);
	}
	else  cout<<"Do thi khong co duong di hay chu trinh euler";
}

int testLT(){
	for(int i = 1; i <= n; i++){
		if(chuaxet[i] == 1)   return 0;
	}
	return 1;
}

int kiemTraLTYeu(){
	int kt = 0;
	for(int i = 1; i <= n; i++){
		init();
		dFS(i);
		if(testLT() == 1){
			kt = 1;
			break;
		}
		init();
    }
    if(kt == 1)  return 1;
    else   return 0;
}

int tinhBacRa(int i){
	int s = 0;
	for(int j = 1; j <= n; j++)
	s = s + a[i][j];
	return s;
}

int tinhBacVao(int i){
	int s = 0;
	for(int j = 1; j <= n; j++)
	s = s + a[j][i];
	return s;
}

int coHuong(){
	int d1 = 0, d2 = 0, d3 = 0, vt;
	for(int i = 1; i <= n; i++){
		if(tinhBacRa(i) == tinhBacVao(i))   d1++;
		else if(tinhBacRa(i) > tinhBacVao(i)){
			d2++;
			vt = i;
		}
		else   d3++;
	}
	if(d1 == n && kiemTraLTYeu() == 1){
	    cout<<"Do thi co huong co chu trinh euler\n";
	    euler(1);
	}
	else if(d1 == n - 2 && d2 == 1 && d3 == 1 && kiemTraLTYeu() == 1){
	    cout<<"Do thi co huong co duong di euler\n";
	    euler(vt);
	}
	else    cout<<"Do thi co huong khong co duong di hay chu trinh euler\n";
	return vt;
}
main()
{
	docFile();
	init();
	xuatDoThi();
	if(tcdt == 0)   voHuong();
	else if(tcdt == 1)   coHuong();
}
