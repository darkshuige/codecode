#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000;
const int mod=998244353;
char a[maxn][maxn];
int vis[maxn][maxn];
int ex[]={-1,-1,-1,0,0,0,1,1,1};
int ey[]={-1,0,1,-1,0,1,-1,0,1};
int n,m;
void dfs(int x,int y)
{
	for(int i=0;i<9;i++)
	{
		int xx=x+ex[i],yy=y+ey[i];
		if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
		if(vis[xx][yy]==1 || a[xx][yy]!='#') continue;
		vis[xx][yy]=1;
		dfs(xx,yy);
	}
}
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='#' && vis[i][j]==0)
			{
				sum++;
				vis[i][j]=1;
				dfs(i,j);
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
