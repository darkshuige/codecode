#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1005;
vector<int>g[maxn];
int n,l,ans;
int vis[maxn];
void bfs(int now)
{
	memset(vis,0,sizeof vis);
	int cnt=0; ans=0;
	queue<int>q;
	q.push(now); vis[now]=1;
	for(int cnt=1;cnt<=l;cnt++)
	{
		for(int j=0,k=q.size();j<k;j++)
		{
			int u=q.front(); q.pop();
			vis[u]=1;
			for(auto v:g[u])
			{
				if(vis[v]==0)
				{
					vis[v]=1;
					q.push(v);
					ans++;
				}
			}	
		}
	}
	
}
signed main()
{
	cin>>n>>l;
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		for(int j=0;j<k;j++)
		{
			int x; cin>>x;
			g[x].push_back(i);
		}
	}
	int q; cin>>q;
	while(q--)
	{
		int k; cin>>k;
		ans=0;
		bfs(k);
		cout<<ans<<endl;
	}
	return 0;
}