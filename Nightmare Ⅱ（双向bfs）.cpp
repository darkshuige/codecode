#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=850;
char g[maxn][maxn];
int vis[maxn][maxn];//1表示男人走过，2表示女人走过 
int n,m,tim;
int dx[]={-1,+0,+1,+0};
int dy[]={+0,+1,+0,-1};
pair<int,int>girl,man,goat[2];
int check(pair<int,int>u)
{
	int x=u.first,y=u.second;
	if(x<0 || x>=n || y<0 || y>=m)
	 return 0;
	if(g[x][y]=='X')
	 return 0;
	for(int i=0;i<2;i++)
	{
		if(abs(goat[i].first-x)+abs(goat[i].second-y)<=tim*2)
		 return 0;
	}
	return 1;
}
int bfs()
{
	memset(vis,0,sizeof vis);
	queue<pair<int,int> >qg,qm;
	vis[man.first][man.second]=1;
	vis[girl.first][girl.second]=2;
	qm.push(man),qg.push(girl);
	tim=0;
	while(!qm.empty() && !qg.empty())
	{
		tim++;
		for(int k=0;k<3;k++)//男的走三步 
		{
			for(int j=0,s=qm.size();j<s;j++)
			{
				auto u=qm.front();qm.pop();
				if(!check(u)) continue;
				for(int i=0;i<4;i++)
				{
					int x=u.first+dx[i],y=u.second+dy[i];
					if(!check({x,y})) continue;
					if(vis[x][y]==2)
					 return tim;
					else if(vis[x][y]==1)
					 continue;
					else vis[x][y]=1;
					qm.push({x,y});
				}
			}
		}
		for(int i=0;i<1;i++)
		{
			for(int j=0,s=qg.size();j<s;j++)
			{
				auto u=qg.front();qg.pop();
				if(!check(u)) continue;
				for(int i=0;i<4;i++)
				{
					int x=u.first+dx[i],y=u.second+dy[i];
					if(!check({x,y})) continue;
					if(vis[x][y]==1)
					 return tim;
					else if(vis[x][y]==2)
					 continue;
					else vis[x][y]=2;	
					qg.push({x,y});
				}
			}
		}
	}
	return -1;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		goat[1]={-1,-1};goat[0]={-1,-1};
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
			 	cin>>g[i][j];
			 	if(g[i][j]=='M')
			 	 man={i,j};
				if(g[i][j]=='G')
				 girl={i,j};
				if(g[i][j]=='Z')
				 if(goat[0].first==-1 && goat[0].second==-1)
				  goat[0]={i,j};
				 else
				  goat[1]={i,j};
			}	
		}
		cout<<bfs()<<endl;		
	}
	return 0;
}
