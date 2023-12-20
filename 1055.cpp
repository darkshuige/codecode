#include<stdio.h>
#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int v,va,vb;
	while(~scanf("%d%d%d",&v,&va,&vb))
	{
		int x=gcd(va,vb);
		if(v%x==0)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
