#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
vector<int>g[maxn];
int sum[maxn],size[maxn];//size用来存以u为根节点最大子树的个数
//sum用来存以u为根节点的数的个数
//可以把数分成上面和下面两个部分，下面的个数是sum，上面就是n-sum
int ans=INT_MAX;
int n;
int dfs(int u,int fa)
{
	size[u]=0;
	sum[u]=1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		int s=dfs(v,u);
		size[u]=max(size[u],s);
		sum[u]+=s;
	}
	ans=min(ans,max(size[u],n-sum[u]));
	return sum[u];
}
signed main()
{
	jiasu;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
} 
