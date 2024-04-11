#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
map<int,int>mp;
const int maxn=2000;
const double PI=3.141592;
char a[maxn][maxn];
char g[maxn][maxn];
int fla[maxn][maxn];
int ex[]={0,-1,-1,-1,+0,+0,+1,+1,+1};
int ey[]={0,-1,+0,+1,-1,+1,-1,+0,+1};
signed main()
{
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>a[i][j],g[i][j]=a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='G')
			{
				for(int k=1;k<=8;k++)
				{
					int xx=i+ex[k],yy=j+ey[k];
					if(!(xx>=1 && xx<=n && yy>=1 && yy<=m))
					 continue;
					if(a[xx][yy]=='H')
					{
						fla[i][j]=1;
						break;
					}
				}
				if(fla[i][j]==0)
				 g[i][j]='B';
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='M') continue;
			if(a[i][j]=='L')
			{
				int flag=1;
				for(int k=1;k<=8;k++)
				{
					int xx=i+ex[k],yy=j+ey[k];
					if(!(xx>=1 && xx<=n && yy>=1 && yy<=m && a[xx][yy]=='L'))
					{
						flag=0;
						break;
					}
				}
				if(flag)
				 g[i][j]='S';
				for(int k=1;k<=8;k++)
				{
					int xx=i+ex[k],yy=j+ey[k];
					if(xx>=1 && xx<=n && yy>=1 && yy<=m)
					{
						if(a[xx][yy]=='G' && fla[xx][yy]==0)
						{
							if(g[xx][yy]!='S')
							 g[xx][yy]='N';
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		 cout<<g[i][j];
		cout<<endl;
	}
	return 0;
} 	