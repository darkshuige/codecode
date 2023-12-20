#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f
using namespace std;
const int maxn=100005;
int a[maxn];
double PI=acos(-1);
int ans;
int n,m,x;
map<pair<int,int>,int>vis;
void dfs(int now,int sum)
{
	if(sum>ans) return ;
	if(now==0)
	{
		ans=min(ans,sum);
		return ;	
	} 
	for(int i=0;i<n;i++)
	{
		int op=(now+(a[i])%m)%n;
		if(vis[{op,i}]==1) continue;
		vis[{op,i}]=1;
		dfs(op,sum+1);
		vis[{op,i}]=0;
	}
}
signed main()
{
	jiasu;
	cin>>n>>m>>x;
	for(int i=0;i<m;i++)
	 cin>>a[i];
	ans=inf;
	dfs(x,0);
	if(ans!=inf)
	 cout<<ans<<endl;
	else
	 cout<<-1<<endl; 
	return 0;
}
