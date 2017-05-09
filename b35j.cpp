#include<iostream>
#include<fstream>
#include<stack>
#define max 100

using namespace std;

char a[max<<1+1], b[max<<1+1];
int f[max+2][max+2];
int m,n;

void docfile(){
    fstream fdoc("biendoixau.txt");
    fdoc>>a;
    fdoc>>b;
    m=strlen(a)-1;
    n=strlen(b)-1;
}

int min( int x, int y, int z){
    int t;
    if(x<y) t=x;
    else t = y;
    if(z<t) t=z;
    return t;
}

void qhd(){
     for(int i =0;i<=n;++i)
         f[0][i] = i;
     for(int i=1;i<=n;++i)
         f[i][0] = i;
     for(int i=1;i<=n;++i){
          for(int j =1;j<=m;++j){
              if(a[i] == b[j])  f[i][j] = f[i-1][j-1];
              else f[i][j] = min(f[i][j-1],f[i-1][j-1],f[i-1][j])+1;//chen,thaythe,xoa
          }
     }    
}

void truyvet() 
{
	stack<int> s;
    cout<<" So lan chuyen doi la : "<<f[n][m]<<endl;
    while(f[n][m]!=f[0][0]){
    	if(a[n]==b[m]){
		    n--;
			m--;
		}
    	else{
    	    if(f[n][m]==f[n][m-1]+1){
			    s.push(1);
			    n--;
			    m--;
			}
    	    else if(f[n][m]==f[n-1][m-1]+1){
			    s.push(2);
			    n--;
			    m--;
			}   
    	    else if(f[n][m]==f[n-1][m]+1){
			    s.push(3);
			    n--;
			    m--;
			}
    	}
    }
    cout<<"      ";
    while(s.empty()==0){
	    int x=s.top();
		cout<<"->"<<x;
		s.pop();
	} 	 
	cout<<"\n1 tuong ung chen 2 tuong ung thay the 3 tuong ung xoa "<<endl;
}

main()
{
      docfile();
      qhd();
      truyvet();
}
