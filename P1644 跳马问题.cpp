#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20;
int mp[maxn][maxn]={0};
int n,m,ans;
int dx[]={-2,-1,+1,+2};
int dy[]={+1,+2,+2,+1};
void dfs(int x,int y)
{
	if(x==n && y==m)
	{
		ans++;
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int a=x+dx[i],b=y+dy[i];
		if(a<0 || a>n || b<0 || b>m)
		 continue;
		dfs(a,b);
	}
}
signed main()
{
	cin>>n>>m;
	ans=0;
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
