#include<bits/stdc++.h>
#define jiasu ios::sync_wiht_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=205;
int f1[maxn][maxn],f2[maxn][maxn],ans;//f1表示是否访问，f2表示是否作为出发点访问
char a[maxn][maxn];
void dfs(int x,int y,int op)//1上 2下 3左 4右 
{
	if(f1[x][y]==0)
	{
		ans++;
		f1[x][y]=1;
	}
	if(op==0)
	{
		if(f2[x][y]==0)
		{
			f2[x][y]=1;
			if(a[x-1][y]=='.') dfs(x-1,y,1);
			if(a[x+1][y]=='.') dfs(x+1,y,2);
			if(a[x][y-1]=='.') dfs(x,y-1,3);
			if(a[x][y+1]=='.') dfs(x,y+1,4);
			return ;
		}
	}
	else if(op==1)
	{
		if(a[x-1][y]=='.')
		 dfs(x-1,y,1);
		else
		 dfs(x,y,0);
	}
	else if(op==2)
	{
		if(a[x+1][y]=='.')
		 dfs(x+1,y,2);
		else
		 dfs(x,y,0);
	}
	else if(op==3)
	{
		if(a[x][y-1]=='.')
		 dfs(x,y-1,3);
		else
		 dfs(x,y,0);
	}
	else if(op==4)
	{
		if(a[x][y+1]=='.')
		 dfs(x,y+1,4);
		else
		 dfs(x,y,0);
	}
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  cin>>a[i][j];
	memset(f1,0,sizeof f1);
	memset(f2,0,sizeof f2);
	ans=0;
	dfs(2,2,0);
	cout<<ans<<endl;
	return 0;
} 
