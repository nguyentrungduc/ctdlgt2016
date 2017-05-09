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
			inp=-1;
			out=-1;
		}
		int empty();
		int full();
		void push(int x);
		int pop();
		int size();
		void display();
};

int queue::empty(){
	if(inp==-1&&out==-1)   return 1;
	return 0;
}

int queue::full(){
	if(inp==MAX-1)   return 1;
	return 0;
}

void queue::push(int x){
	if(full()==0) {
        inp=inp+1; 
        node[inp] = x; 
    }
}

int queue::pop(){
	int x;
	if(empty()==0){
		x=node[out];
		out=out+1;
    }
    return x;
}

int queue::size(){
	return inp-out;
}

void queue::display(){
	for(int i=out+1;i<=inp;i++){
		cout<<node[i]<<" ";
	}
}
main(){
	queue q;
	q.push(1);
	q.push(2);
	q.push(5);
	q.pop();
	q.display();
	cout<<endl<<q.size();
}
