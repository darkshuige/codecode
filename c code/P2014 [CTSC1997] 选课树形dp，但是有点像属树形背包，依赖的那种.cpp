#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=400;
int f[maxn][maxn];//f[j][i][k]表示节点j的前i个节点，限重为k的最大值，可以吧i优化掉，01背包那样
int w[maxn];
bool fa[maxn];
vector<int>g[maxn];
int ma=INT_MIN;
int n,m;
void dfs(int p)
{
	for(auto v:g[p])
	 dfs(v);
	for(auto v:g[p])
	{
		for(int j=m;j>=1;j--)
		{
			for(int k=0;k<j;k++)
			{
				f[p][j]=max(f[p][j],f[p][j-k]+f[v][k]);
			}
		}
	}
}
signed main()
{
	jiasu;
	cin>>n>>m;
	m++;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(i);
		f[i][1]=b;
		w[i]=b;
	}
	dfs(0);
	cout<<f[0][m]<<endl;
	return 0;
} 
