#include<iostream>
#include<fstream>

using namespace std;

struct node{
	string tu;
	int sl;
	struct node *next;
	struct node *prev;
}*start;

class doublelinklist{
	public:
		doublelinklist(){
			start=NULL;
		}
		node* create(string );
		void insert(string );
		void docfile();
		void display();
};

node *doublelinklist::create(string s)
{
	struct node *temp;
	temp=new (struct node);
	if(temp==NULL)
	{
		cout<<"Khong du bo nho den cap phat ";
		return 0;
	}
	else
	{
		temp->tu=s;
		temp->sl=1;
		temp->next=NULL;
		temp->prev=NULL;
		return temp;
	}
}

void doublelinklist::insert(string s)
{
	struct node *temp,*p;
	temp=new (struct node);
	temp->tu=s;
	temp->sl=1;
	temp->next=NULL;
	if(start==NULL)
	{
		temp->prev=NULL;
		start=temp;
	}
	else
	{
		p=start;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
		temp->prev=p;
	}
}

void doublelinklist::display()
{
	struct node *p;
	p=start;
	if(start==NULL)
	{
		cout<<"Danh sach khong co node"<<endl;
		return ;
	}
	else
	{
		while(p!=NULL)
		{
			cout<<p->tu<<" "<<p->sl<<endl;
			p=p->next;
		}
	}
}

void doublelinklist::docfile(){
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

main(){
	doublelinklist l;
	l.docfile();
	l.display();
}
