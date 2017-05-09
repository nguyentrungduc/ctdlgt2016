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

void makeRoot(tree *t,int x){
	node *p=makeNode(x);
	*t=p;
}

tree search(tree *t, int x){ 
    tree p=*t;
    while (p!=NULL){ 
        if(x==p->info) return p;
        else if(x<p->info) p=p->left; 
        else p=p->right; 
    }
    return p;
}

void addNode(tree *t,int x){
   	tree p,q;
   	p=*t;
   	q=*t;
   	while(p->info!=x&&q!=NULL){
        p=q; 
        if(x<p->info) 
        q=p->left; 
        else 
        q=p->right; 
    }
    if(x==p->info){
    	cout<<"Trung node";
	    return;
	}
    node *r=makeNode(x);   
    if(x<p->info) 
    p->left=r;
    else 
    p->right=r;
}
   	
tree remove(tree p){
    tree rp,f;
    if(p==NULL){ 
	     return p; 
	}
    else if(p->right==NULL&&p->left!=NULL)   rp=rp->left;// p chi co nut con ben trai thi nut thay the la con trai 
    else if (p->right!=NULL&&p->left==NULL)  rp = rp->right;
    else{ 
        f=p;
		rp=p->right; // f la node cha cua rp
        while(rp->left!=NULL){
            f=rp;
			rp=rp->left;
        }
        if(f!=p){
		    f->left=rp->right;
			rp->right=p->right;
			rp->left=p->left; 
		}
        else
		rp->left=p->left;
    }
    delete p;
    return rp;
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

void rotateLeft(tree *t ){
    node *temp;
    tree p=*t;
    temp=p->right;
    p->right=temp->left;
    temp->left=p;
}

void rotateRight(tree *t ){
	node *temp;
    tree p=*t;
    temp=p->left;
    p->left=temp->right;
    temp->right=p;
}

void reMove(tree *t,int x){
	node *p;
	if(p!=NULL){
		int found=0;
		tree a;
		tree parent=NULL;
		a=*t;
		while(a!=NULL){
			if(a->info==x)
			break;
			else{
				parent=a;
				if(x>a->info){
					a=a->right;
					found=1;
				}
				else{
					a=a->left;
					found=-1;
				}
			}
		}
		if(found==0)	// node xoa la node goc
		*t=remove(*t);
		else if(found==1)
		parent->right=remove(parent->right);
		else
		parent->left=remove(parent->left);
		cout<<"Da xoa node."<<endl;
	}
	else cout<<"\n Ko tim thay node muon xoa."<<endl;
}

void deleteleft(tree *t,int x){
	node *p;
	p=search(t,x);
	if(p!=NULL)
	remove(p->left);
}

void deleteright(tree *t,int x){
	node *p;
	p=search(t,x);
	if(p != NULL)
	remove(p->right);
}

main(){
	tree t;
    init(&t);	
    makeRoot(&t,40);
    addNode(&t,30);
    addNode(&t,25);
    addNode(&t,35);
    addNode(&t,60);
    addNode(&t,50);
    preOrder(&t);
}

