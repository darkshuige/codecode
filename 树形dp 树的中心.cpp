#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
vector<pair<int,int> >g[maxn];
int d1[maxn],d2[maxn],p[maxn],up[maxn];
//d1,d2存以u为跟的最长边和次长边，p存以u为跟最长边的第一个子节点
//up存以u为跟往上走的最大边
int ans=INT_MAX;
int n;
//一共两次dfs，一次自下而上，一次自上而下
int dfs_d(int u,int fa)//自下而上的dfs
{
	for(auto kk:g[u])
	{
		int v=kk.first,w=kk.second;
		if(v==fa) continue;
		int d=dfs_d(v,u)+w; //dfs函数返回的是以v为根节点的最长路径所以要加上边权就是以u的长度
		if(d>d1[u])//自下而上，先dfs再改
		{
			d2[u]=d1[u];
			d1[u]=d;
			p[u]=v;
		}
		else
		 d2[u]=d;
	}
	return d1[u];
}
void dfs_u(int u,int fa)//自上而下
{
	for(auto kk:g[u])
	{
		int v=kk.first,w=kk.second;
		if(v==fa) continue;
		if(p[u]==v) //如果v在最大路径上
		 up[v]=max(up[u],d2[u])+w;//先改变在dfs，自上而下
		else
		 up[v]=max(up[u],d1[u])+2;
		dfs_u(v,u);
	}
}
signed main()
{
	jiasu;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	dfs_d(1,0);
	dfs_u(1,0);
	for(int i=1;i<=n;i++)
	 ans=min(ans,max(up[i],d1[i]));
	cout<<ans<<endl;
	return 0;
} 
