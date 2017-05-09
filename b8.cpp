#include<iostream>
using namespace std;
const int MAX=100;
class stack{
	private:
		int top;
		int node[MAX];
	public:
		stack(){
			top = -1;
		}
		int empty();
		int full();
		void push(int x);
		int pop();
		int top1();
		void display();
};

int stack::empty(){
	if(top==-1) 
    return 1;
    return 0; 
}

int stack::full(){ 
    if (top==MAX-1) 
    return 1; 
    return 0; 
}

void stack::push(int x){
	if(full()==0){
		top=top+1;
		node[top]=x;
    }
    else{
    	return;
    }
}

int stack::pop(){
	int x;
	if(empty()==0){
		x=node[top];
		top=top-1;
		return x;
    }
}

void stack::display(){
	for(int i=0;i<=top;i++){
		cout<<node[i]<<" ";
	}
} 

int stack::top1(){
	return node[top];
}

main(){
	stack s;
	s.push(1);
	s.push(3);
	s.push(5);
	s.pop();
	s.display();
}
