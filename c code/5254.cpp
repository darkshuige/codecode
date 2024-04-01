#include<bits/stdc++.h>
using namespace std;
struct zb
{
	int d1x,d2x,d3x,d4x;
	int d1y,d2y,d3y,d4y;
	int ch,k;
}a,b,t;
int main()
{
	cin>>a.d1x>>a.d1y>>a.ch>>a.k;
	cin>>b.d1x>>b.d1y>>b.ch>>b.k;
	a.d2x=a.d1x+a.ch;
	a.d2y=a.d1y;
	a.d3x=a.d2x;
	a.d3y=a.d2y-a.k;
	a.d4x=a.d1x;
	a.d4y=a.d3y;
	
	b.d2x=b.d1x+b.ch;
	b.d2y=b.d1y;
	b.d3x=b.d2x;
	b.d3y=b.d2y-b.k;
	b.d4x=b.d1x;
	b.d4y=b.d3y;
	int H=0,L=0;
	if(a.d1y<b.d1y)
	{
		t=a;a=b;b=t;
	}
	if(a.d4y>=b.d1y)
	{
		H=0;
	}
	else
	{
		if(a.d4y<=b.d4y)
		{
			H=b.k;
		}
		else
		{
			H=abs(b.d1y-a.d4y);
		}
	}
	if(a.d1x>b.d2x || a.d2x<b.d1x)
	{
		L=0;
	}
	else
	{
		if(a.d1x>=b.d1x && a.d2x<=b.d2x)
		{
			L=abs(a.d2x-a.d1x);
		}
		else if(a.d2x>b.d2x)
		{
			L=abs(b.d2x-a.d1x);
		}
		else if(a.d1x<b.d1x)
		{
			L=abs(a.d2x-b.d1x);
		}
	}
	cout<<H*L<<endl;
	return 0;
}
