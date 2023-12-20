#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=1005;
vector<int>mp[maxn];
int ans=0,l,r;
string s;
void dfs(int u,int fa,int val,int d)
{
	if(val>r)
	 return ;
	if(val<=r && val>=l && d>1)
	 ans++;
	for(int i=0;i<mp[u].size();i++)
	{
		int v=mp[u][i];
		if(v==fa)
		 continue;
		dfs(v,u,val*2+(s[v]-'0'),d+1);
	}
}
signed main()
{
	int n;
	cin>>n>>l>>r>>s;
	s=" "+s;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,0,s[i]-'0',1);
	}
	cout<<ans<<endl;
	return 0;
}
