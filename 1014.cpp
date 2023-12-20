#include<iostream>
#include<stdio.h>
using namespace std;
long long max(long long a,long long b)
{
	return a>b?a:b;
}
void swap(long long *a,long long *b)
{
	long long t=*a;
	*a=*b;
	*b=t;
}
long long gys(long long a,long long b)
{
	long long t=a%b;
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
	long long a,b;
	scanf("%lld %lld",&a,&b);
	while(a && b)
	{
		if(max(a,b)==b)
		 swap(&a,&b);
		cout<<a*b/gys(a,b)<<endl;
		scanf("%lld %lld",&a,&b);
	}
	return 0;
}
