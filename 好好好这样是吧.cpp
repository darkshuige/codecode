#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2000;
const int mod=998244353;
int g[maxn][maxn],d[maxn],f[maxn],vis[maxn],g1[maxn][maxn];
int n,a,b,c;
void djst(int s)
{
	memset(d,inf,sizeof d);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)
	{
		d[i]=g[s][i];
	}
	d[s]=0;
	while(true)
	{
		int v=-1;
		for(int u=1;u<=n;u++)
		{
			if(!vis[u] && (v==-1 || d[u]<d[v]))
			 v=u;
		}
		if(v==-1)
		 break;
		vis[v]=1;
		for(int u=1;u<=n;u++)
		{
			d[u]=min(d[u],d[v]+g[v][u]);
		}
	}
}
void djst1(int s)
{
	memset(f,inf,sizeof f);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)
	{
		f[i]=g1[s][i];
	}
	f[s]=0;
	while(true)
	{
		int v=-1;
		for(int u=1;u<=n;u++)
		{
			if(!vis[u] && (v==-1 || f[u]<f[v]))
			 v=u;
		}
		if(v==-1)
		 break;
		vis[v]=1;
		for(int u=1;u<=n;u++)
		{
			f[u]=min(f[u],f[v]+g1[v][u]);
		}
	}
}
signed main()
{
	jiasu;
	cin>>n>>a>>b>>c;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>g[i][j];
			g1[i][j]=g[i][j];
			g[i][j]=g[i][j]*a;
			g1[i][j]=g1[i][j]*b+c;
		}
	}
	djst1(n);
	djst(1);
	int ans=inf;
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,d[i]+f[i]);
	}
	cout<<ans<<endl;
	return 0;
}
