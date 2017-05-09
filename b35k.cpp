#include<iostream>

using namespace std;
 
int max(int a,int b){
	if(a>b)   return a;
	return b;
}
 
main(){
    char x[100],y[100],m,n;
    int l[100][100];
    cout<<"Nhap xau x:";
    cin>>x+1;
    cout<<"Nhap xau y:";
    cin>>y+1;
    m=strlen(x+1);
    n=strlen(y+1);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if (x[i]==y[j])
			    l[i][j]=l[i-1][j-1]+1; 
            else 
			    l[i][j]=max(l[i-1][j],l[i][j-1]);
        }
    }
    cout<<"Do dai xau con chung dai nhat la "<<l[m][n];
}
