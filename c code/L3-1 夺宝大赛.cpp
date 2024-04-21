#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200;
int d[maxn][maxn];
int vis[maxn][maxn];
int g[maxn][maxn];
int sx,sy;
int ex[]={+0,-1,+0,+1,+0};
int ey[]={+0,+0,+1,+0,-1};
int n,m;
struct node
{
	int xxx,yyy;
	int ddiiss,id;
}ans[maxn];
int cmp(node a,node b)
{
	return a.ddiiss<b.ddiiss;
}
void bfs(int x,int y)
{
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  d[i][j]=inf;
	memset(vis,0,sizeof vis);
	queue<pair<int,int> >q;
	d[x][y]=0; vis[x][y]=1;
	q.push({x,y});
	while(!q.empty())
	{
		auto k=q.front(); q.pop();
		int x=k.first,y=k.second;
		for(int i=1;i<=4;i++)
		{
			int xx=x+ex[i],yy=y+ey[i];
			if(xx<1 || xx>n || yy<1 || yy>m) continue;
			if(g[xx][yy]==0) continue;
			if(vis[xx][yy]==0)
			{
				vis[xx][yy]=1;
				d[xx][yy]=d[x][y]+1;
				q.push({xx,yy});
			}
		}
	}
}
map<int,int>mp;
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	 {
	 	cin>>g[i][j];
	 	if(g[i][j]==2)
	 	{
	 		sx=i,sy=j;
		}
	 }
	int q; cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>ans[i].xxx>>ans[i].yyy;
		ans[i].id=i;
	}
	bfs(sx,sy);
	
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		 {
//		 	cout<<d[i][j]<<" ";
//		 }
//		 cout<<endl;	
//	}
	 
	 
	 
	for(int i=1;i<=q;i++)
	{
		ans[i].ddiiss=d[ans[i].yyy][ans[i].xxx];
		mp[ans[i].ddiiss]++;
	}
	int pos=-1;
	sort(ans+1,ans+1+q,cmp);
	for(int i=1;i<=q;i++)
	{
		if(ans[i].ddiiss!=inf && mp[ans[i].ddiiss]==1)
		{
			pos=i;
			break;
		}
	}
	if(pos!=-1)
	 cout<<ans[pos].id<<" "<<ans[pos].ddiiss;
	else
	 cout<<"No winner."<<endl;
	return 0;
}