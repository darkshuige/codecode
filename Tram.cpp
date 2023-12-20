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
const int maxn=400,maxe=maxn*maxn;
int h[maxn],to[maxe],ne[maxe],w[maxe];
int vis[maxn];
int d[maxn];
int cnt,n;
void init()
{
	cnt=1;
	memset(h,0,sizeof h);
}
void add(int a,int b,int c)
{
	to[cnt]=b;w[cnt]=c;ne[cnt]=h[a];
	h[a]=cnt++;
}
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
		for(int i=h[u];i;i=ne[i])
		{
			int v=to[i];
			if(d[v]>d[u]+w[i])
			{
				d[v]=d[u]+w[i];
				q.push(make_pair(-(d[v]),v));
			}
		}
	}
}
signed main()
{
	jiasu;
	int a,b;
	cin>>n>>a>>b;
	init();
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;
		for(int j=0;j<m;j++)
		{
			int op;
			cin>>op;
			if(j==0)
			 add(i,op,0);
			else
			 add(i,op,1);
		}
	}
	djst(a);
	if(d[b]!=inf)
	 cout<<d[b]<<endl;
	else
	 cout<<-1<<endl;
	return 0;
}
