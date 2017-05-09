#include<iostream>
using namespace std;
struct node{
	int info;
	struct node *next;
}*last;
class circularlinklist{
	public:
		circularlinklist();
		node *create(int );
		void insertbegin(int);
		void insertpos(int );
		void search(int);
		void deletee(int );
		void display();
		void update();
		void sort();
};
circularlinklist::circularlinklist()
{
	last=NULL;
}
node *circularlinklist::create(int value)
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
void circularlinklist::insertbegin(int value)
{
	struct node *temp;
	if(last==NULL)
	{
		last->info=value;
		last->next=NULL;
	}
	else
	{
		temp=new(struct node);
	    temp->info=value;
		temp->next=last->next;// temp tro den vi tri sau cua last 
		last->next=temp;
	}
}
void circularlinklist::insertpos(int pos)
{
	if(last==NULL)
	{
		cout<<"Danh sach rong ";   return;
	}
	struct node *temp, *s;
	int value;
	cout<<"Nhap  gia tri cho nut :";   cin>>value;
	temp=create(value);
    s = last->next; 
    for (int i = 0;i < pos-1; i++)
	{	
        s = s->next;
        if(s == last->next)
		{ 
            cout<<"So node be hon vi tri ";
            return;
        }
    }
    temp = new(struct node); 
	temp->next = s->next;
    temp->info = value; 
	s->next = temp;
    if (s==last)
	{
        last=temp;
    }
}
void circularlinklist::deletee(int value)
{
    struct node *temp, *s; 
	s = last->next;
    if (last->next==last&&last->info==value)
	{ 
        temp=last; 
		last=NULL; 
		free(temp); 
		return;
    } 
	if (s->info==value) {
        temp=s; 
		last->next=s->next;
		free(temp);
		return;
    }
    while (s->next != last)
	{
        if(s->next->info == value)
		{
            temp=s->next;
			s->next=temp->next;
			free(temp);
        }
        s = s->next;
    }
    if(s->next->info==value)
	{
        temp=s->next;
		s->next=last->next;
		free(temp);
		last=s;
    }
    cout<<"Node"<<value<<" ko co trog ds "<<endl;
}
void circularlinklist::search(int value)
{
    struct node *s; int counter = 0;
    s = last->next; 
    while (s != last)
    { 
        counter++;
        if (s->info==value)
		{
            cout<<"Tim thay node "<<value;
            cout<<" vi tri "<<counter<<endl;
        }
        s=s->next;
    }
	 if(s->info==value)
	 { 
         counter++;
         cout<<"Tim thay node "<<value;
          cout<<" vi tri "<<counter<<endl;
     }
     cout<<"Gia tri "<<value<<" khong co trong danh sach"<<endl;
}
void circularlinklist::display()
{
	if(last==NULL)
	{
		cout<<"Danh sach khong co node nao ";
	}
	else
	{
		node *s;
		s=last->next;
		while(s!=last)
		{
			cout<<s->info<<" ";
			s=s->next;
		}
		cout<<s->info<<endl;  
	}
}
void circularlinklist::update()	
{
	int value,pos;
	if(last==NULL)
	{
		cout<<"Danh sach khong co nut";
	}
	else 
	{
		cout<<"Nhap vi tri node can sua :"; 
		cin>>pos;
		cout<<"Nhap gia tri thay doi :";
		cin>>value;
		node *s;
		s=last->next;
		for(int i=0;i<pos-1;i++)
		{
			
			s=s->next;
		}
		s->info=value;
	}
}
void circularlinklist::sort()
{
	node *s,*p;
	if(last==NULL)
	{
		cout<<"Danh sach khong co nut";
	}
	else
	{
		s=last->next;
		while(s!=last)
		{
			p=s->next;
			while(p!=last->next)
			{
				if (p!=last->next)
				{
                    if (s->info>p->info)
				    {
				    	int temp;
                        temp=s->info;
						s->info=p->info;
                        p->info=temp;
                    }
                }
                else  break; 
            } 
            p= p->next;
        }
        s=s->next;
    }
}
main()
{
	int value,choice;
	circularlinklist sll;
	struct node *temp = new(struct node);
	cin>>value;
    temp->info = value;
    last = temp; 
    temp->next = last;
    sll.insertbegin(3);
    sll.insertpos(2);
    sll.deletee(1);
    sll.display();
}	
