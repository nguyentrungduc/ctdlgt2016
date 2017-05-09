#include<iostream>
using namespace std;

struct node{
	int priority;
	int info;
	node *next;
};

class pqueue{
    private:
        node *front; 
    public:
        pqueue(){
		    front=NULL;
		} 
    void push(int x,int p); 
    void pop(void) ; 
    void display();
};

void pqueue::push(int x,int p){
    node *temp, *q; 
    temp=new node; 
    temp->info=x; 
    temp->priority=p; 
    if (front==NULL||p<front->priority){ 
        temp->next=front; 
        front=temp; 
    }
    else{ 
	    q=front; 
        while(q->next!=NULL&&q->next->priority<=p)
        q=q->next; 
        temp->next=q->next; 
        q->next=temp;
    }
}

void pqueue::pop(){
    node *tmp;
    if(front==NULL) cout<<" khong the pop"<<endl;
    else{ 
	   tmp=front; 
       front=front->next;
	   free(tmp);
    }
}

void pqueue::display(){ 
    node *ptr;
	ptr=front;
    if(front==NULL) 
	cout<<"queue rong"<<endl;
    else{  
		while(ptr!= NULL){ 
		    cout<<ptr->priority<<" "<<ptr->info<<endl;
            ptr=ptr->next;
        }
    }
}

main(){
	pqueue q;
	q.push(1,2);
	q.push(5,4);
	q.push(100,3);
	q.push(3,54);
	q.pop();
	q.display();
}

