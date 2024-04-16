#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf (1<<31)-1
using namespace std;
const int maxn=500010;
int n,m,s,a,b;
vector<int>e[maxn];//记录边
int fa[maxn],son[maxn],dep[maxn],siz[maxn];//父节点，重儿子节点，深度，子节点个数
int top[maxn];//u所在重链的顶点
void dfs1(int u,int f) // fa,son,dep
{
	fa[u]=f; siz[u]=1; dep[u]=dep[f]+1;
	for(auto v:e[u])
	{
		if(v==f) continue;
		dfs1(v,u);
		//回来的时候
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;//一开始都是0
	}
}
void dfs2(int u,int t)// top
{
	top[u]=t;//记录链头
	if(!son[u]) return ;//无重儿子，叶子结点
	dfs2(son[u],t);     //搜重儿子
	//回来的时候
	for(auto v:e[u])
	{
		if(v==fa[u] || v==son[u]) continue;//搜过
		dfs2(v,v);//搜轻儿子 
	}
}
int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v); //u始终是深的那个
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
signed main()
{
	jiasu;
	cin>>n>>m>>s;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs1(s,0);
	dfs2(s,s);
	while(m--)
	{
		cin>>a>>b;
		cout<<lca(a,b)<<endl;
	}
	return 0;
} 	