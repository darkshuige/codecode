#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=3000;
int f[maxn][maxn],a[maxn][maxn];
int ex[]={-1,+0,+1,+0};
int ey[]={+0,+1,+0,-1};
int n,k;
int dfs(int x,int y)
{
	f[x][y]=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<4;j++)
		{
			int xx=x+ex[j]*i,yy=y+ey[j]*i;
			if(xx<1 || yy<1 || xx>n || yy>n) continue;
			if(a[x][y]>=a[xx][yy]) continue;
			if(f[xx][yy]) f[x][y]=max(f[x][y],f[xx][yy]);//如果搜索过就直接停下
			else f[x][y]=max(f[x][y],dfs(xx,yy));
		}	
	}
	f[x][y]+=a[x][y];
	return f[x][y];
}
signed main()
{
	jiasu;
	while(cin>>n>>k)
	{
		if(n==-1 && k==-1) break;
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=n;j++)
		  cin>>a[i][j],f[i][j]=0;
		cout<<dfs(1,1)<<endl;
	}
	return 0;
}