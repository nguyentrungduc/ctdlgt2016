#include<iostream>
using namespace std;

const int MAX=100;
class pqueue{
	private:
		int inp;
		int out;
		int node[MAX];
	public:
		pqueue(){
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
int pqueue::empty(){
	if(inp==-1&&out==-1)   return 1;
	return 0;
}

int pqueue::full(){
	if(inp==MAX-1)   return 1;
	return 0;
}

void pqueue::push(int x){
	if(full()==0) {
        inp=inp+1; 
        node[inp]=x;
        if(node[inp]<node[inp-1])
        {
        	for(int i=out;i<=inp;i++){
		        if(node[i]>node[inp]){
			        int t=node[i];
				    node[i]=node[inp];
				    node[inp]=t;
			    } 
		    }
		}
    }
}

int pqueue::pop(){
	int x;
	if(empty()==0){
		x=node[out];
		out=out+1;
    }
    return x;
}

void pqueue::display(){
	for(int i=out+1;i<=inp;i++){
		cout<<node[i]<<" ";
	}
}

main(){
	pqueue q;
	q.push(3);
	q.push(2);
	q.push(5);
	q.push(1);
	q.push(7);
	q.push(6);
	q.pop();
	q.display();
}
