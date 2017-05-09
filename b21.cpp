#include<iostream>
using namespace std;

class maxheap{   
    int *a; //mang cac not
    int size; 
    public:
        maxheap(){
            size = 0; 
            a = new int[100];
        }
        void MaxHeapify(int k);// tao nut con khoa k
        int parent(int i){ 
		    return (i-1)/2;
	    }
        int left(int i){
		    return (2*i+1);
	    }
        int right(int i){ 
		    return (2*i+2);
		}
        int extractMax();// loai bo phan tu nho nhat
        void changeKey(int i,int n);
        int getMax(){ 
		    return a[0];
	    }
        void deleteKey(int i);
        void insertKey(int k);
        void display();
};

void maxheap::insertKey(int k) {
    if(size==100) {
        cout << "Khong them dc";
        return;
    }
    size++;
	int i=size-1;
    a[i]=k; // them nut k vao cuoi cung sau do xac dinh lai vi tri cua k
    while(i!=0&&a[parent(i)]<a[i]){
        swap(a[i],a[parent(i)]);
        i=parent(i);
    }
}

void maxheap::changeKey(int i,int n){
    a[i]=n;
    while(i!=0&&a[parent(i)]<a[i]){
        swap(a[i],a[parent(i)]);
        i=parent(i);
    }
}

int maxheap::extractMax(){
    if (size<=0) 
    return INT_MIN;
    if (size==1) {
        size--; 
		return a[0]; 
    }
    int root = a[0];
	a[0]=a[size-1];
    size--; 
	MaxHeapify(0);
    return root;
}

void maxheap::deleteKey(int i){
    changeKey(i, INT_MAX); 
    extractMax();// cho nut con xuong thay 
}

void maxheap::MaxHeapify(int i){
    int l=left(i);
	int r=right(i);
	int smallest=i;
    if(l<size&&a[l]>a[i]) smallest=l;
    if(r<size&&a[r]>a[smallest]) smallest=r;
    if(smallest!=i){ 
	    swap(a[i],a[smallest]); 
		MaxHeapify(smallest);
	}
}

void maxheap::display(){
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
}

main(){
	maxheap m;
	m.insertKey(5);
	m.insertKey(2);
	m.insertKey(3);
	m.insertKey(7);
	m.insertKey(6);
	m.deleteKey(0);
	m.display();
}
