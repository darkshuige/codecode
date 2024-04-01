#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int prime[maxn];
bool judge[maxn];
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
int d[maxn];
int n;
int flag;
int a,b;
bool vis[maxn];
void bfs(int now)
{
	memset(vis,0,sizeof vis);
	vis[now]=1;
	memset(d,inf,sizeof d);
	d[now]=0;
	int flag=0;
	queue<int>q;
	q.push(now);
	while(!q.empty() && vis[b]==0)
	{
		int t=q.front();q.pop();
		int temp[5];
		for(int i=1;i<=4;i++)
		{
			temp[1]=t/1000;temp[2]=(t%1000)/100;temp[3]=(t%100)/10;temp[4]=t%10;
			if(i==1)
			{
				for(int j=1;j<=9;j++)
				{
					temp[i]=j;
					int op=temp[1]*1000+temp[2]*100+temp[3]*10+temp[4];
					if(vis[op]==0 && !judge[op])
					{
						d[op]=d[t]+1;
						q.push(op);
						vis[op]=1;
					}
				}
			}
			else
			{
				for(int j=0;j<=9;j++)
				{
					temp[i]=j;
					int op=temp[1]*1000+temp[2]*100+temp[3]*10+temp[4];
					if(vis[op]==0 && !judge[op])
					{
						d[op]=d[t]+1;
						q.push(op);
						vis[op]=1;
					}
				}
			}
			
		}
	}
}
signed main()
{
	jiasu;
	isprime();
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		bfs(a);
		cout<<d[b]<<endl;
	}
	return 0;
}
