#include<iostream>
#include<stdio.h>
using namespace std;
long long ksm(int a,int n)
{
	long double sum=1;
	while(n)
	{
		if(n&1)
		{
			sum=sum*a;
		}
		a=a*a;
		n>>1;	
	}
	return sum;
}
int main()
{
	int t,i;
	cin>>t;
	for(i=0;i<t;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a==b)
		{
			cout<<"0"<<endl;
		}
		else 
		 printf("%lld\n",ksm(a,b)-ksm(b,a));
	}
	return 0;
}
