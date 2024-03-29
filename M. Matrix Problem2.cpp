#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=600;
char b[maxn][maxn];
char a[maxn][maxn];
int vis[maxn][maxn];
const double eps=1e-6;
set<pair<int,int> >st;
int ex[]={+0,-1,+1,+0,+0};
int ey[]={+0,+0,+0,-1,+1};
int n,m;
void bfs1(int i,int j)
{
	if(vis[i][j]==1) return ;
	queue<pair<int,int> >q;
	q.push({i,j});
	vis[i][j]=1;
	while(!q.empty())
	{
		int i=q.front().first,j=q.front().second; q.pop();
		for(int k=1;k<=4;k++)
		{
			int xx=ex[k]+i,yy=ey[k]+j;
			if(xx<1 || xx>n || yy<1 || yy>m) continue;
			if(b[xx][yy]=='1' && vis[xx][yy]==0)
			{
				q.push({xx,yy});
				vis[xx][yy]=1;
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
	 {
	 	cin>>b[i][j];
	 	a[i][j]=b[i][j];
	 }
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	 {
	 	if(b[i][j]=='0' && b[i+1][j]=='1' && b[i-1][j]=='1' && b[i][j+1]=='1' && b[i][j-1]=='1')
	 	 b[i][j]='1';
	 }
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	 {
	 	if(b[i][j]=='1' && vis[i][j]==0)
	 	 bfs1(i,j),st.insert({i,j});
	 }
	for(int i=1;i<=m;i++)
	 b[1][i]='1';
	for(auto k:st)
	{
		int x=k.first,y=k.second;
		for(int i=x;i>=1;i--)
		 b[i][y]='1';
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		 cout<<b[i][j];
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='1')
			 cout<<1;
			else
			 cout<<1-(b[i][j]-'0');
		}
		cout<<endl;
	}
	return 0;
}
