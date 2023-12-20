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
#include<iomanip>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005,maxe=800005;
int h[maxn],to[maxe],ne[maxe],w[maxe],ind;
void init()
{
	ind=1;
	memset(h,0,sizeof h);
}
void add(int a,int b,int c)
{
	to[ind]=b;w[ind]=c;ne[ind]=h[a];
	h[a]=ind++;
}
int d[maxn],vis[maxn],cnt[maxn];
int n,ml,md;
int spfa(int s)
{
	memset(cnt,0,sizeof cnt);
	memset(vis,0,sizeof vis);
	memset(d,inf,sizeof d);
	d[s]=0;vis[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();vis[u]=0;
		for(int i=h[u];i;i=ne[i])
		{
			int v=to[i];
			if(d[v]>d[u]+w[i])
			{
				d[v]=d[u]+w[i];
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n) return 1;
				if(vis[v]==0)
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return 0;
}
signed main()
{
	jiasu;
	cin>>n>>ml>>md;
	for(int i=1;i<=n;i++)
	 add(0,i,0);
	for(int i=0;i<ml;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}
	for(int i=0;i<md;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(b,a,-c);
	}
	if(spfa(0))
	 cout<<-1<<endl;
	else
	{
		spfa(1);
		if(d[n]==inf)
		 cout<<-2<<endl;
		else
		 cout<<d[n]<<endl;
	}
	return 0;
}
