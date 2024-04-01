#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=110;
char a[maxn][maxn];
bool vis[maxn][maxn];
int ex[]={-1,-1,-1,+0,+0,+0,+1,+1,+1};
int ey[]={-1,+0,+1,-1,+0,+1,-1,+0,+1};
int ans,n,m;
void bfs(int x,int y)
{
	vis[x][y]=1;
	queue<pair<int,int> >q;
	q.push({x,y});
	while(!q.empty())
	{
		pair<int,int>p=q.front();q.pop();
		int x=p.first,y=p.second;
		for(int i=0;i<9;i++)
		{
			int xx=x+ex[i],yy=y+ey[i];
			if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
			if(vis[xx][yy]) continue;
			if(a[xx][yy]!='@') continue;
			vis[xx][yy]=1;
			q.push({xx,yy});
		}
	}
}
signed main()
{
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
		 break;
		for(int i=0;i<n;i++)
		 for(int j=0;j<m;j++)
		  cin>>a[i][j];
		memset(vis,0,sizeof vis);
		ans=0;
		for(int i=0;i<n;i++)
		 for(int j=0;j<m;j++)
		 {
		 	if(vis[i][j]==0 && a[i][j]=='@')
		 	{
		 		bfs(i,j);
				ans++;	
			}
		 }
		cout<<ans<<endl;
	}
	return 0;
}
