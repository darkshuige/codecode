#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=500005;
int dep[maxn],fa[maxn][22];
vector<int>g[maxn];
void dfs(int u,int f)
{
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(int i=1;i<=20;i++)
	 fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto y:g[u])
	 if(y!=f)
	  dfs(y,u);
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
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(s,0);
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		cout<<lca(x,y)<<endl;
	}
	return 0;
}
