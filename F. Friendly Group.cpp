#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1000005;
int ex[]={-1,+0,+1,-1};
int ey[]={+0,+1,+0,-1};
vector<int>g[maxn];
bool vis[maxn];
int summ,sumn;
int dfs(int u)
{
	sumn++;
	summ+=g[u].size();
	for(auto v:g[u])
	{
		if(vis[v]==1) continue;
		vis[v]=1;
		dfs(v);
	}
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int cnt=1;cnt<=t;cnt++)
	{
		int n,m;
		cin>>n>>m;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)
		 g[i].clear();
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		cout<<"Case #"<<cnt<<": ";
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1) continue;
			vis[i]=1;
			summ=0,sumn=0;
			dfs(i);
			ans+=max((int)0,summ/2-sumn);
		}
		cout<<ans<<endl;
	}
	return 0;
}
