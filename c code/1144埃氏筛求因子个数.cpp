#include<bits/stdc++.h>
using namespace std;
const int mod=1073741824;
const int maxn=1000010;
int sum[maxn]={0};
void init()//埃氏筛求因子个数 
{
	for(int i=1;i<maxn;i++)
	{
		for(int j=i;j<maxn;j+=i)
		{
			sum[j]++;
		}
	}
}
int main()
{
	int a,b,c;
	init();
	while(scanf("%d %d %d",&a,&b,&c)!=EOF)
	{
		long long Sum=0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				for(int k=1;k<=c;k++)
				{
					Sum+=sum[i*j*k];
					Sum%=mod;
				}
			}
		}
		printf("%lld\n",Sum);
	}
	return 0;
}
