#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005,maxe=800005;
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
int flag,n,m,c;
vector<int>g[maxn];
void djst(int s)
{
	memset(vis,0,sizeof vis);
	memset(d,inf,sizeof d);
	d[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		pair<int,int>op=q.top();q.pop();
		int u=op.second;
		if(d[u]<op.first) continue;
		if(vis[u]) continue;
		vis[u]=1;
//		for(auto i:g[u-1])
//		{
//			int w=c;
//			if(d[i]>d[u]+w)
//			{
//				d[i]=d[u]+w;
//				q.push(make_pair(d[i],i));
//			}
//		}
//		for(auto i:g[u+1])
//		{
//			int w=c;
//			if(d[i]>d[u]+w)
//			{
//				d[i]=d[u]+w;
//				q.push(make_pair(d[i],i));
//			}
//		}
		for(int i=h[u];i;i=ne[i])
		{
			int v=to[i];
			if(d[v]>d[u]+w[i])
			{
				d[v]=d[u]+w[i];
				q.push(make_pair(d[v],v));
			}
		}
	}
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int cnt=1;cnt<=t;cnt++)
	{
		for(int i=0;i<maxn;i++) g[i].clear();
		init();
		cin>>n>>m>>c;
		int ma=0;
		for(int i=1;i<=n;i++)
		{
			int l;
			cin>>l;
			add(l+n,i,0);//第l层层节点向i节点连单向边 
			if(l<n)
				add(i,l+n+1,c);//i节点向l+1层连单向边 
			if(l>1)
				add(i,l+n-1,c);//i节点向l-1层连单向边 
		}
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			add(a,b,c);
			add(b,a,c);
		} 
		djst(1);
		int ans=d[n];
		if(ans==inf)
			ans=-1; 
		cout<<"Case #"<<cnt<<": "<<ans<<endl;
	}
	return 0;
}
