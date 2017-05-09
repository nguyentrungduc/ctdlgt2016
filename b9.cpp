#include<iostream>
using namespace std;

struct node{
	int info;
	struct node *next;
}*stack;

class stackl{
	public:
		node *push(int);
		node *pop();
		void display();
		int top();
        stackl(){ 
		   stack=NULL;
	    }
};

node *stackl::push(int x){ 
    node *temp;
	temp=new (struct node);
    temp->info=x;
	temp->next=stack; 
	stack=temp;
    return stack;
}

node *stackl::pop(){ 
    node *temp;
    if(stack==NULL) cout<<"Stack rong"<<endl;
    else { 
	    temp=stack;
        stack=stack->next; 
		free(temp);
    }
    return stack;
}

void stackl::display(){
    node *temp; 
	temp=stack;
    if(stack==NULL){
    	cout<<"Stack rong"<<endl;
    }
    else{
        while(temp!= NULL){
            cout<<temp->info<<" "; 
			temp=temp->next;
        }  
    }
}

int stackl::top(){
	return stack->info;
}

main(){
	stackl s;
	s.push(2);
	s.push(5);
	s.push(3);
	s.push(6);
	s.pop();
	s.display();
}
