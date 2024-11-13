#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1050;
int n,m,c1,c2;
vector<pair<int,int> >g[maxn];
bool vis[maxn];
int d[maxn];
int num[maxn];
int ma=INT_MIN,cnt=0;
void djst(int s)
{
	memset(vis,0,sizeof vis);
	memset(d,inf,sizeof d);
	d[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push({0,s});
	while(!q.empty())
	{
		auto k=q.top(); q.pop();
		int u=k.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto dd:g[u])
		{
			int v=dd.first,w=dd.second;
			if(d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
}
void dfs(int now,int fa,int total,int ct)
{
	if(total>d[c2]) return ;
	if(now==c2)
	{
		if(total==d[c2])
		{
			cnt++;
			if(ct>ma)
			 ma=ct;
		}
		return ;
	}
	for(auto k:g[now])
	{
		int v=k.first,w=k.second;
		if(v==fa) continue;
		dfs(v,now,total+w,ct+num[v]);
	}
}
signed main()
{
	cin>>n>>m>>c1>>c2;
	for(int i=0;i<n;i++)
	 cin>>num[i];
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	djst(c1);
	dfs(c1,-1,0,num[c1]);
	cout<<cnt<<" "<<ma<<endl;
	return 0;
} 