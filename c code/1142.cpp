#include<iostream>
#include<stdio.h>
using namespace std;
int gys(int a,int b)
{
	int t;
	if(a<b)
	{
		t=a;a=b;b=t;
	}
	t=a%b;
	while(t!=0)
	{
		a=b;
		b=t;
		t=a%b;
	}
	return b;
}
int main()
{
	int x,y;
	while(scanf("%d %d",&x,&y)!=EOF)
	{
		int p,q,count=0;
		int i;
		for(i=1;i<=y;i++)
		{
			p=i*x;
			if(x*y%p!=0)
			 continue;
			q=x*y/p;
			if(gys(p,q)==x)
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
