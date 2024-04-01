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
const int maxn=1010,maxe=1e4+10;
int h[maxn],to[maxe],ne[maxe],w[maxe];
int vis[maxn];
int l[maxn],d[maxn];
int cnt,n,m;
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
int spfa(int left,int right)
{
	memset(vis,0,sizeof vis);
	memset(d,inf,sizeof d);
	vis[0]=1;d[0]=0;
	queue<int>q;
	q.push(0);
	while(!q.empty())
	{
		int op=q.front();q.pop();vis[op]=0;
		for(int i=h[op];i;i=ne[i])
		{
			int j=to[i];
			if(l[j]<left || l[j]>right) continue;
			if(d[j]>d[op]+w[i])
			{
				d[j]=d[op]+w[i];
				if(vis[j]==0)
				{
					vis[j]=1;
					q.push(j);
				}
			}
		}
	}
	return d[1];
}
signed main()
{
	cin>>m>>n;
	init();
	for(int i=1;i<=n;i++)
	{
		int p,le,x;
		cin>>p>>le>>x;
		add(0,i,p);
		l[i]=le;
		for(int j=0;j<x;j++)
		{
			int t,v;
			cin>>t>>v;
			add(t,i,v);
		}
	}
	int s=inf;
	for(int i=l[1]-m;i<=l[1];i++)
	 s=min(s,spfa(i,i+m));
	cout<<s<<endl;
	return 0;
}
