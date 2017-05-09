#include<iostream>
#include<math.h>

using namespace std;

typedef struct tagnode{
    float heso,somu;
    struct tagnode *next,*pre;
}node;

node *taonode(float heso,float somu){
    node *p=new node;
    if(p==NULL) exit(1);
    p->heso=heso;
    p->somu=somu;
    p->next=p->pre=NULL;
    return p;
}

typedef struct tagdathuc{
    node *dau;
	node *cuoi;
}dathuc;

void taodathuc(dathuc &l){
    l.dau=l.cuoi=NULL;
}

void themcuoi(dathuc &l,node *p){
    if(l.dau==NULL) l.dau=l.cuoi=p;
    else{
        l.cuoi->next=p;
        p->pre=l.cuoi;
        l.cuoi=p;
    }
}

void nhap(dathuc &l){
    node *p;
    float heso,somu;
    cout<<"nhap so da thuc, ket thuc khi nhap he so = 0\n";
    do{
        cout<<"he so = ";cin>>heso;
        if(heso!=0)
        {
            cout<<"so mu = ";cin>>somu;
            p=taonode(heso,somu);
            themcuoi(l,p);
        }
        cout<<endl;
    }while(heso!=0);
}

void xuat(dathuc l){
    node *p=l.dau;
    if(p==NULL)
    {
        cout<<0;
        return;
    }
    while(p!=NULL)
    {
        if(p==l.dau){
            if(p->somu==0) cout<<p->heso;
            else if(fabs(p->heso)!=1 && p->somu!=1) cout<<p->heso<<"X^"<<p->somu;
            else if(fabs(p->heso)!=1 && p->somu==1) cout<<p->heso<<"X";
            else if(fabs(p->heso)==1 && p->somu!=1) cout<<(p->heso==1?"X^":"-X^")<<p->somu;
            else cout<<(p->heso==1?"X":"-X");
        }
        else{
            if(p->somu==0) cout<<(p->heso<0?" - ":" + ")<<fabs(p->heso);
            else if(fabs(p->heso)!=1 && p->somu!=1) cout<<(p->heso<0?" - ":" + ")<<fabs(p->heso)<<"X^"<<p->somu;
            else if(fabs(p->heso)!=1 && p->somu==1) cout<<(p->heso<0?" - ":" + ")<<fabs(p->heso)<<"X";
            else if(fabs(p->heso)==1 && p->somu!=1) cout<<(p->heso==1?" + X^":" - X^")<<p->somu;
            else cout<<(p->heso==1?" + X":" - X");
        }
        p=p->next;
    }
}

void sapxep(dathuc &l){
    node *p1=l.dau,*p2;
    while(p1!=NULL)
    {
        p2=p1->next;
        while(p2!=NULL)
        {
            if(p2->somu>p1->somu)
            {
                swap(p1->heso,p2->heso);
                swap(p1->somu,p2->somu);
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}

void xoatruocQ(dathuc &l,node *Q)
{
    node *p;
    if(Q==NULL)
    {
        p=l.cuoi;
        if(l.dau==l.cuoi)
        {
            l.dau=l.cuoi=NULL;
            delete p;
        }
        else if(p!=NULL)
        {
            l.cuoi=l.cuoi->pre;
            l.cuoi->next=NULL;
            delete p;
        }
    }
    else
    {
        p=Q->pre;
        if(p!=NULL)
        {
            if(p==l.dau)
            {
                l.dau=l.dau->next;
                l.dau->pre=NULL;
                delete p;
            }
            else
            {
                p->pre->next=Q;
                Q->pre=p->pre;
                delete p;
            }
        }
    }
}

void rutgon(dathuc &l)
{
    node *p1=l.dau,*p2;
    while(p1!=NULL)
    {
        p2=p1->next;
        while(p2!=NULL)
        {
            if(p2->somu==p1->somu)
            {
                p1->heso+=p2->heso;
                p2=p2->next;
                xoatruocQ(l,p2);
            }
            else p2=p2->next;
        }
        p1=p1->next;
    }
}

void themtruocQ(dathuc &l,node *Q,node *p)
{
    if(Q==l.dau)
    {
        l.dau->pre=p;
        p->next=l.dau;
        l.dau=p;
    }
    else
    {
        p->pre=Q->pre;
        p->next=Q;
        Q->pre->next=p;
        Q->pre=p;
    }
}

void insert(dathuc &l,node *p){
    node *p1=l.dau;
    while(p1!=NULL && p1->somu > p->somu) p1=p1->next;
    if(p1!=NULL)
    {
        if(p1->somu == p->somu) p1->heso += p->heso;
        else themtruocQ(l,p1,p);
    }
    else themcuoi(l,p);
}

void xuly(dathuc &l){
    node *p=l.dau;
    while(p!=NULL)
    {
        if(p->heso==0)
        {
            p=p->next;
            xoatruocQ(l,p);
        }
        else p=p->next;
    }
}

int cong(dathuc l1,dathuc l2,dathuc &l){
    node *p=l1.dau,*a;
    while(p!=NULL)
    {
        a=taonode(p->heso,p->somu);
        themcuoi(l,a);
        p=p->next;
    }
    p=l2.dau;
    while(p!=NULL)
    {
        a=taonode(p->heso,p->somu);
        insert(l,a);
        xuly(l);
        p=p->next;
    }
    xuly(l);
    if(l.dau==NULL) return 0;
    return 1;
}

int tru(dathuc l1,dathuc l2,dathuc &l){// cong voi dao cua no
    node *p=l2.dau;
    while(p!=NULL)
    {
        p->heso=-p->heso;
        p=p->next;
    }
    cong(l1,l2,l);
    p=l2.dau;
    while(p!=NULL)
    {
        p->heso=-p->heso;
        p=p->next;
    }
    if(l.dau==NULL) return 0;
    return 1;
}

int nhan(dathuc l1,dathuc l2,dathuc &l)
{
    node *p,*p1,*p2;
    p2=l2.dau;
    while(p2!=NULL)
    {
        p1=l1.dau;
        while(p1!=NULL)
        {
            p=taonode(p2->heso*p1->heso,p2->somu+p1->somu);
            insert(l,p);
            p1=p1->next;
        }
        p2=p2->next;
    }
    xuly(l);
    if(l.dau==NULL) return 0;
    return 1;
}

void xoacuoi(dathuc &l){
    node *p=l.cuoi;
    if(p==NULL) exit(1);
    if(l.dau==l.cuoi)
    {
        l.dau=l.cuoi=NULL;
        delete p;
    }
    else
    {
        l.cuoi=p->pre;
        l.cuoi->next=NULL;
        delete p;
    }
}

void xoa(dathuc &l){
    while(l.dau!=NULL) xoacuoi(l);
}

void chia(dathuc l1,dathuc l2){
    node *p,*p1;
    dathuc a,b,du;
    taodathuc(a);
	taodathuc(b);
	taodathuc(du);
    p1=l1.dau;
    while(p1!=NULL){// copy l1 vao du
        p=taonode(p1->heso,p1->somu);
        themcuoi(du,p);
        p1=p1->next;
    }
    while(du.dau!=NULL && du.dau->somu >= l2.dau->somu){// lay du chia cho l2
        p=taonode(du.dau->heso / l2.dau->heso,du.dau->somu - l2.dau->somu);
        themcuoi(a,p);
        xoa(b);// list b la list lay phan du a nhan bs l2 roi tru di .....
        if(nhan(l2,a,b)==0) break;
        xoa(du);
        if(tru(l1,b,du)==0) break;
    }
    xuat(a);
    if(du.dau!=NULL)
    {
        cout<<"\n du ";
        xuat(du);
    }
}

main()
{
    dathuc l1,l2,l3,l4,l5,l6;
    taodathuc(l1);
	taodathuc(l2);
	taodathuc(l3);
	taodathuc(l4);
	taodathuc(l5);
	taodathuc(l6);
    nhap(l1);
	nhap(l2);
    rutgon(l1);
	sapxep(l1);
    cout<<"\nda thuc 1 = ";
	xuat(l1);
	cout<<endl;
    rutgon(l2);
	sapxep(l2);
    cout<<"\nda thuc 2 = ";
	xuat(l2);
	cout<<endl;
    cong(l1,l2,l3);
	xuat(l3); 
	cout<<endl;
    tru(l1,l2,l4);
	xuat(l4);
	cout<<endl;
    nhan(l1,l2,l5);
	xuat(l5);
	cout<<endl;
    chia(l1,l2);
}
