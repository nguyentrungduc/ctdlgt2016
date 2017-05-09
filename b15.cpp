#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL,*p=NULL,*np=NULL;

int empty(){
	if(front==NULL)   return 1;
	return 0;
}

void push(int x){
    np=new node; 
    np->data=x; 
	np->next=NULL; 
    if(front==NULL){ 
        front=rear=np; 
        rear->next = NULL;
    }
    else{
        rear->next=np;
		rear=np;
        rear->next=NULL;
    }
}

int pop(){ 
    int x;
    if(front==NULL){ 
    cout<<"Hang doi rong"<<endl;
    }
    else{ 
        p=front; 
        x=p->data; 
        front=front->next; 
        delete(p);
        return x; 
    }
}

void display(){
	node *q;
	q=front;
	while(q!=NULL){
		cout<<q->data<<" ";
		q=q->next;
	}
}

main(){
	push(3);
	push(5);
	push(2);
	pop();
	push(6);
	display();
}
	
