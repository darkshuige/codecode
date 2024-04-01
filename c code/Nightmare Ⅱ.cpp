#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=805;
char g[maxn][maxn];
bool vis1[maxn][maxn],vis2[maxn][maxn];
int n,m,cnt;
queue<pair<int,int> >q1,q2;
vector<pair<int,int> >v;
int ex[]={-1,+0,+1,+0};
int ey[]={+0,+1,+0,-1};
int mx,my;
int check(int x,int y)
{
	for(auto node:v)
	{
		if(cnt*2>=abs(x-node.first)+abs(y-node.second))
		 return 0;
	}
	return 1;
}
int bfs()
{
	cnt=0;
	while(!q1.empty() || !q2.empty())
	{
		cnt++;
		for(int j=0;j<3;j++)
		{
			for(int i=0,s=q1.size();i<s;i++)
			{
				auto node=q1.front();q1.pop();
				int x=node.first,y=node.second;
				if(check(x,y)==0) continue;
				for(int i=0;i<4;i++)
				{
					int xx=x+ex[i],yy=y+ey[i];
					if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
					if(vis1[xx][yy]==1 || g[xx][yy]=='X' || check(xx,yy)==0) continue;
					if(vis2[xx][yy]==1) return cnt;
					vis1[xx][yy]=1;
					q1.push({xx,yy});
				}
			}	
		}
		for(int i=0,s=q2.size();i<s;i++)
		{
			auto node=q2.front();q2.pop();
			int x=node.first,y=node.second;
			if(check(x,y)==0) continue;
			for(int i=0;i<4;i++)
			{
				int xx=x+ex[i],yy=y+ey[i];
				if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
				if(vis2[xx][yy]==1 || g[xx][yy]=='X' || check(xx,yy)==0) continue;
				if(vis1[xx][yy]==1) return cnt;
				vis2[xx][yy]=1;
				q2.push({xx,yy});
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
		v.clear();
		memset(vis1,0,sizeof vis1);
		memset(vis2,0,sizeof vis2);
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>g[i][j];
				if(g[i][j]=='M')
				 q1.push({i,j}),vis1[i][j]=1;
				else if(g[i][j]=='G')
				 q2.push({i,j}),vis2[i][j]=1;
				else if(g[i][j]=='Z')
				 v.push_back({i,j});
			}
		}
		cout<<bfs()<<endl;
	}
	return 0;
}
