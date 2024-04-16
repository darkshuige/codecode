#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf (1<<31)-1
using namespace std;
const int maxn=200005;
int d[maxn],vis[maxn];
int n,m,s;
vector<pair<int,int> >g[maxn];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void djst(int s)
{
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++) d[i]=inf;
	d[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second; q.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		for(auto k:g[u])
		{
			int v=k.first,w=k.second;
			if((d[u]+w)<d[v])
			{
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
}
signed main()
{
	jiasu;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		int a,b,w; cin>>a>>b>>w;
		g[a].push_back({b,w});
	}
	djst(s);
	for(int i=1;i<=n;i++)
	{
		if(i!=1) cout<<" ";
		cout<<d[i];
	}
	return 0;
} 	