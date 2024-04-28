#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ull unsigned long long
using namespace std;
const int maxn=1005;
deque<int>de;
char a[maxn][maxn];
int vis2[maxn][maxn];
int flag[maxn][maxn];
int n,m;
int ex[]={+0,-1,+0,+1,+0};
int ey[]={+0,+0,+1,+0,-1};
int bfs(int i,int j)
{
	map<pair<int,int>,int>mp;
	int res=1;
	vis2[i][j]=1;
	queue<pair<int,int> >q;
	q.push({i,j});
	while(!q.empty())
	{
		auto k=q.front(); q.pop();
		int x=k.first,y=k.second;
		for(int i=1;i<=4;i++)
		{
			int xx=x+ex[i],yy=y+ey[i];
			if(xx<1 || xx>n || yy<1 || yy>m) continue;
			if(a[xx][yy]!='.') continue;
			if(vis2[xx][yy]==1 && flag[xx][yy]==1 && mp[{xx,yy}]==0) res++,mp[{xx,yy}]++;
			if(vis2[xx][yy]==1) continue;
			vis2[xx][yy]=1;
			res++;
			if(flag[xx][yy]==1) continue;
			q.push({xx,yy});
		}
	}
	return res;
}
signed main()
{
	jiasu;
	cin>>n>>m;
	memset(flag,0,sizeof flag);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='#')
			 for(int k=1;k<=4;k++)
			 {
			 	flag[i+ex[k]][j+ey[k]]=1;
			 	vis2[i+ex[k]][j+ey[k]]=1;
			 }
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='.' && vis2[i][j]==0)
			 ans=max(ans,bfs(i,j));
		}
	}
	cout<<ans<<endl;
	return 0;
}
