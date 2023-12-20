#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
long long c[1000005]={0};
int main()
{
	long long n,m;
	while(scanf("%lld %lld",&n,&m)!=EOF)
	{
		if(n==0)
		 break;
		memset(c,0,sizeof c);
		int i;
		for(i=1;i<=m;i++)
		{
			long long  x,y;
			scanf("%lld %lld",&x,&y);
			c[x]++;
			c[y]--;
		}
		for(i=1;i<=n;i++)
		{
			c[i]+=c[i-1];
			if(i!=1)
			 printf(" ");
			printf("%lld",c[i]);
		}
		printf("\n");
	}
	return 0;
}
