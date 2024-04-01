#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int p,m,c,k,r,v;
	int a1,b1,c1,d1;
	while(scanf("%d %d %d\n%d %d %d",&p,&m,&c,&k,&r,&v)!=EOF)
	{
		a1=p/k;
		b1=m/r;
		c1=c/v;
		d1=a1<b1?(a1<c1?a1:c1):(b1<c1?b1:c1);
		cout<<d1<<endl;
	}
	
	return 0;
}
