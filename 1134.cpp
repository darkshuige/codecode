#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
long long gys(long long a,long long b)
{	
	long long t;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
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
	long long a,b,c,d,res1,res2,chu,c1,c2;
	int n,i;//b/a d/c
	cin>>n;//a/b c/d
	for(i=0;i<n;i++)
	{
		scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
		c1=c;
		c2=a;
		a*=c1;
		b*=c1;
		c*=c2;
		d*=c2;
		res1=abs(b-d);
		res2=a;
		if(res1==0)
		{
			cout<<"1"<<endl;
		}
		else
		{
			if(res2%res1==0)
			 cout<<res2/res1<<endl;
			else
			{
				chu=gys(res1,res2);
				res1/=chu;
				res2/=chu;
				cout<<res2<<"/"<<res1<<endl;	
			}
		}
	}
	return 0;
}
