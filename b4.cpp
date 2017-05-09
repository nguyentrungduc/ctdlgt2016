#include<iostream>
using namespace std;
struct node{
	int info;
	struct node *next;
	struct node *prev;
}*start;
class doublelinklist{
	public:
		doublelinklist();
		node* create(int );
		void insertbegin(int );
		void insertpos(int ,int );
		void insertlast(int );
		void deletee(int );
		int count();
		void display();
};
doublelinklist::doublelinklist()
{
	start=NULL;
}
node *doublelinklist::create(int value)
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
		temp->info=value;
		temp->next=NULL;
		temp->prev=NULL;
		return temp;
	}
}
void doublelinklist::insertlast(int value)
{
	struct node *temp,*s;
	temp=new (struct node);
	temp->info=value;
	temp->next=NULL;
	if(start==NULL)
	{
		temp->prev=NULL;
		start=temp;
	}
	else
	{
		s=start;
		while(s->next!=NULL)
		{
			s=s->next;
		}
		s->next=temp;
		temp->prev=s;
		temp->next=NULL;
	}
}
void doublelinklist::insertbegin(int value)
{
	if(start==NULL)
	{
		cout<<"Danh sach rong ";
		return;
	}
	else
	{
		struct node *temp;
		temp=new (struct node);
		temp->info=value;
		temp->prev=NULL;
		temp->next=start;
		start->prev=temp;
		start=temp;
	}
}
void doublelinklist::insertpos(int value,int pos)
{
	if(start==NULL)
	{
		cout<<"Danh sach rong ";
		return;
	}
	else
	{
		struct node *temp,*s;
		s=start;
		for(int i=0;i<pos-1;i++)
		{
			s=s->next;
			if(s==NULL)
			{
				cout<<"So node trong danh sach nho hon vi tri :";
				return;
			}
		}
		temp=new (struct node);
		temp->info=value;
		if(s->next==NULL)
		{
			temp->next=NULL;
			s->next=temp;
			temp->prev=s;
		}
		else
		{
			temp->next=s->next;
			temp->next->prev=temp;
			temp->prev=s;
			s->next=temp;
		}
		
	}
}
void doublelinklist::deletee(int value)
{
	struct node *temp,*s;
	if(start->info==value)
	{
		temp=start;
		start=start->next;
		start->prev=NULL;
		free(temp);
		return;
	}
	else
	{
		s=start;
		while(s->next->next==NULL)
		{
			if(s->next->info==value)
			{
				temp=s->next;
				s->next=temp->next;
				temp->next->prev=s;
				free(temp);
				return;
			}
			s=s->next;
		}
		if(s->next->info==value)
		{
			temp=s->next;
			s->next=NULL;
            free(temp);
            return;
		}
	}
}
void doublelinklist::display()
{
	struct node *s;
	s=start;
	if(start==NULL)
	{
		cout<<"Danh sach khong co node"<<endl;
		return ;
	}
	else
	{
		while(s!=NULL)
		{
			cout<<s->info<<" ";
			s=s->next;
		}
	}
}
int doublelinklist::count()
{
	struct node *s;
	s=start;
	int d=0;
	while(s!=NULL)
	{
		s=s->next;
		d++;
	}
	return d;
}
main()
{
	doublelinklist dll;
	dll.insertlast(5);
	dll.insertlast(2);
	dll.insertbegin(4);
	dll.deletee(4);
	dll.display();
}
