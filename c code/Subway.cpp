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
const int maxn=220;
int n,m;
struct node
{
	double x,y;
}a[maxn];
double mp[maxn][maxn];
double d[maxn];
int vis[maxn];
double l(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void djst(int s)
{
	memset(vis,0,sizeof vis);
	for(int i=1;i<maxn;i++)
	{
		d[i]=mp[1][i];
	}
	vis[1]=1;d[1]=0;
	while(1)
	{
		int v=-1;
		double m=1e18;
		for(int i=1;i<=n;i++)
		{
			if(d[i]<m && vis[i]==0)
			{
				v=i;
				m=d[i];
			}
		}
		if(v==-1) break;
		vis[v]=1;
		for(int u=1;u<=n;u++)
		{
			if(d[u]>d[v]+mp[v][u])
			 d[u]=d[v]+mp[v][u];
		}
	}
}
void init()
{
	for(int i=0;i<maxn;i++)
	 for(int j=0;j<maxn;j++)
	  mp[i][j]=mp[j][i]=1e18;
}
signed main()
{
	jiasu;
	init();
	double x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x3>>y3;
	n=2;
	while(cin>>a[n].x>>a[n].y)
	{
		n++;
		while(cin>>x2>>y2)
		{
			if(x2==-1 && y2==-1) break;
			a[n].x=x2;a[n].y=y2;
			mp[n][n-1]=mp[n-1][n]=l(a[n].x,a[n].y,a[n-1].x,a[n-1].y)/1000/40;
			n++;
		}	
	}
	a[n].x=x3;a[n].y=y3;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			mp[i][j]=min(mp[i][j],l(a[i].x,a[i].y,a[j].x,a[j].y)/1000/10);
			mp[j][i]=mp[i][j];
		}
	}
	djst(1);
	cout<<(int)(d[n]*60+0.5)<<endl;
	return 0;
}
