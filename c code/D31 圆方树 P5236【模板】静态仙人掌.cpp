#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=200000;
const int maxm=maxn*3;
int n,m,Q;
struct edge
{
	int v,w,ne;
}e[maxm];
int h1[maxn],h2[maxn],idx=1;
int dfn[maxn],low[maxn],tim;
int s[maxn],sc[maxn],fa[maxn],fw[maxn],fe[maxn],cn;//到割点的距离，所在环的长度，父节点，边权，入边
int f[maxn][14],dep[maxn],d[maxn];//lca
int A,B;
void add(int h[],int a,int b,int c)
{
	e[++idx]={b,c,h[a]};
	h[a]=idx;
}
void build_tree(int u,int v,int w)
{
	int sum=w;
	for(int k=v;k!=u;k=fa[k])
	{
		s[k]=sum;
		sum+=fw[k];
	}
	add(h2,u,++cn,0);
	for(int k=v;k!=u;k=fa[k])
	{
		sc[k]=sum;
		add(h2,cn,k,min(s[k],sum-s[k]));
	}
}
void tarjan(int u,int ine)
{
	dfn[u]=low[u]=++tim;
	for(int i=h1[u];i;i=e[i].ne)
	{
		int v=e[i].v,w=e[i].w;
		if(!dfn[v])//没有访问，fw存边权，fe存入边
		{
			fa[v]=u,fw[v]=w,fe[v]=i;
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<low[v])//非环边
			 add(h2,u,v,w);
		}
		else if(i!=(ine^1))//访问过并且是环
		 low[u]=min(low[u],dfn[v]);//不建边 
	}
	for(int i=h1[u];i;i=e[i].ne)
	{
		int v=e[i].v,w=e[i].w;
		if(dfn[u]<dfn[v] && fe[v]!=i)//构成环
		 build_tree(u,v,w);//建树
	}
}
void dfs(int u,int father)
{
	dep[u]=dep[father]+1;
	f[u][0]=father;
	for(int k=1;k<=13;k++)
	 f[u][k]=f[f[u][k-1]][k-1];
	for(int i=h2[u];i;i=e[i].ne)//找邻边
	{
		int v=e[i].v,w=e[i].w;
		d[v]=d[u]+w;//不算距离就没有这两部
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int k=13;k>=0;k--)
	 if(dep[f[u][k]]>=dep[v])
	  u=f[u][k];
	if(u==v) return v;
	for(int k=13;k>=0;k--)
	{
		if(f[u][k]!=f[v][k])
		{
			u=f[u][k];
			v=f[v][k];
		}
	}
	A=u,B=v;
	return f[u][0];
}
signed main()
{
	jiasu;
	cin>>n>>m>>Q;
	cn=n;
	while(m--)
	{
		int a,b,c; cin>>a>>b>>c;
		add(h1,a,b,c); add(h1,b,a,c);
	}
	tarjan(1,-1);//找环建树
	dfs(1,0);//dfs打表
	while(Q--)
	{
		int u,v;
		cin>>u>>v;
		int p=lca(u,v);
		if(p<=n)//如果是圆点
		 cout<<d[u]+d[v]-2*d[p]<<endl;
		else
		{
			int len=abs(s[A]-s[B]);//环上两个点的距离
			int dAB=min(len,sc[A]-len);
			int dis=dAB+d[u]-d[A]+d[v]-d[B];
			cout<<dis<<endl;
		}
	}
	return 0;
}