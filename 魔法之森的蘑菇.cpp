#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2000;
map<pair<int,int>,int>mp;
char a[maxn][maxn];
int sx,sy,tx,ty;
int n,m;
int ex[]={+0,-1,+1,+0,+0};//上下左右
int ey[]={+0,+0,+0,-1,+1};//上下左右
struct node
{
	int x,y;
	int pos;
};
void bfs(int x,int y)
{
	queue<node>q;
	mp[{x,y}]=0;
	for(int i=1;i<=4;i++)
	{
		int xx=x+ex[i],yy=y+ey[i];
		if(xx>=1 && xx<=n && yy>=1 && yy<=m && a[xx][yy]!='#')
		{
			q.push({xx,yy,i});
			mp[{xx,yy}]=mp[{x,y}]+1;
		}
	}
	while(!q.empty())
	{
		int x=q.front().x,y=q.front().y,op=q.front().pos; q.pop();
		if(a[x][y]=='*')//四周
		{
			for(int i=1;i<=4;i++)
			{
				if(i==(op^1)) continue;
				int xx=x+ex[i],yy=y+ey[i];
				if(xx>=1 && xx<=n && yy>=1 && yy<=m && a[xx][yy]!='#' && !mp.count({xx,yy}))
				{
					q.push({xx,yy,i});
					mp[{xx,yy}]=mp[{x,y}]+1;
				}
			}
		}
		else if(a[x][y]=='.')
		{
			int xx=x+ex[op],yy=y+ey[op];
			if(xx>=1 && xx<=n && yy>=1 && yy<=m && a[xx][yy]!='#' && !mp.count({xx,yy}))
			{
				q.push({xx,yy,op});
				mp[{xx,yy}]=mp[{x,y}]+1;
			}
		}
	}
}
signed main() 
{
    jiasu;
    int t;
    cin>>t;
    while(t--)
    {
    	mp.clear();
    	cin>>n>>m;
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=1;j<=m;j++)
    		{
    			cin>>a[i][j];
    			if(a[i][j]=='S')
    			 sx=i,sy=j;
    			if(a[i][j]=='T')
    			 tx=i,ty=j;
			}
		}
		bfs(sx,sy);
		if(mp.count({tx,ty}))
		 cout<<mp[{tx,ty}]<<endl;
		else
		 cout<<-1<<endl;
	}
    return 0;
}
