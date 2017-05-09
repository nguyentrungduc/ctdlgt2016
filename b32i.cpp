#include<iostream>
#include<fstream>
using namespace std;

int s[10][10];
void docFile(){
	fstream fdoc("sudoku.txt");
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			fdoc>>s[i][j];
		}
	}
}

void xuat(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
}

int kiemtra(int x,int y,int k){
    for(int i=0;i<9;i++){
        if(s[x][i]==k) return 0;
    }
    for(int i=0;i<9;i++){
            if(s[i][y]==k) return 0;
        }
    int a=x/3, b=y/3;
    for(int i=3*a;i<3*a+3; i++){
        for(int j=3*b;j<3*b+3;j++){
            if(s[i][j]==k) return 0;
        }
    }
    return 1;
}

void Try(int x,int y){
    if(y==9){
        if(x==8){
            xuat();
            exit(0);
        } 
		else{
            Try(x+1,0);
        }
    }
	else if(s[x][y]==0){
        int k=0;
        for(k=1;k<=9;k++){
            if(kiemtra(x,y,k)){
                s[x][y]=k;
                Try(x,y+1);
                s[x][y]=0;
            }
        }
    } 
	else {
        Try(x,y+1);
    }
}

main(){
	docFile();
	Try(0,0);
}
