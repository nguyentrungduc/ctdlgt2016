#include<iostream>
#include<list>
using namespace std;
list<int> mylist;
void empty(){
	if(mylist.size()==0)  
	cout<<"Danh sach rong";
}

int size(){
	return mylist.size();
}

void push(int a){
	mylist.push_back(a);
}

void pop(){
	mylist.pop_back();
}

main(){

}
