#include<iostream>
using namespace std;

struct node{
	int info;
	node *prev;
	node *next;
}*start,*last;

int counter=0;
class dclist{
	public:
        node *createnode(int); 
        void insertbegin(int); 
        void insertlast(int); 
        void insertpos(int,int); 
        void deletepos(int); 
        void search(int); 
        void update(int,int); 
        void display(); 
        void reverse(); 
        void sort(); 
        dclist() {
             start = NULL; last = NULL;
        }
};

node *dclist::createnode(int value){
	counter++;
	struct node *temp;
	temp = new (struct node);
	temp->info=value;
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}

void dclist::insertbegin(int value){
	struct node *temp;
	temp=createnode(value);
	if(start==last&&start==NULL){
		start=last=temp;
		start->next = last->next = NULL;
        start->prev = last->prev = NULL;
    }
    else{
    	temp->next=start;
    	start->prev=temp;
    	start=temp;
    	start->prev=last;
    	last->next=start;
    }
}

void dclist::insertlast(int value){
	struct node *temp;
	temp=createnode(value);
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

void dclist::insertpos(int value,int pos){
	struct node *temp,*ptr,*s;
	temp=createnode(value);
	if(start==last&&start==NULL){
		if(pos==1){
			start=last=temp;
		    start->next = last->next = NULL;
            start->prev = last->prev = NULL;
        }
        else{
        	counter--;
        	return ;
        }
    }
    else{
    	if(counter<pos){
    		counter--;
    		return;
        }
        s=start;
        for(int i=1;i<=counter;i++){
        	ptr=s; 
		    s=s->next;
        	if(i==pos-1){
        		ptr->next=temp;
				temp->prev = ptr;
                temp->next = s; 
				s->prev = temp;
                break;
            }
        }
    }
}

void dclist::deletepos(int pos){
	if (start == last && start == NULL){
        return;
    }
    node *s,*ptr;
    if(counter<pos){
    	cout<<"Vi tri khong hop le";
    	return;
    }
    s=start;
    if(pos==1){
    	counter--; 
		last->next=s->next;
        s->next->prev=last;
		start=s->next;
		free(s);
	}
	for (int i=0;i<pos-1;i++ ){
        s=s->next; 
		ptr=s->prev;
    }
    ptr->next=s->next;
	s->next->prev=ptr;
    if (pos==counter) { last = ptr; }
    counter--; free(s);
}

void dclist::update(int pos,int value){
    if (start==last&&start==NULL){
    return;
    }
    struct node *s;
    if (counter < pos){ 
	    cout<<"Vi tri ko hop le";return;
	}
    s=start; 
    if (pos == 1) {
        s->info= value;
	    return;
    }
    for (int i=0;i<pos-1;i++) {
        s = s->next;
    }
    s->info = value;
}

void dclist::search(int value){
    int pos=0,i;
    bool flag=false;
    struct node *s;
    if (start==last&&start==NULL){
        return;
    }
    s=start; 
    for (i=0;i<counter;i++){ 
	    pos++;
        if (s->info == value){
            cout<<"Tim thay "<<value<<" tai vi tri "<<pos<<endl;
            flag = true; 
        }
        s = s->next;
    }
	if (!flag)
    cout<<"Khong tim thay";
}

void dclist::sort(){
    struct node *temp, *s; int value, i;
    if (start==last&&start==NULL){
        return;
    }
    s=start; 
    for(i=0;i<counter;i++){
    temp=s->next;
    while(temp!=start){
         if(s->info>temp->info){
             int value=s->info;
             s->info=temp->info;
             temp->info=value;
         }
         temp=temp->next;
    }
    s=s->next;
    }
}

void dclist::display(){
    struct node *s;
    if(start==last&&start==NULL){
        return;
    }
    s=start;
    for(int i=0;i<counter-1;i++){
        cout<<s->info<<"<->";
        s = s->next; 
    }  
    cout<<s->info<<endl; 
}

void dclist::reverse(){//Dao nguoc
    if (start == last && start == NULL){
        return;
    }
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != start){
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    last=start;
	start=p1;
}

main(){
	dclist dcl;
	dcl.insertbegin(2);
	dcl.insertbegin(3);
	dcl.insertbegin(4);
	dcl.deletepos(2);
	dcl.reverse();
	dcl.display();
	
}
