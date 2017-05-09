#include <iostream>
 
using namespace std;
 
int x,y,a[8][8];
 
int dx[]={-2,-1,+1,+2,+2,+1,-1,-2};
int dy[]={+1,+2,+2,+1,-1,-2,-2,-1};
 
void init(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			a[i][j]=0;
		}
	}
}

void xuat(){
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
 
// Tim 1 trong 8 o xung quanh cua (x,y) de dat Ma
void madituan(int x,int y,int buoc)
{
    if(buoc==64)
    xuat();
    else{
    // Xet 8 o xung quanh
        for(int k=0;k<8;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx>=0&&yy>=0&&xx<8&&yy<8)
            if(a[xx][yy]==0){
                a[xx][yy]=buoc;
                madituan(xx,yy,buoc+1);
                a[xx][yy]=0;
            }
        }
    }
}
 
int main()
{
    cout<<"Nhap toa do bat dau cho ma chay :";
    cin>>x;
    cin>>y;
    init();
    int buoc=1;
    a[x][y]=buoc;
    madituan(x,y,buoc+1);
}
