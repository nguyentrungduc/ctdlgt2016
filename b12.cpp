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
			out=0;
			inp=-1;
		}
		int empty();
		int full();
		void push(int x);
		int pop();
		int size();
		void display();
};

int queue::empty(){
	if(inp<0)   return 1;
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
		for(int i=0;i<inp;i++){   // xoa xong roi dich hàng xuong de dè lên cái phan tu vua xoa
			node[i]=node[i+1];
		}
		inp=inp-1;
    }
    return x;
}

void queue::display(){
	for(int i=0;i<=inp;i++)
    {
        cout<<node[i]<<" ";
    }
}

int queue::size(){
	return inp+1;
}

main(){
	queue q;
	q.push(1);
	q.push(2);
	q.push(5);
	q.pop();
	q.push(6);
	q.pop();
	q.display();
	cout<<endl<<q.size();
}
