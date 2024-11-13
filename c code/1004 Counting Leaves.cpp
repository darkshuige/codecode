#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1050;
vector<int>g[maxn];
map<int,int>mp,ans;
void dfs(int now,int dp)
{
	mp[now]=dp;
	for(auto v:g[now])
	{
		dfs(v,dp+1);
	}
}
signed main()
{
	int n,m; cin>>n>>m;
	while(m--)
	{
		int a,k; cin>>a>>k;
		while(k--)
		{
			int b; cin>>b;
			g[a].push_back(b);
		}
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()==0)
		 ans[mp[i]]++;
	}
	int kk=ans.size();
	auto it=ans.begin();
	for(int j=1;j<kk;j++) it++;
	for(int i=1;i<=(*it).first;i++)
	{
		if(i!=1) cout<<" ";
		cout<<ans[i];
	}
	return 0;
} 