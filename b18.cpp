#include<iostream>
using namespace std;

struct node{
	int info;
	node *prev;
	node *next;
}*head,*tail;

class dqueue{
    public:
        int top1,top2; 
        void insert_front(int); 
        void insert_last(int); 
        void del_front(); 
        void del_last(); 
        void display_front(); 
        void display_last(); 
        dqueue(){ 
            top1=0;
            top2=0;
            head=NULL;
            tail=NULL;
        }
};

void dqueue::insert_front(int value){
    struct node *temp;
    if (top1+top2>=50){
       cout<<"Tran queue"<<endl;
	   return;
    }  
	if(top1+top2==0){
        head=new (struct node); 
		head->info=value;
        head->next=NULL; 
        head->prev=NULL; 
        tail=head; 
        top1++;
    }
    else{ 
        temp=new (struct node);
		temp->info=value;
        temp->next=head; 
        temp->prev=NULL; 
        head->prev=temp; 
        head=temp; 
        top1++;
    }
}

void dqueue::insert_last(int value){ 
    struct node *temp;
    if(top1+top2>=50){
        cout<<"Tran queue"<<endl;
		return;
    }
	if(top1+top2==0){ 
        head=new(struct node);
		head->info=value;
        head->next=NULL;
        head->prev=NULL;
        tail=head; 
        top1++;
    }
    else{
        temp=new(struct node);
		temp->info=value;
        temp->next=NULL; 
        temp->prev=tail;
        tail->next=temp; 
        tail=temp; 
        top2++;
    }
}

void dqueue::del_front(){
    struct node *temp=head;
    if (top1+top2<=0){ 
        cout<<"Khong the pop"<<endl;
        return;
    }
    head=head->next; 
    head->prev=NULL; 
    top1--;
	free(temp);
}

void dqueue::del_last(){
    struct node *temp =tail;
    if(top1+top2<=0){
        cout<<"Khong the pop"<<endl;
        return;
    }
    tail=tail->prev;
    tail->next=NULL;
    top2--;
	free(temp);
}

void dqueue::display_front(){ 
    struct node *temp;
    if(top1+top2<=0){
        cout<<"Queue rong"<<endl;return;
    }
    temp=head; 
    cout<<"Duyet tu node dau:"<<endl;
    while (temp!=NULL){
        cout<<temp->info<<" ";
		temp=temp->next;
    }
}

void dqueue::display_last(){ 
    struct node *temp;
    if(top1+top2<=0){
        cout<<"Queue rong"<<endl;
		return; 
    }
    cout<<"Duyet tu node cuoi:"<<endl;
    temp=tail;
    while(temp!=NULL){
        cout<<temp->info<<" ";
		temp=temp->prev;
    }
}

main(){
	dqueue q;
	q.insert_front(2);
	q.insert_front(3);
	q.insert_last(1);
	q.insert_front(6);
	q.del_last();
	q.display_front();
}

