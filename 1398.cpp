#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=300;
bool used[maxn];
int d[maxn];
int cost[maxn][maxn];
int n,m;
void djst(int s)
{
	memset(d,inf,sizeof d);
	fill(used,used+n,0);
	d[s]=0;
	while(true)
	{
		int v=-1;
		for(int u=0;u<n;u++)
		{
			if(used[u]==0 && (v==-1 || d[u]<d[v]))
			{
				v=u;
			}
		}
		if(v==-1)
		 break;
		used[v]=1;
		for(int u=0;u<n;u++)
		{
			d[u]=min(d[u],d[v]+cost[v][u]);
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		memset(cost,inf,sizeof cost);
		for(int i=0;i<m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			cost[x][y]=min(cost[x][y],z);
			cost[y][x]=min(cost[y][x],z);
		}
		int s,t;
		cin>>s>>t;
		djst(s);
		if(d[t]==inf)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<d[t]<<endl;
		}
	}
	return 0;	
} 
