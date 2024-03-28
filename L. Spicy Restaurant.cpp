#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int d[105][maxn],w[maxn];
vector<int>g[maxn];
int vis[maxn];
queue<int>qq;
void bfs(int la)
{
	memset(vis,0,sizeof vis);
	while(!qq.empty())
	{
		int u=qq.front(); qq.pop();
		for(auto v:g[u])
		{
			if(vis[v]) continue;
			if(d[la][v]==-1)
			 d[la][v]=d[la][u]+1;
			else
			 d[la][v]=min(d[la][v],d[la][u]+1);
			vis[v]=1;
			qq.push(v);
		}
	}
}
signed main()
{
	jiasu;
	int n,m,q; cin>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(d,-1,sizeof d);
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=n;j++)
		 if(w[j]==i)
		 {
		 	qq.push(j);
		 	d[i][j]=0;
		 	vis[j]=1;
		 }
		bfs(i);
		while(!qq.empty()) qq.pop();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=100;j++)
		{
			if(d[j][i]==-1)
		     d[j][i]=d[j-1][i];	
		    if(d[j-1][i]!=-1)
		     d[j][i]=min(d[j-1][i],d[j][i]);
		}
	}
	while(q--)
	{
		int now,l;
		cin>>now>>l;
		cout<<d[l][now]<<endl;
	}
	return 0;
}