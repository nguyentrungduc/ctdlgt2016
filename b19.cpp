#include<iostream>
using namespace std;

typedef struct {
   int a[100];   //Luu gia tri cua nut
   int n;//so nut
}tree;

int EmptyTree(tree t) {
   return t.n == 0;
}

int Root(tree t) {
   if (!EmptyTree(t))
      return 0;
   else
      return -1;
}

int contrai(int p, tree t) {
      return (2*p+1);
}

int conphai(int p, tree t) {
      return 2*(p+1);
}

void truoc(int p, tree t) {
   if(t.a[p]!=-1) {
      cout<<t.a[p]<<" ";
      truoc(contrai(p,t),t);
      truoc(conphai(p,t),t);
   }
}

void giua(int p, tree t) {
   if(t.a[p]!=-1) {
      giua(contrai(p,t),t);
      cout<<t.a[p]<<" ";
      giua(conphai(p,t),t);
   }
}

void sau(int p, tree t) {
   if(t.a[p]!=-1) {
      sau(contrai(p,t),t);
      sau(conphai(p,t),t);
      cout<<t.a[p]<<" ";
   }
}

void remove(int p,tree t){
	t.a[p]=-1;
}

/*nhap cay
neu khong co con trai hoac phai thi nhap -1*/
void nhap(tree *t) {
   int i = 0, Child = 0;
   printf("Nhap vao so nut: ");
   cin>>(*t).n;
   while(i<(*t).n) {
      if(i==0)
      {
         cout<<"Nut goc :";
         cin>>(*t).a[i];
         (*t).a[contrai(i,*t)] = -1;
         (*t).a[conphai(i,*t)] = -1;
         i++;
      }
      else
      if((*t).a[Child]!=-1)
      {   int k;
         cout<<"Con trai "<<Child;
         k = contrai(Child,*t);
         cin>>(*t).a[k];
         if((*t).a[k] != -1) {
            (*t).a[contrai(k,*t)] = -1;
            (*t).a[conphai(k,*t)] = -1;
            i++;
         }
         cout<<"Con phai "<<Child;
         k = conphai(Child,*t);
         scanf("%d",&(*t).a[k]);
         if((*t).a[k] != -1) {
            (*t).a[contrai(k,*t)] = -1;
            (*t).a[conphai(k,*t)] = -1;
            i++;
         }
         Child++;
      }
   }
}
main() {
   tree t;
   nhap(&t);
   printf("Duyet tien tu.\n");
   truoc(Root(t),t);
   printf("\nDuyet trung tu.\n");
   giua(Root(t),t);
   printf("\nDuyet hau tu.\n");
   sau(Root(t),t);
}

