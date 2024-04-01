#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn=3050;
char a[maxn][maxn];
int dist[maxn][maxn];
int ts[maxn][maxn];
int ox[]={-1,+0,+1,+0};
int oy[]={+0,+1,+0,-1};
int n,m;
void bfs(int x,int y)
{
	queue<pair<int,int> >q;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  dist[i][j]=INT_MAX;
	q.push({x,y});
	dist[1][1]=0;
	while(!q.empty())
	{
		auto t=q.front();
		q.pop();
		int sx=t.first,sy=t.second;
		if(a[sx][sy]=='*')
		{
			int w=ts[sx][sy];
			for(int i=0;i<4;i++)
			{
				int xx=sx+ox[i]*w,yy=sy+oy[i]*w;
				if(xx<1 || xx>n || yy<1 || yy>m || a[xx][yy]=='#')
				 continue;
				else
				{
					if(dist[xx][yy]>dist[sx][sy])
					{
						dist[xx][yy]=dist[sx][sy];
						q.push({xx,yy});
					}
					 
				}
			}
		}
		else if(a[sx][sy]=='.')
		{
			for(int i=0;i<4;i++)
			{
				int xx=sx+ox[i],yy=sy+oy[i];
				if(xx<1 || xx>n || yy<1 || yy>m || a[xx][yy]=='#')
				 continue;
				else
				{
					if(dist[xx][yy]>dist[sx][sy]+1)
					{
						dist[xx][yy]=dist[sx][sy]+1;
						q.push({xx,yy});
					}
				}
			}	
		}
	}
}
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>a[i][j];
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		ts[x][y]=w;
	}
	bfs(1,1);
	if(dist[n][m]==INT_MAX)
	 cout<<-1<<endl;
	else
	 cout<<dist[n][m]<<endl;
	return 0;
} 
