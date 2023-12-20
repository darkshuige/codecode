#include<bits/stdc++.h>
using namespace std;
int cc;
int gys(int a,int b)
{
	int t;
	if(a<b)
	{
		t=a;a=b;b=t;
	}
	t=a%b;
	while(t)
	{
		a=b;
		b=t;
		t=a%b;
	}
	return b;
}
int fact(int &a)
{
	while(a%2==0)
	{
		a/=2;
		cc++;
	}
	while(a%3==0)
	{
		a/=3;
		cc++;
	}
	while(a%5==0)
	{
		a/=5;
		cc++;
	}
}
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cc=0;
		int g=gys(a,b);
		a/=g,b/=g;
		fact(a);
		fact(b);
		if(a==b)
		 cout<<cc<<endl;
		else
		 cout<<-1<<endl;
	}
	return 0;
} 
