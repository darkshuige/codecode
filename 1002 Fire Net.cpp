#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
int ex[]={0,-1,+0,+1,+0};
int ey[]={0,+0,+1,+0,-1};
const int maxn=10;
char a[maxn][maxn];
int vis[maxn][maxn];
int n,ans;
int check(int x,int y)
{
	for(int i=x;i>=0;i--)
	{
		if(a[i][y]=='X') break;
		if(vis[i][y]==1) return 0;
	}
	for(int i=x;i<n;i++)
	{
		if(a[i][y]=='X') break;
		if(vis[i][y]==1) return 0;
	}
	for(int i=y;i>=0;i--)
	{
		if(a[x][i]=='X') break;
		if(vis[x][i]==1) return 0;
	}
	for(int i=y;i<n;i++)
	{
		if(a[x][i]=='X') break;
		if(vis[x][i]==1) return 0;
	}
	return 1;
}
void dfs(int x,int y,int sum)
{
	ans=max(ans,sum);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int dx=i,dy=j;
			if(a[dx][dy]=='X' || vis[dx][dy]==1) continue;
			if(check(dx,dy)==0) continue;
			vis[dx][dy]=1;
			dfs(dx,dy,sum+1);
			vis[dx][dy]=0;	
		}
	}
}
signed main()
{
	while(cin>>n)
	{
		if(n==0)
		 break;
		for(int i=0;i<n;i++)
		 for(int j=0;j<n;j++)
		  cin>>a[i][j];
		ans=0;
		dfs(0,0,0);
		cout<<ans<<endl;
	}
	return 0;
} 
