#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2000;
vector<pair<int,int >>g[maxn];
int a[maxn][maxn],b[maxn][maxn];
int f[maxn];
void dfs(int u)
{
	for(auto k:g[u])
	{
		int v=k.first,w=k.second;
		f[v]=max(f[v],f[u]+w);
		if(u!=1)
		 dfs(v);
	}
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>a[i][j];
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>b[i][j];
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  g[b[i][j]].push_back({i,a[i][j]});
	f[n+1]=0;
	dfs(n+1);
	cout<<f[1]<<endl;
	return 0;
}