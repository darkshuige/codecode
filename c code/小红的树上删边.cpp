#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=100005;
const int mod=1000000007;
int a[maxn];
vector<int>g[maxn];
int siz[maxn];
int sum=0;
void dfs(int now,int fa)
{
	for(auto v:g[now])
	{
		if(v==fa) continue;
		dfs(v,now);
		siz[now]+=siz[v];
		if(siz[v]%2==0) sum++;
	}
}
signed main() 
{
    jiasu;
	int n; cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=1;i<=n;i++) siz[i]=1;
	dfs(1,0);
	if(n%2==0)
	 cout<<sum<<endl;
	else 
	 cout<<-1<<endl;
    return 0;
}
