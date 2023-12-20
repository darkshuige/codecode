#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#include<iomanip>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
#define double float
const int maxn=200;
int n,m,st;
double vv;
struct node
{
	int v;
	double res,rate;
};
vector<node>g[maxn];
int cnt[maxn],vis[maxn];
double d[maxn];
int spfa(int st)
{
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	memset(d,inf,sizeof d);
	d[st]=vv;vis[st]=1;
	queue<int>q;
	q.push(st);
	while(!q.empty())
	{
		int u=q.front();q.pop();vis[u]=0;
		for(int i=0;i<g[u].size();i++)
		{
			node a=g[u][i];
			int v=a.v;
			double rate=a.rate,res=a.res;
			if(d[v]<(d[u]-res)*rate)
			{
				d[v]=(d[u]-res)*rate;
				if(d[v]<0) return 0;
				cnt[v]=cnt[u]+1;
				if(cnt[v]>=n) return 1;
				if(vis[v]==0)
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return 0;
}
signed main()
{
	jiasu;
	cin>>n>>m>>st>>vv;
	for(int i=0;i<m;i++)
	{
		int x,y;
		node a;
		cin>>x>>y>>a.rate>>a.res;
		a.v=y;
		g[x].push_back(a);
		a.v=x;cin>>a.rate>>a.res;
		g[y].push_back(a);
	}
	if(spfa(st))
	 cout<<"YES"<<endl;
	else
	 cout<<"NO"<<endl;
	return 0;
}
