#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[110][110];
bool vis[110][110];
int res;
int maxn=0;
int nx[]={-1,0,0,1};
int ny[]={0,-1,1,0};
pair<int,int>p;
void bfs(pair<int,int>op)
{
	queue<pair<int,int> >que;
	que.push(pair<int,int>(op.first,op.second));
	res++;
	if(res>maxn)
	 maxn=res;
	vis[op.first][op.second]=1;
	while(que.size())
	{
		p=que.front();que.pop();
		for(int i=0;i<=3;i++)
		{
			int sx=p.first+nx[i],sy=p.second+ny[i];
			if(sx>0 && sx<=n && sy>0 && sy<=m && vis[sx][sy]==0 && a[sx][sy]==1)
			{
				que.push(pair<int,int>(sx,sy));
				vis[sx][sy]=1;
				res++;
				if(res>maxn)
				 maxn=res;
			}
		}
	}
}
int main()
{
	while(cin>>n>>m>>k)
	{
		maxn=0; 
		res=0;
		memset(a,0,sizeof a);
		memset(vis,0,sizeof vis);
		int i;
		for(i=0;i<k;i++)
		{
			int x,y;
			cin>>x>>y;
			a[x][y]=1;
		}
		for(i=1;i<=n;i++)
		{
			int j;
			for(j=1;j<=m;j++)
			{
				if(vis[i][j]==0 && a[i][j]==1)
				{
					bfs(pair<int,int>(i,j));
					res=0;
				}
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}

