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
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=600;
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
int n,m,cnt,s;
double ans;
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
void ku()
{
	cnt=0;
	ans=0;
	for(int i=0;i<m;i++)
	{
		int ex=find(a[i].u);int ey=find(a[i].v);
		if(ex!=ey)
		{
			f[ex]=ey;
			ans=max(ans,a[i].w);
			cnt++;
			if(cnt>=n-s) break;
		}
	}
}
void init()
{
	for(int i=0;i<maxn;i++) f[i]=i;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s>>n;
		init();
		m=0;
		for(int i=1;i<=n;i++)
		{
			cin>>g[i].x>>g[i].y;
			for(int j=1;j<i;j++)
			{
				double len=sqrt((g[i].x-g[j].x)*(g[i].x-g[j].x)+(g[i].y-g[j].y)*(g[i].y-g[j].y));
				a[m].u=i;a[m].v=j;a[m++].w=len;	
			}
		}
		sort(a,a+m);
		ku();
		cout<<fixed<<setprecision(2)<<ans<<endl;	
	}
    return 0;
}
