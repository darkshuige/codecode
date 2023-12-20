#include<bits/stdc++.h>
using namespace std;
int gys(int a,int b)
{
	if(a<b)
	 swap(a,b);
	int t=a%b;
	while(t)
	{
		a=b;
		b=t;
		t=a%b;
	}
	return b;
}
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a==b)
		{
			cout<<0<<endl;
			continue;
		}
		int g=gys(a,b);
		a/=g;
		b/=g;
		int count=0;
		while(a%3==0)
		 a/=3,count++;;
		while(a%2==0)
		 a/=2,count++;;
		while(b%3==0)
		 b/=3,count++;;
		while(b%2==0)
		 b/=2,count++;;
		if(a==b)
		{
			cout<<count<<endl;			
		}
		else
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}
