#include<iostream>
using namespace std;

const int MAX=100;
class queue{
	private:
		int inp;
		int out;
		int node[MAX];
	public:
		queue(){
			inp=99;
			out=100;
		}
		int empty();
		void push1(int x);
		int pop1();
		void push2(int x);
		int pop2();
		int size();
		void display();
};

int queue::empty(){
	if(inp==100&&out==100)   return 1;
	return 0;
}

void queue::push1(int x){
    inp=inp+1; 
    node[inp]=x; 
}

void queue::push2(int x){
    out=out-1;
    node[out]=x;
}

int queue::pop1(){
	int x;
	if(empty()==0){
		x=node[out];
		out=out+1;
    }
    return x;
}

int queue::pop2(){
	int x;
	if(empty()==0){
		x=node[inp];
		inp=inp-1;
	}
	return x;
}

int queue::size(){
	return inp-out;
}

void queue::display(){
	for(int i=out;i<=inp;i++){
		cout<<node[i]<<" ";
	}
}

main(){
	queue q;
	q.push1(2);
	q.push2(3);
	q.push1(5);
	q.push1(7);
	q.push1(6);
	q.pop1();
	q.pop2();
	q.push2(1);
	q.pop1();
	q.display();
}
