#include<iostream>
using namespace std;

struct node{
	int info;
	struct node *next;
	struct node *prev;
}*start;

int counter=0;
class sorteddlist{
	public:
		node *create(int );
		void insert(int);
		void deletebegin();
		void deletelast();
		void deletepos(int);
		void search(int);
		void reverse();
		void display();
		sorteddlist(){
			start=NULL;
		}
};

node *sorteddlist::create(int value){
	struct node *temp;
	temp=new(struct node);
	if(temp==NULL)
	{
		cout<<"Khong du bo nho cap phat";
		return 0;
	}
	else{
	    temp->info=value;
	    temp->prev=NULL;
	    temp->next=NULL;
	    return temp;
	}
}

void sorteddlist::insert(int value){
	struct node *temp;
	temp=create(value);
	if(start==NULL){
		start=temp;
		start->next=NULL;
		start->prev=NULL;
	}
	else{
		struct node *s,*p;
		s=start;
		int kt=0;
		if(s->info>value){
		    temp->prev=NULL;
		    temp->next=start;
		    start->prev=temp;
		    start=temp;
		}
		else{
			s=start;
			p=s->next;
			while(s->next!=NULL){
				if(p->info>value){
					kt=1;
					break;
				}
				s=s->next;
				p=p->next;
			}
			if(kt==1){
				s->next=temp;
				temp->prev=s;
				temp->next=p;
				p->prev=temp;
			}
			if(s->next==NULL){
				s->next=temp;
				temp->prev=s;
				temp->next=NULL;
			}	
		}
	}
}

void sorteddlist::display()
{
	struct node *s;
	s=start;
	if(start==NULL)
	{
		return ;
	}
	else
	{
		while(s!=NULL)
		{
			cout<<s->info<<" ";
			s=s->next;
		}
	}
}

void sorteddlist::deletebegin(){
	node *s;
	s=start;
	start=s->next;
	s->next=NULL;
	free(s);
}

void sorteddlist::deletelast(){
	node *s,*p;
	s=start;
	while(s->next!=NULL){
		p=s;
		s=s->next;
	}
	p->next=NULL;
	free(s);
}

void sorteddlist::deletepos(int pos){
	node *s,*p;
	s=start;
	for(int i=1;i<pos;i++){
		p=s;
		s=s->next;
	}
	p->next=s->next;
	s->prev=p;
}

void sorteddlist::search(int value){
	int pos=0,kt=0;
	struct node *s;
	s=start;
	while(s!=NULL)
	{
		pos++;
		if(s->info==value)
		{
			kt=1;
			cout<<"Tim thay tai vi tri "<<pos<<endl;
		}
		s=s->next;
	}
	if(kt==0)    cout<<"Khong tim thay ";
}

void sorteddlist::reverse(){
    struct node *p1, *p2; 
    p1 = start; 
    p2 = p1->next; 
    p1->next = NULL; 
    p1->prev = p2; 
    while (p2 != NULL) {
        p2->prev = p2->next; 
        p2->next = p1; 
        p1 = p2; 
        p2 = p2->prev; 
    }
    start = p1; 
}
main(){
	sorteddlist sl;
	sl.insert(3);
	sl.insert(10);
	sl.insert(2);
	sl.insert(5);
	sl.insert(1);
	sl.deletepos(3);
	sl.display();
	sl.reverse();
	sl.display();
}
