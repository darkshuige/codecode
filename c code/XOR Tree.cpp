#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=2e5+10;
int n,ans,a[maxn],siz[maxn],son[maxn],dis[maxn];
vector<int>e[maxn];
set<int>s[maxn];
void dfs(int x,int fa)
{
	s[x].insert(dis[x]);
	bool flag=0;
	for(int y:e[x])
	{
		if(y==fa) continue;
		dis[y]=dis[x]^a[y];
		dfs(y,x);
	
		if(s[x].size()<s[y].size()) swap(s[x],s[y]);//x里面放大的
		
		for(int z:s[y]) //如果s[x]中存在s[y]^a[x]
		{
			if(s[x].find(z^a[x])!=s[x].end())
			 flag=1;
		}
		for(int z:s[y]) s[x].insert(z);
	}
	if(flag) ans++,s[x].clear();
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int a,b; cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dis[1]=a[1];
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}