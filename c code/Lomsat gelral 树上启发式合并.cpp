#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=1e5+10;
int n,col[maxn],siz[maxn],son[maxn],cnt[maxn],mx;
int sum,ans[maxn];
vector<int>e[maxn];
void dfs1(int u,int fa)
{
	siz[u]=1;
	for(auto v:e[u])
	{
		if(v==fa) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	} 
}
void add(int x,int fa,int son)
{
	cnt[col[x]]++;
	if(cnt[col[x]]>mx) mx=cnt[col[x]],sum=col[x];
	else if(cnt[col[x]]==mx) sum+=col[x];
	
	for(int v:e[x])//加轻儿子
	 if(v!=fa && v!=son)
	  add(v,x,son);
}
void sub(int x,int fa)
{
	cnt[col[x]]--;
	for(int y:e[x])
	{
		if(y!=fa) sub(y,x);
	}
 }
void dfs2(int u,int fa,int opt)
{
	for(auto v:e[u])//先搜轻儿子
	 if(v!=fa && v!=son[u])
	  dfs2(v,u,0);//轻儿子就是0; 
	if(son[u]) dfs2(son[u],u,1);//有重儿子最后搜重儿子
	
	add(u,fa,son[u]);//累加v和轻子树贡献
	ans[u]=sum;
	if(!opt) sub(u,fa),sum=mx=0;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>col[i];
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs1(1,0);
	dfs2(1,0,0);
	for(int i=1;i<=n;i++)
	 cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}