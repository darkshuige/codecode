#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=10005;
int d[maxn];
int cost[maxn][maxn];
bool vis[maxn];
int cc[maxn];
int n,m,st,ed,h;
void djst(int x)
{
	memset(d,INF,sizeof d);
	memset(vis,0,sizeof vis);
	d[st]=0;
	for(int i=1;i<=n;i++)
	 d[i]=cost[st][i];
	while(1)
	{
		int v=-1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0 && cc[i]<=x && (v==-1 || d[i]<d[v]))
			 v=i;
		}
		if(v==-1)
		 break;
		vis[v]=1;
		for(int i=1;i<=n;i++)
		 d[i]=min(d[i],d[v]+cost[v][i]);
	}
}
int check(int x)
{
	djst(x);
	return d[ed]<=h;
}
signed main()
{
	jiasu;
	cin>>n>>m>>st>>ed>>h;
	for(int i=1;i<=n;i++)
	 cin>>cc[i];
	memset(cost,INF,sizeof cost);
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		cost[x][y]=min(cost[x][y],z);
		cost[y][x]=min(cost[y][x],z);
	}
	int l=0,r=1e7;
	int ans=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
