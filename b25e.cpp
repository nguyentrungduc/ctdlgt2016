#include<iostream>
#include<fstream>

using namespace std;

struct node{
	string tu;
	int sl;
	node *prev;
	node *next;
}*start,*last;
int counter=0;
class dclist{
	public:
        node *create(string);  
        void insert(string);  
        void docfile();
        void display();  
        dclist() {
             start = NULL; last = NULL;
        }
};

node *dclist::create(string s){
	counter++;
	struct node *temp;
	temp = new (struct node);
	temp->tu=s;
	temp->sl=1;
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}

void dclist::insert(string s){
	struct node *temp;
	temp=create(s);
	if(start==last&&start==NULL){
		start=last=temp;
		start->next = last->next = NULL;
        start->prev = last->prev = NULL;
    }
    else{
    	last->next=temp;
    	temp->prev=last;
    	last=temp;
    	start->prev=last;
    	last->next=start;
    }
}

void dclist::docfile(){
	fstream fdoc("bai25.txt");
	string s;
	fdoc>>s;
	insert(s);
	while(!fdoc.eof()){
		string s;
		fdoc>>s;
		int kt=1;
		node *p=start;
		for(int i=0;i<=counter-1;i++){
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

void dclist::display(){
    struct node *p;
    if(start==last&&start==NULL){
        return;
    }
    p=start;
    for(int i=0;i<counter-1;i++){
        cout<<p->tu<<" "<<p->sl<<endl;
        p=p->next; 
    }  
    cout<<p->tu<<" "<<p->sl<<endl;
}

main(){
	dclist l;
	l.docfile();
	l.display();
}
