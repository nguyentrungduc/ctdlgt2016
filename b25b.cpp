#include<iostream>
#include<fstream>

using namespace std;

struct node{
	string tu;
	int sl;
	struct node *next;
}*last;

class circularlinklist{
	public:
		circularlinklist(){
			last=NULL;
		}
		node *create(string );
		void insert(string );
		void docfile();
		void display();
};

node *circularlinklist::create(string s) 
{
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

void circularlinklist::insert(string s){
	node *p;
	p=create(s);
	if(last==NULL){
		last=p;
		p->next=last;
	}
	else{
		p->next=last->next;
		last->next=p;
		last=p;
	}
}

void circularlinklist::docfile(){
	fstream fdoc("bai25.txt");
	string s;
	fdoc>>s;
	insert(s);
	while(!fdoc.eof()){
		string s;
		fdoc>>s;
		int kt=1;
		node *p=last->next;
		while(p!=last){
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

void circularlinklist::display()
{
	if(last==NULL)
	{
		cout<<"Danh sach khong co node nao ";
	}
	else
	{
		node *p;
		p=last->next;
		while(p!=last)
		{
			cout<<p->tu<<" "<<p->sl<<endl;
			p=p->next;
		}
		cout<<p->tu<<" "<<p->sl<<endl;  
	}
}

main(){
	circularlinklist l;
	l.docfile();
	l.display();
}
