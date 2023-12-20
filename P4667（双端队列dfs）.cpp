#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=550;
char g[maxn][maxn];
int d[maxn][maxn],vis[maxn][maxn],n,m;
char rr[]="\\/\\/";
int dx[]={-1,-1,+1,+1};
int dy[]={-1,+1,+1,-1};
int ex[]={-1,-1,+0,+0};
int ey[]={-1,+0,+0,-1};
void bfs(int x,int y)
{
	memset(d,inf,sizeof d);
	memset(vis,0,sizeof vis);
	deque<pair<int,int> >q;
	q.push_front({x,y});
	d[0][0]=0;
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;
		q.pop_front();
		if(vis[x][y]) continue;
		vis[x][y]=1;
		for(int i=0;i<4;i++)
		{
			int a=x+dx[i],b=y+dy[i];
			if(a<0 || a>n || b<0 || b>m) continue;
			int dis=d[x][y]+(rr[i]!=g[x+ex[i]][y+ey[i]]);
			if(dis<d[a][b])
			{
				d[a][b]=dis;
				if(rr[i]==g[x+ex[i]][y+ey[i]])
				 q.push_front({a,b});
				else
				 q.push_back({a,b});
			}
		}
	}
}
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++)
	  cin>>g[i][j];
	bfs(0,0);
	if(d[n][m]!=inf)
	 cout<<d[n][m];
	else 
	 cout<<"NO SOLUTION"<<endl;
	return 0;
}
