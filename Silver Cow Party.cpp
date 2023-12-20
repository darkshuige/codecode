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
const int maxn=100005;
struct edge
{
	int v,w;
};
vector<edge>g[maxn];
int d[maxn],d1[maxn],vis[maxn];
void djst(int s)
{
	memset(vis,0,sizeof vis);
	memset(d,inf,sizeof d);
	d[s]=0;
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		pair<int,int>op=q.top();q.pop();
		int u=op.second;
		for(int i=0;i<g[u].size();i++)
		{
			edge a=g[u][i];
			int v=a.v,w=a.w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push(make_pair(-(d[v]),v));
			}
		}
	}
}
void djst2(int s)
{
	memset(vis,0,sizeof vis);
	memset(d1,inf,sizeof d1);
	d1[s]=0;
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		pair<int,int>op=q.top();q.pop();
		int u=op.second;
		for(int i=0;i<g[u].size();i++)
		{
			edge a=g[u][i];
			int v=a.v,w=a.w;
			if(d1[v]>d1[u]+w)
			{
				d1[v]=d1[u]+w;
				q.push(make_pair(-(d1[v]),v));
			}
		}
	}
}
signed main()
{
	jiasu;
	int n,m,x;
	cin>>n>>m>>x;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		edge a;a.v=y,a.w=z;
		g[x].push_back(a);
	}
	djst(x);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i==x) continue;
		djst2(i);
		ans=max(ans,d1[x]+d[i]);
	}
	cout<<ans<<endl;
	return 0;
}
