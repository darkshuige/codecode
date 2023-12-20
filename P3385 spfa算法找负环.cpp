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
//spfa就是 Bellman-Ford的优化 
//spfa算法可以反复入队，并且记录入队次数，如果某一个点入队次数大于n了那么肯定是有负环了 
using namespace std;
const int maxn=3005;
struct edge
{
	int v,w;
};
vector<edge>g[maxn];
int d[maxn],vis[maxn],cnt[maxn];
int n,m;
int spfa(int s)
{
	memset(vis,0,sizeof vis);
	memset(d,inf,sizeof d);
	memset(cnt,0,sizeof cnt);
	d[s]=0;
	vis[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();vis[u]=0;
		for(auto ed:g[u])
		{
			int v=ed.v,w=ed.w;
			if(d[u]+w<d[v])
			{
				d[v]=d[u]+w;
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
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<maxn;i++) g[i].clear();
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			g[x].push_back({y,z});
			if(z>=0)
			g[y].push_back({x,z});
		}
		if(spfa(1))
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	}
	return 0;
}
