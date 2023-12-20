#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
using namespace std;
const int maxn=1005;
int d[maxn];
bool used[maxn];
int cost[maxn][maxn];
int n;
void djst(int x)
{
	memset(used,0,sizeof used);
	for(int i=1;i<=n;i++)
	 d[i]=inf;
	for(int i=1;i<=n;i++)
	 d[i]=cost[x][i];
	d[x]=0;
	while(1)
	{
		int v=-1;
		for(int i=1;i<=n;i++)
		{
			if(used[i]==0 && (v==-1 || d[i]<d[v]))
			 v=i;
		}
		if(v==-1)
		 break;
		used[v]=1;
		for(int i=1;i<=n;i++)
		 d[i]=min(d[i],d[v]+cost[v][i]);
	}
}
signed main()
{
	jiasu;
	int m;
	cin>>n>>m;
	memset(cost,inf,sizeof cost);
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		cost[x][y]=min(cost[x][y],z);
		cost[y][x]=min(cost[y][x],z);
	}
	djst(1);
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int x;
		cin>>x;
		cout<<d[x]<<endl;
	}
	return 0;	
} 
