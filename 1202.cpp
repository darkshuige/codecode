#include<bits/stdc++.h>
using namespace std;
const long long m=1000000007;
long long skm(long long a,long long n)
{
	long long sum=1;
	while(n)
	{
		if(n&1)
		{
			sum=(sum*a)%m;
		}
		a=(a*a)%m;
		n>>=1;
	}
	return sum;
}
int main()
{
	
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		long long sum=0;
		int i;
		if(n==0)
		{
			printf("1\n");	
		}	
		else
		{
			printf("%lld\n",(1-skm(3,n+1))*(-500000004)%1000000007);
		}
	}
	
	return 0;
}
