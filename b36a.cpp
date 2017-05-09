#include<iostream>

const int MAX=100;
using namespace std;

char x[100],y[100];

void nhap(){
	cout<<"Nhap xau X :";   cin>>x;
	cout<<"Nhap xau Y :";   cin>>y;
}

int KMP(char x[], char y[])
{
    int next[MAX], i = 0, leny, j=-1, lenx;
    leny = strlen(y);
    lenx = strlen(x);
    next[0] = -1;
    do{
         if (j == -1 || y[i] == y[j]){
             i++;
             j++;
             next[i] = j;
         }
         else
         j = next[j];
    } 
	while (i < leny-1);
    i = j = 0;
    do {
        if (j==0 || x[i] == y[j])
        {
            i++;
            j++;
        }
        else
        j = next[j];
    } 
	while (j<leny && i<lenx);
    if (j>=leny)
        return i-leny;
    else
        return -1;
}

main(){
	nhap();
	cout<<"Vi tri xuat hien cua y trong x la :"<<KMP(x,y);
}
