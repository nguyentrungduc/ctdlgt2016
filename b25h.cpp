#include<iostream>
#include<fstream>

using namespace std;

typedef struct node{
	int sl;
	string tu;
	struct node *left;
	struct node *right;
}*tree;

void init(tree *t){
	*t = NULL;
}

int isEmpty(tree *t){
	if(*t == NULL)    return 1;
	return 0;
}

node *makeNode(string s){
	node *p=new node;
	p -> tu = s;
	p -> sl = 1;
	p -> left = NULL;
	p -> right = NULL;
	return p;
}

void makeRoot(tree *t,string s){
	node *p=makeNode(s);
	*t=p;
}

tree search(tree *t, string s){ 
    tree p=*t;
    while (p!=NULL){ 
        if(s==p->tu) return p;
        else if(s<p->tu) p=p->left; 
        else p=p->right; 
    }
    return NULL;
}

void addNode(tree *t,string s){
   	tree p,q;
   	p=*t;
   	q=*t;
   	while(p->tu!=s&&q!=NULL){
        p=q; 
        if(s<p->tu) 
        q=p->left; 
        else 
        q=p->right; 
    }
    if(s==p->tu){
    	cout<<"Trung node";
	    return;
	}
    node *r=makeNode(s);   
    if(s<p->tu) 
    p->left=r;
    else 
    p->right=r;
}

void display(tree *t){
	tree p=*t;
	if(p!=NULL){
	    cout<<p -> tu<<"  "<<p -> sl<<endl;
	    display(&(p -> left));
	    display(&(p -> right));
	}
}

void docfile(tree *t){
	fstream fdoc("bai25.txt");
	string s;
	fdoc>>s;
	makeRoot(t,s);
	while(!fdoc.eof()){
		string s;
		fdoc>>s;
		tree p=*t;
		p=search(t,s);
		if(p==NULL){
			addNode(t,s);
		}
		else   p->sl++;
    }
}

main(){
	tree t;
	init(&t);
	docfile(&t);
	display(&t);
}

