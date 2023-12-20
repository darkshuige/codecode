#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=205,maxe=1e5+10;
int a[maxn];
int h[maxn],to[maxe],ne[maxe],w[maxe],ind;
void init()
{
	ind=1;
	memset(h,0,sizeof h);
}
void add(int a,int b,int c)
{
	to[ind]=b;w[ind]=c;ne[ind]=h[a];
	h[a]=ind++;
}
int d[maxn],vis[maxn],cnt[maxn];
int col[maxn];
int flag,n;
void dfs(int u)
{
	col[u]=1;
	for(int i=h[u];i;i=ne[i])
	{
		int v=to[i];
		if(col[v]==0) dfs(v);
	}
}
void spfa(int s)
{
	memset(col,0,sizeof col);
	memset(cnt,0,sizeof cnt);
	memset(vis,0,sizeof vis);
	memset(d,inf,sizeof d);
	d[s]=0;vis[s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();vis[u]=0;
		if(col[u]) continue;
		for(int i=h[u];i;i=ne[i])
		{
			int v=to[i];
			if(d[v]>d[u]+w[i])
			{
				d[v]=d[u]+w[i];
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n)
				{
					dfs(v);
				}
				if(vis[v]==0)
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
signed main()
{
	int t;
	cin>>t;
	for(int cnt=1;cnt<=t;cnt++)
	{
		init();
		cin>>n;
		for(int i=1;i<=n;i++)
		 cin>>a[i];
		int m;
		cin>>m;
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			int w=pow(a[y]-a[x],3);
			add(x,y,w);
		}
		spfa(1);
		int q;
		cin>>q;
		int ans[maxn];
		for(int i=0;i<q;i++)
		{
			int op;
			cin>>op;
			if(col[op]==1)
			 ans[i]=-1;
			else
			{
				if(d[op]<3 || d[op]==inf)
				 ans[i]=-1;
				else
				 ans[i]=d[op];
			}
		}
		cout<<"Case "<<cnt<<":"<<endl;
		for(int i=0;i<q;i++)
		 if(ans[i]==-1)
		  cout<<"?"<<endl;
		 else
		  cout<<ans[i]<<endl;
	}
	return 0;
}
