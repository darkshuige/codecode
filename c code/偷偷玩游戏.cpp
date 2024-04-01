#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f 
using namespace std;
const int maxn=3005;
int ox[]={-1,+0,+0,+1};
int oy[]={-0,+1,-1,+0};
bool vis[maxn][maxn];
int d1[maxn][maxn];
int d2[maxn][maxn];
int a[maxn][maxn];
int n,m,kk,sx,sy,ex,ey;
struct node
{
	int x,y,d;
}op[maxn];
int k=0;
void bfs1(int x,int y)
{
	memset(d1,INF,sizeof d1);
	memset(vis,0,sizeof vis);
	queue<pair<int,int> >q;
	pair<int,int>p;
	p={x,y};
	vis[x][y]=1;
	d1[x][y]=0;
	q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=p.first+ox[i],yy=p.second+oy[i];
			if(xx<1 || xx>n || yy<1 || yy>m || a[xx][yy]==-1 || vis[xx][yy]==1)
			 continue;
			if(d1[xx][yy]>d1[p.first][p.second]+1)
			{
				q.push({xx,yy});
				d1[xx][yy]=d1[p.first][p.second]+1;
				vis[xx][yy]=1;	
			}
			
		}
	}
}
void bfs2(int x,int y)
{
	memset(d2,INF,sizeof d2);
	memset(vis,0,sizeof vis);
	queue<pair<int,int> >q;
	pair<int,int>p;
	p={x,y};
	vis[x][y]=1;
	d2[x][y]=0;
	q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=p.first+ox[i],yy=p.second+oy[i];
			if(xx<1 || xx>n || yy<1 || yy>m || a[xx][yy]==-1 || vis[xx][yy]==1)
			 continue;
			if(d2[xx][yy]>d2[p.first][p.second]+1)
			{
				q.push({xx,yy});
				d2[xx][yy]=d2[p.first][p.second]+1;
				vis[xx][yy]=1;	
			}
			
		}
	}
}
signed main()
{
	jiasu;
	cin>>n>>m>>kk>>sx>>sy>>ex>>ey;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>a[i][j];
	bfs1(sx,sy);
	bfs2(ex,ey);
	int minn=INF;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  if(a[i][j]>kk && d1[i][j]!=INF && d2[i][j]!=INF)
	   minn=min(minn,d1[i][j]+d2[i][j]);
	if(minn==INF)
	 cout<<-1<<endl;
	else
	 cout<<minn<<endl;
	return 0;
}
