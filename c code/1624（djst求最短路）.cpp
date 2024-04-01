#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1005; 
int cost[maxn][maxn],d[maxn];
bool used[maxn];
int n,m;
void djst(int s)
{
	fill(d,d+n,inf);
	memset(used,0,sizeof used);
	for(int i=1;i<=n;i++)
	{
		d[i]=cost[s][i];
	}
	d[s]=0;
	while(true)
	{
		int v=-1;
		for(int i=1;i<=n;i++)
		{
			if(!used[i] && (v==-1 || d[i]<d[v]))
			{
				v=i;
			}
		}
		if(v==-1)
		 break;
		used[v]=1;
		for(int i=1;i<=n;i++)
		{
			d[i]=min(d[i],d[v]+cost[v][i]);
		}
	}
}
int main()
{
	int t;
	cin>>t;
	for(int l=0;l<t;l++)
	{
		cin>>n>>m;
		memset(cost,inf,sizeof cost);
		for(int i=0;i<m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			cost[x][y]=min(cost[x][y],z);
			cost[y][x]=min(cost[y][x],z);	
		} 
		int s,e;
		cin>>s>>e;
		djst(s);
		if(d[e]==inf)
		 cout<<-1<<endl;
		else
		 cout<<d[e]<<endl;
	}
	return 0;
}
