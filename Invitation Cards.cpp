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
const int maxn=1000005;
int h[maxn],cnt,h1[maxn];
struct edge
{
	int to,w,ne;
}e[maxn],e1[maxn];
int n,m;
int d[maxn],d1[maxn];
void init()
{
	cnt=1;
	for(int i=0;i<=n;i++)
	{
		h[i]=0;
		h1[i]=0;
	}
}
void add(int a,int b,int c)
{
	e[cnt].to=b; e[cnt].w=c; e[cnt].ne=h[a];
	h[a]=cnt;
	e1[cnt].to=a; e1[cnt].w=c; e1[cnt].ne=h1[b];
	h1[b]=cnt++;
}
void djst(int s)
{
	memset(d,inf,sizeof d);
	d[s]=0;
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		pair<int,int>op=q.top();q.pop();
		int u=op.second;
		for(int i=h[u];i;i=e[i].ne)
		{
			int v=e[i].to,w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push(make_pair(-(d[v]),v));
			}
		}
	}
}
void djst1(int s)
{
	memset(d1,inf,sizeof d1);
	d1[s]=0;
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		pair<int,int>op=q.top();q.pop();
		int u=op.second;
		for(int i=h1[u];i;i=e1[i].ne)
		{
			int v=e1[i].to,w=e1[i].w;
			if(d1[v]>d1[u]+w)
			{
				d1[v]=d1[u]+w;
				q.push(make_pair(-(d1[v]),v));
			}
		}
	}
}
void scan(int &x)// ‰»Î
{
	x=0;int f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
signed main()
{
	//jiasu;
	int t;
	scan(t);
	while(t--)
	{
		scan(n);scan(m);
		init();
		for(int i=0;i<m;i++)
		{
			int x,y,z;
			scan(x);scan(y);scan(z);
			add(x,y,z);
		}
		djst(1),djst1(1);
		int ans=0;
		for(int i=1;i<=n;i++)
		 ans+=d[i]+d1[i];
		printf("%lld\n",ans);	
	}
	return 0;
}
