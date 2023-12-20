#include <iostream>
#include <cstdio>
#include <algorithm>
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
#include<string>
#include<stack>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
//#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1000;
int n,m;
struct edge
{
	int u,v;
	double w;
}a[maxn*maxn];
struct node
{
	double x,y;
}g[maxn];
bool operator < (edge a,edge b)
{
	return a.w<b.w;
}
int f[maxn];
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
void init()
{
	for(int i=0;i<maxn;i++) f[i]=i;
}
void ku()
{
	for(int i=0;i<m;i++)
	{
		int ex=find(a[i].u);int ey=find(a[i].v);
		if(ex!=ey)
		{
			f[ex]=ey;
			printf("%d %d\n",a[i].v,a[i].u);
		}
	}
}
signed main()
{
	//jiasu;
	scanf("%d",&n);
	init();
	m=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %lf",&g[i].x,&g[i].y);
		for(int j=1;j<i;j++)
		{
			double len=(g[i].x-g[j].x)*(g[i].x-g[j].x)+(g[i].y-g[j].y)*(g[i].y-g[j].y);			
			a[m].u=i;a[m].v=j;a[m++].w=len;
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		int ex=find(a);int ey=find(b);
		if(ex!=ey)
		 f[ex]=ey;
	}
	sort(a,a+m);
	ku();
    return 0;
}
