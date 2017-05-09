#include<iostream>
#include<fstream>
using namespace std;

struct node{
	string tu;
	int sl;
	node *next;
}*start;

class singlelinklist{
	public:
		node* create(string );
		void insertlast(string);
		void docfile();
		void display();
		singlelinklist();
};

singlelinklist::singlelinklist()
{
	start=NULL;
}

node *singlelinklist::create(string s) 
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

void singlelinklist::insertlast(string s){
	struct node *temp,*p;
	temp=create(s);
	if(start==NULL){
		start=temp;
		start->next=NULL;
	}
	else{
	    p=start;
	    while(p->next!=NULL){
	        p=p->next;
	    }
	    temp->next=NULL;
	    p->next=temp;
	}
}

void singlelinklist::docfile(){
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
		    insertlast(s);
		}
	}
}

void singlelinklist::display()
{
	struct node *p;
	if(start==NULL){
		cout<<"ds rong ";
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
	singlelinklist l;
	l.docfile();
	l.display();
}
