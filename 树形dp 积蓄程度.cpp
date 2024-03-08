#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
vector<pair<int,int> >g[maxn];
int d[maxn],f[maxn],deg[maxn];
//d用来存最大下流量，d[i]+=min(d[j],w[i]) 自下而上
//f用来存最大总流量 自上而下 设j是i的子节点,j在i这条路的下流量U=min(d[j],w[i])
//f[i]=U+其他 对于j而言，f[j]=d[j]+上流量 上流量就是i的其他也就是 f[i]-U
//f[j]=d[j]+min(w[i],f[i]-min(d[j],w[i])
int ans=INT_MIN;
int n;
//一共两次dfs，一次自下而上，一次自上而下
int dfs_d(int u,int fa)//自下而上的dfs
{
	for(auto kk:g[u])
	{
		int v=kk.first,w=kk.second;
		if(v==fa) continue;
		int s=dfs_d(v,u);
		d[u]+=min(w,s);
	}
	if(deg[u]==1) return inf;//叶子结点特殊处理
	else return d[u];
}
void dfs_u(int u,int fa)//自上而下
{
	for(auto kk:g[u])
	{
		int v=kk.first,w=kk.second;
		if(v==fa) continue;
		if(deg[u]==1) f[v]=d[v]+w;//叶子结点特殊处理
		else f[v]=d[v]+min(w,f[u]-min(d[v],w));
		dfs_u(v,u);
	}
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) g[i].clear();
		memset(d,0,sizeof d); memset(f,0,sizeof f);memset(deg,0,sizeof deg);
		for(int i=1;i<n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			g[a].push_back({b,c});
			g[b].push_back({a,c});
			deg[a]++; deg[b]++;
		}
		dfs_d(1,0);
		f[1]=d[1];
		dfs_u(1,0);
		ans=INT_MIN;
		for(int i=1;i<=n;i++)
		 ans=max(ans,f[i]);
		cout<<ans<<endl;	
	}
	return 0;
} 
