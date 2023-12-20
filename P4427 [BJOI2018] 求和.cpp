#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=300005;
int dep[maxn],fa[maxn][22];
vector<int>g[maxn];
int s[maxn][60],mi[maxn];
const int mod=998244353;
void dfs(int u, int f)
{
	for(int i=1; i<=20; i++) 
	fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i:g[u])
	{
		int v=i;
		if(v==f) continue;
		fa[v][0]=u; dep[v]=dep[u]+1;
		for(int j=1;j<=50;j++) 
		 mi[j]=mi[j-1]*dep[v]%mod;
		for(int j=1;j<=50;j++) 
		 s[v][j]=(mi[j]+s[u][j])%mod;
		dfs(v, u);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])
	 swap(x,y);
	for(int i=20;i>=0;i--)
	{
		if(dep[fa[x][i]]>=dep[y])
		 x=fa[x][i];
	}
	if(x==y)//当y就是x的祖先的时候 
	 return y;
	for(int i=20;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		 x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
signed main()
{
	int n,m;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	mi[0]=1;
	dfs(1,0);
	cin>>m;
	while(m--)
	{
		int u,v,k;
		cin>>u>>v>>k;
		int l=lca(u,v);
		cout<<(s[u][k]+s[v][k]-s[l][k]-s[fa[l][0]][k]+2*mod)%mod<<endl;
	}
	return 0;
}
