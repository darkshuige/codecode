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
	int s1=0,s2=0;
	if(dep[x]<dep[y])
	 swap(x,y);
	for(int i=20;i>=0;i--)
	{
		if(dep[fa[x][i]]>=dep[y])
		 x=fa[x][i],s1+=(1<<i);
	}
	if(x==y)//当y就是x的祖先的时候 
	 return s1;
	for(int i=20;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		 x=fa[x][i],y=fa[y][i],s1+=(2<<i),s2+=(1<<i);
	}
	return s1+s2;
}
signed main()
{
	int n,s;
	cin>>n; s=1;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(s,0);
	int sum=0;
	for(int i=1;i<=n;i++)
	 for(int j=i+1;j<=n;j++)
	  sum+=min(i*j,lca(i,j));
	cout<<sum*2<<endl;
	return 0;
}