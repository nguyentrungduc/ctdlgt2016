#include<iostream>
using namespace std;

class minheap{   
    int *a; //mang cac not
    int size; 
    public:
        minheap(){
            size = 0; 
            a = new int[100];
        }
        void MinHeapify(int k);// tao nut con khoa k
        int parent(int i){ 
		    return (i-1)/2;
	    }
        int left(int i){
		    return (2*i+1);
	    }
        int right(int i){ 
		    return (2*i+2);
		}
        int extractMin();// loai bo phan tu nho nhat
        void changeKey(int i,int n);
        int getMin(){ 
		    return a[0];
	    }
        void deleteKey(int i);
        void insertKey(int k);
        void display();
};

void minheap::insertKey(int k) {
    if(size==100) {
        cout << "Khong them dc";
        return;
    }
    size++;
	int i=size-1;
    a[i]=k; // them nut k vao cuoi cung sau do xac dinh lai vi tri cua k
    while(i!=0&&a[parent(i)]>a[i]){
        swap(a[i],a[parent(i)]);
        i=parent(i);
    }
}

void minheap::changeKey(int i,int n){
    a[i]=n;
    while(i!=0&&a[parent(i)]>a[i]){
        swap(a[i],a[parent(i)]);
        i=parent(i);
    }
}

int minheap::extractMin(){
    if (size<=0) 
    return INT_MAX;
    if (size==1) {
        size--; 
		return a[0]; 
    }
    int root = a[0];
	a[0]=a[size-1];
    size--; 
	MinHeapify(0);
    return root;
}

void minheap::deleteKey(int i){
    changeKey(i, INT_MIN); 
    extractMin(); 
}

void minheap::MinHeapify(int i){
    int l=left(i);
	int r=right(i);
	int smallest=i;
    if(l<size&&a[l]<a[i]) smallest=l;
    if(r<size&&a[r]<a[smallest]) smallest=r;
    if(smallest!=i){ 
	    swap(a[i],a[smallest]); 
		MinHeapify(smallest);
	}
}

void minheap::display(){
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
}

main(){
	minheap m;
	m.insertKey(5);
	m.insertKey(2);
	m.insertKey(3);
	m.insertKey(7);
	m.insertKey(6);
	m.deleteKey(0);
	m.display();
}
