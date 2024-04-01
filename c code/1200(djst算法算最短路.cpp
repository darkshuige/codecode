#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
const int inf=0x3f3f3f3f;
bool used[maxn];
int cost[maxn][maxn];
int d[maxn];
int n,m;
void djst(int s)
{
	fill(d,d+n,inf);
	fill(used,used+n,0);
	for(int i=1;i<=n;i++)
	{
		d[i]=cost[s][i];
	}
	d[s]=0;
	while(true)
	{
		int v=-1;
		for(int u=1;u<=n;u++)
		{
			if(!used[u] && (v==-1 || d[u]<d[v]))
			 v=u;
		}
		if(v==-1)
		 break;
		used[v]=true;
		for(int u=1;u<=n;u++)
		{
			d[u]=min(d[u],d[v]+cost[v][u]);
		}
	}
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		memset(cost,inf,sizeof cost);
		cin>>n>>m;
		for(int j=0;j<m;j++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			cost[x][y]=min(cost[x][y],z);
			cost[y][x]=min(cost[y][x],z);
		}
		int s,e;
		cin>>s>>e;
		djst(s);
		if(d[e]!=inf)
		 cout<<d[e]<<endl;
		else
		 cout<<-1<<endl;
	}
	return 0;
} 
