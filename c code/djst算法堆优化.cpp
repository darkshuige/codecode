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
const int maxn=2005;
int t,n;
struct edge
{
	int v,w;
};
vector<edge>g[maxn];
int d[maxn],vis[maxn];
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
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			edge ed=g[u][i];
			int v=ed.v,w=ed.w;
			if(d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				q.push(make_pair(-(d[v]),v));
			}
		}
	}
}
signed main()
{
	jiasu;
	cin>>t>>n;
	for(int i=0;i<t;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		edge a1;a1.v=y;a1.w=z;
		g[x].push_back(a1);
		a1.v=x;
		g[y].push_back(a1);
	}
	djst(n);
	cout<<d[1]<<endl;
	return 0;
}
