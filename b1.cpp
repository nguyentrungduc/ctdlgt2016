#include<iostream>
using namespace std;
struct node{
	int info;
	struct node *next;
}*start;
class singlelinklist{
	public:
		node* create(int );
		void insertbegin();
		void insertpos();
		void insertlast();
		void deletepos();
		void sort();
		void search();
		void update();
		void reverse();
		void display();
		singlelinklist();
};
singlelinklist::singlelinklist()
{
	start=NULL;
}
node *singlelinklist::create(int value) // khoi tao 1 nut cho danh sach lien ket
{
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
void singlelinklist::insertbegin(){
	struct node *temp,*p;//temp la node them vao dau 
	int value;
	cout<<"Nhap gia tri cho nut :";   
	cin>>value;
	temp=create(value);
	if(start==NULL)
	{
		start=temp;
		start->next=NULL;
	}
	else{
		p=start;
		start=temp;
		start->next=p;
	}
}
void singlelinklist::insertlast(){
	struct node *temp,*s;
	int value;
	cout<<"Nhap gia tri cho nut :";   
	cin>>value;
	temp=create(value);
	s=start;
	while(s->next!=NULL){
	    s=s->next;
	}
	temp->next=NULL;
	s->next=temp;
}
void singlelinklist::display()
{
	struct node *s;
	if(start==NULL)
	{
		cout<<"Co gi dau ma hien thi ";
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
void singlelinklist::insertpos()
{
	struct node *s,*p,*temp;
	int pos,d,value;
	cout<<"Nhap vi tri can chen phan tu :";
	cin>>pos;
	cout<<"Nhap gia tri cho phan tu them vao :";
	cin>>value;
	temp=create(value);
	s=start;
	while(s!=NULL)
	{
		s=s->next;
		d++;
	}
	if(pos==1)    singlelinklist::insertbegin();
	else if(pos>1&&pos<=d){
		s=start;
		for(int i=1;i<pos;i++)
		{
			p=s;
			s=s->next;
		}
		p->next=temp;
		temp->next=s;
	}
	else cout<<"Nhap sai ";
}	
void singlelinklist::deletepos()
{
	int pos,d=0;
	struct node *s,*p;
	cout<<"Nhap vi tri can xoa :";
	cin>>pos;
	s=start;
	while(s!=NULL)
	{
		s=s->next;
		d++;
	}
	if(pos>d||pos<0)    cout<<"Nhap sai ";
	else if(pos==1)
	{
		start=s->next;
		s->next=NULL;
		free(s);
	}  
	else{
		s=start;
		for(int i=1;i<pos;i++)
		{
			p=s;
			s=s->next;
		}
		p->next=s->next;
	}
}
void singlelinklist::update()
{
	int value,pos,d=0;
	struct node *s;
	cout<<"Nhap vi tri phan tu can thay doi :";
	cin>>pos;
	s=start;
	while(s!=NULL)
	{
		s=s->next;
		d++;
	}
	cout<<"Nhap gia tri moi cua nut can sua :";
	cin>>value;
	if(pos==1)
	{
		start->info=value;
	}
	else if(pos>1&&pos<=d)
	{
		s=start;
		for(int i=1;i<pos;i++)
		{
			s=s->next;
		}
		s->info=value;
	}
	else   cout<<"Nhap sai ";
}	
void singlelinklist::search()
{
	int value,pos=0,kt=0;
	struct node *s;
	cout<<"Nhap gia tri can tim :";   cin>>value;
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
main()
{
	singlelinklist sll;
}
