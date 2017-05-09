#include<iostream>
using namespace std;
typedef struct node{
	int info;
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

node *makeNode(int x){
	node *p=new node;
	p -> info = x;
	p -> left = NULL;
	p -> right = NULL;
	return p;
}

tree search(tree t,int x){
	tree p;
	if(t -> info == x)   return t;
	if(t == NULL)    return NULL;
	p = search(t -> left, x);
	if(p == NULL) 
	p = search(t -> right, x);
	return p;
}

void makeRoot(tree *t,int x){
	node *p=makeNode(x);
	*t=p;
}

void addLeft(tree *t,int x,int y){// them nut ben trai nut co noi dung la x
    tree temp=*t;	
    node *p = search(temp, x);
    if(p == NULL){
    	cout<<"Khong co nut ";
    	return;
    }
    else if(p -> left != NULL){
    	cout<<"Da co nut ben trai ";
    	return ;
    }
    else{
    	node *q = makeNode(y);
    	p -> left = q;
    }
}

void addRight(tree *t,int x,int y){
	tree temp=*t;
	node *p = search(temp, x);
	if(p == NULL){
		cout<<"Khong co nut ";
		return;
	}
	else if(p -> right != NULL){
		cout<<"Da co nut ben phai ";
		return ;
	}
	else{
		node *q = makeNode(y);
		p -> right =q;
	}
}

void removeLeft(tree *t,int x){
	tree p=*t;
	p = search(p, x);
	if(p == NULL){
		cout<<"Khong co nut ";
		return ;
	}
	else if(p -> left == NULL){
		cout<<"Ben trai khong co nut ";
		return;
	}
	else if(p -> left -> left !=NULL || p -> left -> right != NULL)   return;
	else{
		tree q = p -> left;
		p -> left = NULL;
		delete q;
	}
}

void removeRight(tree *t,int x){
	tree p=*t;
	p = search(p, x);
	if(p == NULL){
		cout<<"Khong co nut ";
		return ;
	}
	else if(p -> right == NULL){
		cout<<"Ben phai khong co nut ";
		return;
	}
	else if(p -> right -> left !=NULL || p -> right -> right != NULL)   return;
	else{
		tree q = p -> right;
		p -> right = NULL;
		delete q;
	}
}

void preOrder(tree *t){
	tree p=*t;
	if(p!=NULL){
	    cout<<p -> info<<"  ";
	    preOrder(&(p -> left));
	    preOrder(&(p -> right));
	}
}

void posOrder(tree *t){
	tree p=*t;
	if(p!=NULL){
	    posOrder(&(p -> left));
	    cout<<p -> info<<"  ";
	    posOrder(&(p -> right));
    }
}

void inOrder(tree *t){
	tree p=*t;
	if(p!=NULL){
	    inOrder(&(p -> left));
	    inOrder(&(p -> right));
	    cout<<p -> info<<"  ";
	}
}

main(){
	tree t;
    init(&t);	
    //cout<<isEmpty(&t);
    makeRoot(&t,3);
    addLeft(&t,3,2);
    addRight(&t,3,5);
    removeLeft(&t,3);
    removeRight(&t,3);
    inOrder(&t);
    //addLeft(&t,2,3);
}

