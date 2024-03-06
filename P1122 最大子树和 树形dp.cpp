#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=17000;
int f[maxn];
int w[maxn];
bool fa[maxn];
vector<int>g[maxn];
int ma=INT_MIN;
void dfs(int p)
{
	f[p]=w[p];
	for(auto v:g[p])
	{
		dfs(v);
		if(f[v]>=0)
		 f[p]+=f[v];
		ma=max(ma,f[p]);
	}
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		g[b].push_back(a);
		fa[a]=1;
	}
	int root;
	for(int i=1;i<=n;i++) if(fa[i]==0)
	{
		root=i;
		break;
	}
	dfs(root);
	cout<<ma<<endl;
	return 0;
} 
