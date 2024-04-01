#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=5005;
char mp[maxn][maxn];
int vis[maxn];
int n;
int dfs(int u,int fa)
{
	vis[u]=1;
	for(int i=1;i<=n;i++)
	{
		if((mp[u][i]-'0'))
		{
			if((mp[i][fa]-'0'))
			{
				cout<<u<<" "<<i<<" "<<fa<<endl;
				return 1;
			}
			if(!vis[i])
			 if(dfs(i,u))
			  return 1;
		}
	}
	return 0;
}
signed main()
{
	jiasu;
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>mp[i]+1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			if(dfs(i,i))
			 return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
