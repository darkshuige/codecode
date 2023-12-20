#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=400000;
struct node
{
	int v,w;
};
int d[maxn],vis[maxn];
vector<node>g[maxn];
int n,m,ans;
int prim(int s)
{
	ans=0;memset(vis,0,sizeof vis);
	memset(d,inf,sizeof d);
	d[s]=0;
	priority_queue<pair<int,int> >q;
	q.push({0,s});
	int cnt=0;
	while(!q.empty())
	{
		pair<int,int>op=q.top();q.pop();
		int u=op.second;
		if(vis[u]) continue;
		vis[u]=1;
		cnt++;
		ans+=d[u];
		for(auto ed:g[u])
		{
			int v=ed.v,w=ed.w;
			if(d[v]>w)
			{
				d[v]=w;
				q.push({-(d[v]),v});
			}
		}
	}
	return cnt==n;
}
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	if(prim(1))
	 cout<<ans<<endl;
	else
	 cout<<"orz"<<endl;
    return 0;
}
