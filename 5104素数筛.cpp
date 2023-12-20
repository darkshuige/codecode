#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int prime[maxn],judge[maxn];
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
int main()
{
	isprime();
	judge[0]=1;
	int l,r;
	cin>>l>>r;
	int count=0;
	for(int i=l;i<=r;i++)
	{
		if(judge[i]==0)
		 count++;
	}	
	cout<<count<<endl;
	return 0;
}
