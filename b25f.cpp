#include<iostream>
#include<fstream>

using namespace std;

struct node{
	string tu;
	int sl;
	struct node *next;
	struct node *prev;
}*start;

class sorteddlist{
	public:
		node *create(string );
		void insert(string);
        void docfile();
		void display();
		sorteddlist(){
			start=NULL;
		}
};

node *sorteddlist::create(string s){
	struct node *temp;
	temp=new(struct node);
	if(temp==NULL)
	{
		cout<<"Khong du bo nho cap phat";
		return 0;
	}
	else{
	    temp->tu=s;
	    temp->sl=1;
	    temp->prev=NULL;
	    temp->next=NULL;
	    return temp;
	}
}

void sorteddlist::insert(string s){
	struct node *temp;
	temp=create(s);
	if(start==NULL){
		start=temp;
		start->next=NULL;
		start->prev=NULL;
	}
	else{
		struct node *q,*p;
		q=start;
		int kt=0;
		if(q->tu>s){
		    temp->prev=NULL;
		    temp->next=start;
		    start->prev=temp;
		    start=temp;
		}
		else{
			q=start;
			p=q->next;
			while(q->next!=NULL){
				if(p->tu>s){
					kt=1;
					break;
				}
				q=q->next;
				p=p->next;
			}
			if(kt==1){
				q->next=temp;
				temp->prev=q;
				temp->next=p;
				p->prev=temp;
			}
			if(q->next==NULL){
				q->next=temp;
				temp->prev=q;
				temp->next=NULL;
			}	
		}
	}
}

void sorteddlist::docfile(){
	fstream fdoc("bai25.txt");
	while(!fdoc.eof()){
		string s;
		fdoc>>s;
		int kt=1;
		node *p=start;
		while(p!=NULL){
			if(p->tu==s){
				kt=0;
				p->sl++;
				break;
			}
			p=p->next;
		}
		if(kt==1){
		    insert(s);
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
			cout<<s->tu<<" "<<s->sl<<endl;
			s=s->next;
		}
	}
}

main(){
	sorteddlist l;
	l.docfile();
	l.display();
}
