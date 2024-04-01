#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(fasle),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=15;
vector<int>g[maxn];
int dest[maxn][maxn];
int ans;
int vis[maxn];
void dfs(int x,int f,int now)
{
	if(now>ans)
	 ans=now;
	for(auto i:g[x])
	{
		if(i!=f && vis[i]==0)
		{
			vis[i]=1;
			dfs(i,x,now+dest[x][i]);
			vis[i]=0;
		}
	}
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y,d;
		cin>>x>>y>>d;
		g[x].push_back(y);
		g[y].push_back(x);
		dest[x][y]=d;
		dest[y][x]=d;
	}
	ans=0;
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		dfs(i,0,0);
		vis[i]=0;	
	}
	cout<<ans<<endl;
	return 0;
}
