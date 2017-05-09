#include<iostream>
#include<fstream>

using namespace std;

struct node{
	string tu;
	int sl;
	node *next;
}*start;

class sortedlist{
	public:
		node* create(string );
		void insert(string);
		void docfile();
		void display();
		sortedlist(){
			start=NULL;
		}
};

node *sortedlist::create(string s){
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
	    temp->next=NULL;
	    return temp;
	}
}

void sortedlist::insert(string s){
	struct node *temp;
	temp=create(s);
	if(start==NULL){
		start=temp;
		start->next=NULL;
	}
	else{
		struct node *q,*p;
		int kt=0;
		q=start;
		if(q->tu>s){
			p=start;
			start=temp;
			start->next=q;
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
				temp->next=p;
			}
			if(q->next==NULL){
				q->next=temp;
				temp->next=NULL;
			}	
		}
	}
}

void sortedlist::docfile(){
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

void sortedlist::display()
{
	struct node *p;
	if(start==NULL)
	{
		cout<<"List rong ";
	}
	else
	{
	    p=start;
	    while(p!=NULL)
	    {
		    cout<<p->tu<<" "<<p->sl<<endl;
		    p=p->next;
	    }
	}
}		

main(){
	sortedlist l;
	l.docfile();
	l.display();
}


