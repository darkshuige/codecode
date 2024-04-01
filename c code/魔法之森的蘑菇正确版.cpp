#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//long long 开了会超时 
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1005;
char a[maxn][maxn];
int sx,sy,tx,ty;
int n,m;
int ex[]={+0,-1,+1,+0,+0};
int ey[]={+0,+0,+0,-1,+1};
struct node
{
	int x,y;
	int pos,s;//s是距离 
};
int mp[maxn][maxn][5];//同时记录四个方向 
void bfs(int x,int y)
{
	queue<node>q;
	memset(mp,0,sizeof mp);
	for(int i=1;i<=4;i++) q.push({x,y,i});
	while(!q.empty())
	{
		int x=q.front().x,y=q.front().y,op=q.front().pos,s=q.front().s; q.pop();
		if(x==tx&&y==ty)
		{
			cout<<s<<"\n";
			return;
		}
		if(a[x][y]=='*')
		{
			for(int i=1;i<=4;i++)
			{
				int xx=x+ex[i],yy=y+ey[i];
				if((i==1&&op==2)||(i==2&&op==1)||(i==3&&op==4)||(i==4&&op==3)) continue;//不能掉头 
				if(xx>=1 && xx<=n && yy>=1 && yy<=m && a[xx][yy]!='#' && !mp[xx][yy][i])
				{
					mp[xx][yy][i]=mp[x][y][op]+1;
					q.push({xx,yy,i,mp[xx][yy][i]});
				}
			}
		}
		else if(a[x][y]=='.'||a[x][y]=='S')
		{
			int xx=x+ex[op],yy=y+ey[op];
			if(xx>=1 && xx<=n && yy>=1 && yy<=m && a[xx][yy]!='#' && !mp[xx][yy][op])
			{
				mp[xx][yy][op]=mp[x][y][op]+1;
				q.push({xx,yy,op,mp[xx][yy][op]});
			}
		}
	}
	cout<<"-1\n";
}
signed main() 
{
    jiasu;
    int t;
    cin>>t;
    while(t--)
    {
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
	}
    return 0;
}
