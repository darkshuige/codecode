#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
struct edge
{
	int u,v;
	double w;
}a[maxn];
struct node
{
	double x,y;
}g[maxn];
int n,m,flag;
double ans;
int cmp(edge a,edge b)
{
	return a.w<b.w;
}
int f[maxn];
int find(int x)
{
	if(x==f[x])
	 return x;
	else
	 return f[x]=find(f[x]);
}
int ku()
{
	for(int i=0;i<maxn;i++) f[i]=i;
	int cnt=0;
	ans=0;
	for(int i=0;i<m;i++)
	{
		int ex=find(a[i].u);int ey=find(a[i].v);
		if(ex!=ey)
		{
			f[ex]=ey;
			ans+=a[i].w;
			cnt++;
		}
	}
	return cnt==n-1;
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		flag=1;
		cin>>n;
		m=0;
		for(int i=1;i<=n;i++) cin>>g[i].x>>g[i].y;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				double len=(g[i].x-g[j].x)*(g[i].x-g[j].x)+(g[i].y-g[j].y)*(g[i].y-g[j].y);
				if(len<100 || len>1000000) continue;
				a[m].u=i,a[m].v=j;a[m++].w=sqrt(len);
			}
		}
		sort(a,a+m,cmp);
		if(ku()) cout<<fixed<<setprecision(1)<<ans*100<<endl; else cout<<"oh!"<<endl;
	}
	return 0;
}
