#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=4000;
int w[maxn];
int t,n;
struct edge
{
	int v,w;
};
vector<edge>g[maxn];
int d[maxn],vis[maxn];
void djst(int s)
{
	memset(vis,0,sizeof vis);
	memset(d,inf,sizeof d);
	d[s]=0;
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		pair<int,int>op=q.top();q.pop();
		int u=op.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			edge ed=g[u][i];
			int v=ed.v,w=ed.w;
			if(d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				q.push(make_pair(-(d[v]),v));
			}
		}
	}
}
struct node
{
	int money,len;
	double bi;
}b[maxn];
int cmp(node a,node b)
{
	return a.bi>b.bi;
}
int f[10000000];
signed main()
{
	jiasu;
	int n,m,t; cin>>n>>m>>t;
	for(int i=2;i<=n;i++) cin>>w[i];
	for(int i=0;i<m;i++)
	{
		int x,y,z; cin>>x>>y; z=1;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	djst(1);
	int cnt=0;
	for(int i=2;i<=n;i++)
	{
		int money=w[i],len=d[i]*2;
		double bi=money/len;
		b[cnt++]={money,len,bi};
	}
	for(int i=0;i<cnt;i++)
	{
		for(int j=b[i].len;j<=t;j++)//如果是正序，那么就会把前面的变了会出错会加多次，正符合完全背包的定义
		{
			f[j]=max(f[j],f[j-b[i].len]+b[i].money);//一维就是把i给去了
		}
	}
	for(int i=1;i<=t;i++)
	{
		if(i!=1) cout<<" ";
		cout<<f[i];	
	}
	cout<<endl;
	return 0;
}
