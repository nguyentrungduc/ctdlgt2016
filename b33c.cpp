#include <iostream>
// cho n cv moi cv thuc hien trog 1 dv thoi gian. lam sao chon thuc hien it cv va thoi gian sao cho loi nhuan cao nhat
using namespace std;

struct cv{
	int so;
	int thoihan;
	int loinhuan;
};
int n;
cv c[100];

void nhap() {
	cout<<"Nhap so cong viec :";
	cin>>n;
	for(int i = 1; i <= n; i++) {
		cout <<"Han chot cong viec thu "<<i<<" la ";  cin>>c[i].thoihan;
		cout <<"Loi nhuan cong vc thu "<<i<<" la ";  cin>>c[i].loinhuan;
		c[i].so=i;
		cout<<endl;
	}
}

void sort() {
	for( int i = 1; i <= n; i++) {
		for( int j = i+1; j <= n; j++) {
			if(c[i].loinhuan<c[j].loinhuan) {
				cv temp=c[i];
				c[i]=c[j];
				c[j]=temp;
			}
		}
	}
}

void greedy() {
	bool chon[100];
	for( int i = 1; i <= n; i++) {
		chon[i] = false;
	}
	int kq[100];
	for( int i = 1; i <= n; i++) {
		for( int j = c[i].thoihan; j >= 1; j--) {
			if( !chon[j]) {
				kq[j] = i;
				chon[j] = true;
				break;
			}
		}
	}
	cout<<"Lich lam cac cong viec toi uu la : ";
	for( int i = 1; i <= n; i++) {
		if(chon[i]) {
			cout<<c[kq[i]].so<<" ";
		}
	}
}

main(){
	nhap();
	sort();
	greedy();
}


