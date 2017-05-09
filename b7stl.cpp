#include<iostream>
#include<string>
#include<list>
using namespace std;
void nhap(list <int > &heso,list <int > &somu)
{
	int hs,sm;
	int n;
	cout<<"Nhap so phan tu cua da thuc :";   cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap he so :";   cin>>hs;
		heso.push_back(hs);
		cout<<"Nhap so mu :";   cin>>sm;
		somu.push_back(sm);
	}
}
void xuat(list <int > heso,list <int > somu)
{
	list<int>::iterator it1;
	list<int>::iterator it2;
	it2=somu.begin();
	int i=0;
	for (it1=heso.begin(); it1!=heso.end(); it1++)
	{
		i++;
        cout<<*it1<<"x^";
        cout<<*it2; 
		it2++;
		if(i==heso.size())
		{
			cout<<" ";
		}
		else   cout<<"+";
    }
    cout<<endl;
}
void tinhtong(list <int > a,list <int > somup,list <int > heso,list <int > somu)
{
	list <int > hesok;
	list <int > somuk;
	list<int>::iterator it1;
	list<int>::iterator it2;
	list<int>::iterator it3;
	list<int>::iterator it4;
	it1=a.begin();      cout<<*it1;
	it2=somup.begin();      cout<<*it2;
	it3=heso.begin();      cout<<*it3;
	it4=somu.begin();      cout<<*it4<<endl;
	while(it1!=a.end()&&it2!=somup.end()&&it3!=heso.end()&&it4!=somu.end())
	{
		if(*it2>*it4)
		{
			hesok.push_back(*it1);
			somuk.push_back(*it2);
			it1++;
			it2++;
		}
		else if(*it4>*it2)
		{
			hesok.push_back(*it3);
			somuk.push_back(*it4);
			it3++;
			it4++;
		}
		else if(*it4==*it2)
		{
			hesok.push_back(*it1+*it3);  cout<<*it1<<"?";  
			somuk.push_back(*it2);
			it1++;
			it2++;
			it3++;
			it4++;
		}
	}
//	while(it1==a.end()&&it2==somup.end()&&it3!=heso.end()&&it4!=somu.end())
//	{
//		hesok.push_back(*it3);
//		somuk.push_back(*it4);
//	}
//	while(it1!=a.end()&&it2!=somup.end()&&it3==heso.end()&&it4==somu.end())
//	{
//		hesok.push_back(*it1);
//		somuk.push_back(*it2);
//	}
	xuat(hesok,somuk);
}
main()
{
	list <int > a;
	list <int > somup;
	list <int > heso;
	list <int > somu;
	nhap(a,somup);
	xuat(a,somup);
	nhap(heso,somu);
	xuat(heso,somu);
	tinhtong(a,somup,heso,heso);
}			

