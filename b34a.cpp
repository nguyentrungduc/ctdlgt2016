#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>

using namespace std;
const int MAX_LENGTH = 100000;

void themnso0vaodau(char *a, int n) {

      int l = strlen(a);
      for (int i = l - 1 + n; i >= n; --i) {
          a[i] = a[i - n];
      }
      a[l + n] = 0;
      for (int i = 0; i < n; ++i){
          a[i] = '0';
      }
}

void xoaso0dangsau(char *a) {
    int l = strlen(a);
    int id = 0;
    while (id < l && a[id] == '0'){
       ++id;
    }

    for (int i = id; i < l; ++i) {
        a[i - id] = a[i];
    }
    a[l - id] = 0;
}

void cong(char *a, char *b, char *s) {
    int la = strlen(a);
    int lb = strlen(b);

    if (la < lb) {
       swap(a, b);
       swap(la, lb);
    }
    int nho = 0;
    for (int ida = la - 1, idb = lb - 1; ida >= 0; --ida, --idb) {
        int x = a[ida] - '0';
        int y = idb >= 0 ? b[idb] - '0' : 0;

        int tong = x + y + nho;

        if (tong >= 10) {
            nho = 1;
            tong -= 10;
        }
	    else{
            nho = 0;
        }

        s[ida] = tong + '0';
    }

    if (nho == 1) {
         themnso0vaodau(s, 1);
         s[0] = '1';
    }
}


void tru(char *a, char *b, char *s) {
    int la = strlen(a);
    int lb = strlen(b);
    int nho = 0;
    for (int ida = la - 1, idb = lb - 1; ida >= 0; --ida, --idb) {
        int x = a[ida] - '0';
        int y = idb >= 0 ? b[idb] - '0' : 0;
        if (nho == 1) {
            x--;
        }
        int hieu;
        if(x < y){
            hieu = x + 10 -y;
            nho = 1;
        }
		else {
             hieu = x - y;
             nho = 0;
        }
        s[ida] = hieu + '0';
    }
}

void nhan10(char* a, int n) {
     int l = strlen(a);
     if (l == 1 && a[0] == '0') {
          return;
     }
     for (int i = l; i < l + n; ++i) {
         a[i] = '0';
     }
     a[l + n] = 0;
}

char *taoxau(int len) {
    char *s = new char[len];
    memset(s, 0, len);
    return s;
}

void cho2xaubangnhau(char *a, char  *b) {
    int la = strlen(a);
    int lb = strlen(b);

    int n = max(la, lb);

    themnso0vaodau(a, n - la);
    themnso0vaodau(b, n - lb);
}

void karatsuba(char *x, char *y, char *s) {
    cho2xaubangnhau(x, y);

    int l = strlen(x);
    if (l == 1) {
        int a = (x[0] - '0') * (y[0] - '0');
        if (a < 10) {
             s[0] = a + '0';
        }
		else {
            s[0] = (a / 10) + '0';
            s[1] = (a % 10) + '0';
        }
    }
	else {
        char *xl = taoxau(l);
        char *xr = taoxau(l);
        char *yl = taoxau(l);
        char *yr = taoxau(l);

        int rightSize = l / 2;
        int leftSize = l - rightSize;

        strncpy(xl, x, leftSize);  // nua trai cua x
        strcpy(xr, x + leftSize);  // nua phai cua y
        strncpy(yl, y, leftSize);  
        strcpy(yr, y + leftSize);

        int maxl = 3 * l;
        char *P1 = taoxau(maxl);
        char *P2 = taoxau(maxl);
        char *P3 = taoxau(maxl);

        karatsuba(xl, yl, P1);   // p1 la tich nua trai cua 2 cai ...
        karatsuba(xr, yr, P2);

        char *temp1 = taoxau(maxl);
        char *temp2 = taoxau(maxl);

        cong(xl, xr, temp1);    
        cong(yl, yr, temp2);
        karatsuba(temp1, temp2, P3);

        tru(P3, P1, P3);
        tru(P3, P2, P3);
        nhan10(P3, rightSize);

        nhan10(P1, 2 * rightSize);

        cong(P1, P2, s);
        cong(s, P3, s);

        xoaso0dangsau(s);

        delete[] xl;
        delete[] xr;
        delete[] yl;
        delete[] yr;
        delete[] temp1;
        delete[] temp2;
        delete[] P1;
        delete[] P2;
        delete[] P3;
    }
}

main() {
     char a[MAX_LENGTH], b[MAX_LENGTH];
     cout<<"Nhap a :";  cin>>a;
     cout<<"Nhap b :";  cin>>b;
     char *s = taoxau(MAX_LENGTH);
     karatsuba(a, b, s);
     cout<<"Tich la :"<<s<<endl;
}
