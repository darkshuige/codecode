#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int judge[maxn];
int prime[maxn];
int num[maxn];
int a,b,k;
void isprime()
{
	memset(judge,0,sizeof judge);
	int index=0;
	for(int i=2;i<maxn;i++)
	{
		if(judge[i]==0)
		 prime[index++]=i;
		for(int j=0;j<index && prime[j]*i<maxn;j++)
		{
			judge[i*prime[j]]=1;
			if(i%prime[j]==0)
			 break;
		}
	}
}
void init()
{
	isprime();
	memset(num,0,sizeof num);
	for(int i=2;i<maxn;i++)
	{
		if(judge[i]==0)
		 num[i]=num[i-1]+1;
		else
		 num[i]=num[i-1];
	}
}
int check(int x)
{
	for(int i=a;i<=b-x+1;i++)
	{
		if(num[i+x-1]-num[i-1]<k)
		 return 0;
	}
	return 1;
}
int main()
{
	init();
	while(cin>>a>>b>>k)
	{
		int l=1,r=b-a+1,flag=0,mid;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid))
			{
				r=mid-1;
				flag=1;
			}
			else
			 l=mid+1;
		}
		if(flag)
		 cout<<l<<endl;
		else
		 cout<<-1<<endl;
	}
	return 0;
} 
