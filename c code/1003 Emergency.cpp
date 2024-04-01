#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=510;
int n,m,c1,c2;
vector<pair<int,int> >g[maxn];
bool vis[maxn];
int num[maxn];
int sum[maxn];
int st,ans;
void dfs(int now,int l,int s,int f)
{
	if(now==c2)
	{
		sum[l]++;
		st=min(st,l);
		return ;
	}
	for(auto v:g[now])
	{
		if(v.first==f) continue;
		if(vis[v.first]) continue;
		vis[v.first]=1;
		dfs(v.first,l+v.second,s+num[v.first],now);
		vis[v.first]=0;
	}
}
void dfs2(int now,int l,int s,int f)
{
	if(now==c2)
	{
		if(l==st)
		 ans=max(ans,s);
		return ;
	}
	for(auto v:g[now])
	{
		if(v.first==f) continue;
		if(vis[v.first]) continue;
		vis[v.first]=1;
		dfs2(v.first,l+v.second,s+num[v.first],now);
		vis[v.first]=0;
	}
}
signed main()
{
	while(cin>>n>>m>>c1>>c2)
	{
		memset(sum,0,sizeof sum);
		for(int i=0;i<n;i++)
		 cin>>num[i];
		for(int i=0;i<m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			g[x].push_back({y,z});
			g[y].push_back({x,z});
		}
		ans=0;
		memset(vis,0,sizeof vis);
		st=INT_MAX;
		dfs(c1,0,num[c1],-1);
		memset(vis,0,sizeof vis);
		dfs2(c1,0,num[c1],-1);
		cout<<sum[st]<<" "<<ans<<endl;
	}
	return 0;
} 
