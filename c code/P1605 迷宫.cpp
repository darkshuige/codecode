#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=10;
int mp[maxn][maxn]={0};
int n,m,sx,sy,ex,ey,ans;
int dx[]={-1,+0,+1,+0};
int dy[]={+0,+1,+0,-1};
void dfs(int x,int y)
{
	if(x==ex && y==ey)
	{
		ans++;
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int a=x+dx[i],b=y+dy[i];
		if(a<1 || a>n || b<1 || b>m)
		 continue;
		if(mp[a][b]==1)
		 continue;
		mp[a][b]=1;
		dfs(a,b);
		mp[a][b]=0;
	}
}
signed main()
{
	int t;
	cin>>n>>m>>t;
	cin>>sx>>sy>>ex>>ey;
	mp[sx][sy]=1;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		mp[x][y]=1;
	}
	ans=0;
	dfs(sx,sy);
	cout<<ans<<endl;
	return 0;
}
