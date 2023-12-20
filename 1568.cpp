#include<bits/stdc++.h>
using namespace std;
long long a[1000000]={0};
const int mod=1000000007;
void init()
{
	a[1]=1;
	a[2]=2;
	for(int i=3;i<1000000;i++)
	{
		a[i]=a[i-1]+a[i-2];
		a[i]%=mod;
	}
}
int f(int n)
{
	int sum=0;
	while(n)
	{
		if(n&1)
		 sum++;
		n>>=1;
	}
	return sum;
}
int main()
{
	init();
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		long long n,op;
		scanf("%lld %lld",&n,&op);
		if(f(a[n])==op)
		 printf("CORRECT\n");
		else
		 printf("INCORRECT\n");
	}
	return 0;
}
