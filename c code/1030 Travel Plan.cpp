#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=505;
struct node
{
	int to;
	int dis;
	int cost;
};
vector<node>g[maxn];
int n,m,st,ed;
int vis[maxn];
int d[maxn];
vector<node>pri[maxn];
void djst(int s)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	memset(vis,0,sizeof vis); 
	fill(d,d+n,inf); d[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		auto k=q.top(); q.pop();
		int u=k.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto k:g[u])
		{
			int v=k.to;
			int w=k.dis;
			if(d[u]+w<=d[v])
			{
				d[v]=d[u]+w;
				q.push({d[v],v});
				pri[v].push_back({u,w,k.cost});
			}
		}
	}
}
deque<int>aannss,ans;
int mi=INT_MAX;
void dfs(int now,int total,int todis)
{
	if(now==st)
	{
		if(total<mi && todis==d[ed])
		{
			mi=total;
			aannss=ans;
			return ;
		}
	}
	for(auto k:pri[now])
	{
		int v=k.to;
		int cost=k.cost;
		if(vis[v]) continue;
		vis[v]=1;
		ans.push_back(v);
		dfs(v,total+cost,todis+k.dis);
		ans.pop_back();
		vis[v]=0;
	}
	return ;
}
signed main()
{
	cin>>n>>m>>st>>ed;
	while(m--)
	{
		int a,b,c,d; cin>>a>>b>>c>>d;
		g[a].push_back({b,c,d});
		g[b].push_back({a,c,d});
	}
	djst(st);
	memset(vis,0,sizeof vis); vis[ed]=1;
	ans.push_back(ed);
	dfs(ed,0,0);
	reverse(aannss.begin(),aannss.end());
	for(int i=0;i<aannss.size();i++)
	{
		if(i!=0) cout<<" ";
		cout<<aannss[i];
	}
	cout<<" "<<d[ed]<<" "<<mi<<endl;
	return 0;
} 
