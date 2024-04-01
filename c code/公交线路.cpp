#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1005;
int d[maxn];
int a[maxn][maxn];
int used[maxn];
int n,m;
void djst(int s)
{
	memset(d,inf,sizeof d);
	memset(used,0,sizeof used);
	for(int i=1;i<=n;i++)
	{
		d[i]=a[s][i];
	}
	d[s]=0;
	while(1)
	{
		int v=-1;
		for(int i=1;i<=n;i++)
		{
			if(!used[i] && (v==-1 || d[i]<d[v]))
			 v=i;
		}
		if(v==-1)
		 break;
		used[v]=1;
		for(int i=1;i<=n;i++)
		{
			d[i]=min(d[i],d[v]+a[v][i]);
		}
	}
}
signed main()
{
	jiasu;
	int s,t;
	cin>>n>>m>>s>>t;
	memset(a,inf,sizeof a);
	for(int i=0;i<m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		a[x][y]=min(a[x][y],w);
		a[y][x]=min(a[y][x],w);
	}
	djst(s);
	if(d[t]==inf)
	 cout<<-1<<endl;
	else
	 cout<<d[t]<<endl;
	return 0;
} 
