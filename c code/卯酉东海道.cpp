#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
const int maxn=500052;
int n,m,l,base;
struct edge
{
	int v,w,col;
};
vector<edge>g[maxn];
int d[maxn],vis[maxn];
void djst(int s,int cc)
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
			int col=ed.col;
			if(col!=cc)
			{
				w*=base;
				cc=col;
			}
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
	cin>>n>>m>>l>>base;
	for(int i=0;i<m;i++)
	{
		int x,y,col,z;
		cin>>x>>y>>col>>z;
		g[x].push_back({y,z,col});
	}
	int mi=inf;
	for(int i=1;i<=l;i++)
	{
		djst(1,i);
		mi=min(d[n],mi);
	}
	if(mi!=inf)
	 cout<<mi<<endl;
	else
	 cout<<-1<<endl;
	return 0;
}