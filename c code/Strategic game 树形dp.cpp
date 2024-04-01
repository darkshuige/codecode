#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=1000055;
int f[maxn][2];// f[i][0]表示不取第i个的最小值，f[i][1]表示取
bool fa[maxn];
vector<int>g[maxn];
void dfs(int p)
{
	f[p][1]=1;
	for(auto v:g[p])
	{
		dfs(v);
		f[p][0]+=f[v][1];
		f[p][1]+=min(f[v][0],f[v][1]);
	}
}
signed main()
{
	jiasu;
	int n;
	while(cin>>n)
	{
		memset(f,0,sizeof f);memset(fa,0,sizeof fa);
		for(int i=0;i<=n;i++) g[i].clear();
		for(int i=0;i<n;i++)
		{
			int y; cin>>y;
			int k; char kk;
			cin>>kk>>kk>>k>>kk;
			for(int j=0;j<k;j++)
			{
				int x;
				cin>>x;
				g[y].push_back(x);
				fa[x]=1;
			}
		}
		int root;
		for(int i=0;i<n;i++) if(fa[i]==0)
		{
			root=i;
			break;
		}
		dfs(root);
		cout<<min(f[root][0],f[root][1])<<endl;	
	}
	
	return 0;
} 
