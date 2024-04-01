#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=220;
char a[maxn][maxn];
int ex[]={-1,+0,+1,+0};
int ey[]={+0,+1,+0,-1};
int n,m;
int x1,x2,y1,y2;
int d1[maxn][maxn],d2[maxn][maxn];
int ans;
int flag;
bool vis1[maxn][maxn],vis2[maxn][maxn];
void bfs()
{
	memset(vis1,0,sizeof vis1);
	memset(vis2,0,sizeof vis2);
	memset(d1,inf,sizeof d1);
	memset(d2,inf,sizeof d2);
	queue<pair<int,int> >q1,q2;
	vis1[x1][y1]=1;vis2[x2][y2]=1;
	d1[x1][y1]=0;d2[x2][y2]=0;
	q1.push({x1,y1}),q2.push({x2,y2});
	while((!q1.empty() || !q2.empty()))
	{
		for(int i=0,s=q1.size();i<s;i++)
		{
			pair<int,int>p=q1.front();q1.pop();
			int x=p.first,y=p.second;
			for(int i=0;i<4;i++)
			{
				int xx=x+ex[i],yy=y+ey[i];
				if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
				if(vis1[xx][yy]==1 || a[xx][yy]=='#') continue;
				vis1[xx][yy]=1;
				d1[xx][yy]=d1[x][y]+1;
				q1.push({xx,yy});
			}
		}
		for(int i=0,s=q2.size();i<s;i++)
		{
			pair<int,int>p=q2.front();q2.pop();
			int x=p.first,y=p.second;
			for(int i=0;i<4;i++)
			{
				int xx=x+ex[i],yy=y+ey[i];
				if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
				if(vis2[xx][yy]==1 || a[xx][yy]=='#') continue;
				vis2[xx][yy]=1;
				d2[xx][yy]=d2[x][y]+1;
				q2.push({xx,yy});
			}
		}
	}
}
signed main()
{
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		 for(int j=0;j<m;j++)
		 {
		 	cin>>a[i][j];
		 	if(a[i][j]=='Y')
		 	 x1=i,y1=j;
		 	else if(a[i][j]=='M')
		 	 x2=i,y2=j;
		 }
		flag=0;
		bfs();
		ans=inf;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]=='@')
				{
					ans=min(ans,d1[i][j]+d2[i][j]);
				}
			}
		}
		cout<<ans*11<<endl;
	}
	return 0;
}
