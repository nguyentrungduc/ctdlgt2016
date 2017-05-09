#include <iostream>

using namespace std;

void nhap(string &s, int &l, int &d) {
	cout<<"Nhap xau : ";
	cin>>s;
	l = s.length();
	cout<<"Khoang cach = ";
	cin>>d;
}

struct tu{
	char kt;
	int sl;
};

void greedy(string s, int l, int d) {
	tu t[100];
	int n = 0; 
	for( int i = 0; i < l; i++){
		bool found = false;
		for( int j = 0; j < n; j++){
			if( t[j].kt == s[i]) {
				t[j].sl++;
				found = true;
			}
		}
		if( !found) {
			t[n].kt = s[i];
			t[n].sl = 0;
			n++;
		}
	}
	
	for( int i = 0; i < n; i++) {
		for( int j = i+1; j < n; j++) {
			if( t[i].sl < t[j].sl) {
				tu temp = t[i];
				t[i] = t[j];
				t[j] = temp;
			}
		}
	}
	string kq = s;
	bool kt[100];
	for( int i = 0; i < l; i++) {
		kt[i] = true;
	}
	int cokq = true;
	for( int i = 0; i < n; i++) {
		int p;
		for( p = 0; p < l; p++) {
			if( kt[p]) {
				break;
			}
		}
		int f = 0;
		while( f <= t[i].sl) {
			if( p + f*d > l) {
				cokq = false;
				break;
			}
			kq[p + f*d] = t[i].kt;
			kt[p + f*d] = false;
			f++;
		}	
		if( !cokq) {
			break;
		}
	}
	if( !cokq) {
		cout << "Khong co ket qua" << endl;
	}
	else {
		cout << "Xau duoc sap xep : ";
		for( int i = 0; i < l; i++) 
		{
			cout<<kq[i];
		}
		cout<<endl;
	}
}

int main() {
	string s;
	int l;
	int d;
	nhap(s,l, d);
	greedy(s,l, d);
}

