#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
}*start;

class sortedlist{
	public:
		node *create(int );
		void insert(int);
		void deletebegin();
		void deletelast();
		void deletepos(int );
		void search(int);
		void reverse();
		void display();
		sortedlist(){
			start=NULL;
		}
};

node *sortedlist::create(int value){
	struct node *temp;
	temp=new(struct node);
	if(temp==NULL)
	{
		cout<<"Khong du bo nho cap phat";
		return 0;
	}
	else{
	    temp->info=value;
	    temp->next=NULL;
	    return temp;
	}
}

void sortedlist::insert(int value){
	struct node *temp;
	temp=create(value);
	if(start==NULL){
		start=temp;
		start->next=NULL;
	}
	else{
		struct node *s,*p;
		int kt=0;
		s=start;
		if(s->info>value){
			p=start;
			start=temp;
			start->next=p;
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
				temp->next=p;
			}
			if(s->next==NULL){
				s->next=temp;
				temp->next=NULL;
			}	
		}
	}
}

void sortedlist::deletebegin(){
	node *s;
	s=start;
	start=s->next;
	s->next=NULL;
	free(s);
}

void sortedlist::deletelast(){
	node *s,*p;
	s=start;
	while(s->next!=NULL){
		p=s;
		s=s->next;
	}
	p->next=NULL;
	free(s);
}

void sortedlist::deletepos(int pos){
	node *s,*p;
	s=start;
	for(int i=1;i<pos;i++){
		p=s;
		s=s->next;
	}
	p->next=s->next;
}

void sortedlist::display()
{
	struct node *s;
	if(start==NULL)
	{
		cout<<"List rong ";
	}
	else
	{
	    s=start;
	    while(s!=NULL)
	    {
		    cout<<s->info<<" ";
		    s=s->next;
	    }
	}
}		

void sortedlist::search(int value){
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

void sortedlist::reverse(){
    struct node *ptr1, *ptr2, *ptr3; 
    if (start == NULL) {
         return;
    } 
	if(start->next == NULL){
        return;
    }
    ptr1 = start; 
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1;
    while (ptr3 != NULL){
        ptr1 = ptr2; 
        ptr2 = ptr3; 
        ptr3 = ptr3->next; 
        ptr2->next = ptr1; 
    }
    start = ptr2;
}
main(){
	sortedlist srl;
	srl.insert(3);
	srl.insert(1);
	srl.insert(4);
	srl.insert(2);
	srl.reverse();
	srl.display();
}
