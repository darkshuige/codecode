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
//#define int long long
#define endl "\n"
#define inf 0x3f
using namespace std;
const int maxn=35005;
const int maxe=155005;
int h[maxn],cnt;
struct edge
{
	int to,w,ne;
}e[maxe];
int n,m;
int d[maxn];
void init()
{
	cnt=1;
	for(int i=0;i<=n;i++)
	 h[i]=0;
}
void add(int a,int b,int c)
{
	e[cnt].to=b; e[cnt].w=c; e[cnt].ne=h[a];
	h[a]=cnt++;
}
void djst(int s)
{
	memset(d,inf,sizeof d);
	d[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		pair<int,int>op=q.top();q.pop();
		int u=op.second;
		if(d[u]<op.first) continue;
		for(int i=h[u];i;i=e[i].ne)
		{
			int v=e[i].to,w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push(make_pair(d[v],v));
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
	scan(n);scan(m);
	init();
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		scan(x);scan(y);scan(z);
		add(x,y,z);
	}
	djst(1);
	printf("%d\n",d[n]);	
	return 0;
}
