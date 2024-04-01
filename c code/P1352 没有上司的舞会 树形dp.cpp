#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=6005;
int f[maxn][2];// f[i][0]表示不取第i个的最大值，f[i][1]表示取
int w[maxn];
bool fa[maxn];
vector<int>g[maxn];
void dfs(int p)
{
	f[p][1]=w[p];
	for(auto v:g[p])
	{
		dfs(v);
		f[p][0]+=max(f[v][0],f[v][1]);
		f[p][1]+=f[v][0];
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
	cout<<max(f[root][0],f[root][1])<<endl;
	return 0;
} 
