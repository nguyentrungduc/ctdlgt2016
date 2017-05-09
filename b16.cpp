#include<iostream>
using namespace std;
struct node{
	int info;
	struct node *next;
}*last;
class cqueue{
	public:
		cqueue(){
			last=NULL;
		}
		void push(int);
		void push1(int);
		void pop();
		void display();
};

void cqueue::push1(int x){
	node *temp;
	last=temp;
}
void cqueue::push(int x)
{
	struct node *temp;
	temp=new(struct node);
	temp->info=x;
	if(last==NULL){
		last=temp;
		temp->next=last;
	}
	else{
		temp->next=last->next;
		last->next=temp;
		last=temp;
	}
}

void cqueue::pop()
{

	if(last==NULL){
		cout<<" khong the pop "<<endl;
	}
	struct node *temp,*s;
    if (last->next==last){ 
        temp=last; 
		last=NULL; 
		free(temp); 
		return;
    }
	else{
		s=last->next;
		temp=s;
		last->next=s->next;
		free(temp);
		return;
	} 
}	

void cqueue::display()
{
	if(last==NULL)
	{
		cout<<"queue rong ";
	}
	else
	{
		node *s;
		s=last->next;
		while(s!=last)
		{
			cout<<s->info<<" ";
			s=s->next;
		}
		cout<<s->info<<endl;  
	}
}

main()
{
	cqueue q;
	q.push(3);
	q.push(5);
	q.push(2);
	q.pop();
    q.display();
}	
