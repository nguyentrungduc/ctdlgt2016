#include<iostream>
#include<fstream>

using namespace std;

typedef struct node{
	string tu;
	int sl;
	node *right,*left;
}*tree;

void init(tree *t){
	*t = NULL;
}

node *makeNode(string s){
	node *p=new node;
	p -> tu = s;
	p -> sl = 1;
	p -> left = NULL;
	p -> right = NULL;
	return p;
}

tree search(tree *t,string s){
    tree p=*t;
    while(p!=NULL){ 
        if(s==p->tu) return p; 
        else p=p->right; 
    }
    return NULL;
}

void makeRoot(tree *t,string s){
	node *p=makeNode(s);
	*t=p;
}

void addNode(tree *t,string s){
	tree p=*t,q;
	if(p==NULL)    makeRoot(t,s);
	else{
	    while(p->right!=NULL){
		    p=p->right;
        }
        q=makeNode(s);
        p->right=q;
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

void display(tree *t){
	tree p=*t;
	if(p!=NULL){
	    cout<<p -> tu<<"  "<<p -> sl<<endl;
	    display(&(p -> left));
	    display(&(p -> right));
	}
}

main(){
	tree t;
	init(&t);
	docfile(&t);
	display(&t);
}
