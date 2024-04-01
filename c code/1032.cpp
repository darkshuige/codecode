#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
int h,w,sum,op,sx,sy,ex,ey;
char a[50][50];
int sum1,sum2,sum3;
int xx[5]={0,-1,+0,+1,+0};
int yy[5]={0,+0,+1,+0,-1};//1,2,3,4
int check(int x,int y)
{
	if(x<1 || x>h || y<1 || y>w || a[x][y]=='#')
	 return 0;
	else
	 return 1;	
}
void dfs1(int x,int y,int op)
{
	if(x==ex && y==ey)
	 return ;
	sum1++;
	if(op==1)
	{
		if(check(x+xx[4],y+yy[4])) dfs1(x+xx[4],y+yy[4],4);
		else if(check(x+xx[1],y+yy[1])) dfs1(x+xx[1],y+yy[1],1);
		else if(check(x+xx[2],y+yy[2])) dfs1(x+xx[2],y+yy[2],2);
		else if(check(x+xx[3],y+yy[3])) dfs1(x+xx[3],y+yy[3],3);
	}
	else if(op==2)
	{
		if(check(x+xx[1],y+yy[1])) dfs1(x+xx[1],y+yy[1],1);
		else if(check(x+xx[2],y+yy[2])) dfs1(x+xx[2],y+yy[2],2);
		else if(check(x+xx[3],y+yy[3])) dfs1(x+xx[3],y+yy[3],3);
		else if(check(x+xx[4],y+yy[4])) dfs1(x+xx[4],y+yy[4],4);
	}
	else if(op==3)
	{
		if(check(x+xx[2],y+yy[2])) dfs1(x+xx[2],y+yy[2],2);
		else if(check(x+xx[3],y+yy[3])) dfs1(x+xx[3],y+yy[3],3);
		else if(check(x+xx[4],y+yy[4])) dfs1(x+xx[4],y+yy[4],4);
		else if(check(x+xx[1],y+yy[1])) dfs1(x+xx[1],y+yy[1],1);
	}
	else if(op==4)
	{
		if(check(x+xx[3],y+yy[3])) dfs1(x+xx[3],y+yy[3],3);
		else if(check(x+xx[4],y+yy[4])) dfs1(x+xx[4],y+yy[4],4);
		else if(check(x+xx[1],y+yy[1])) dfs1(x+xx[1],y+yy[1],1);
		else if(check(x+xx[2],y+yy[2])) dfs1(x+xx[2],y+yy[2],2);
	}
}
void dfs2(int x,int y,int op)
{
	if(x==ex && y==ey)
	 return ;
	sum2++;
	if(op==1)
	{
		if(check(x+xx[2],y+yy[2])) dfs2(x+xx[2],y+yy[2],2);
		else if(check(x+xx[1],y+yy[1])) dfs2(x+xx[1],y+yy[1],1);
		else if(check(x+xx[4],y+yy[4])) dfs2(x+xx[4],y+yy[4],4);
		else if(check(x+xx[3],y+yy[3])) dfs2(x+xx[3],y+yy[3],3);
	}
	else if(op==2)
	{
		if(check(x+xx[3],y+yy[3])) dfs2(x+xx[3],y+yy[3],3);
		else if(check(x+xx[2],y+yy[2])) dfs2(x+xx[2],y+yy[2],2);
		else if(check(x+xx[1],y+yy[1])) dfs2(x+xx[1],y+yy[1],1);
		else if(check(x+xx[4],y+yy[4])) dfs2(x+xx[4],y+yy[4],4);
	}
	else if(op==3)
	{
		if(check(x+xx[4],y+yy[4])) dfs2(x+xx[4],y+yy[4],4);
		else if(check(x+xx[3],y+yy[3])) dfs2(x+xx[3],y+yy[3],3);
		else if(check(x+xx[2],y+yy[2])) dfs2(x+xx[2],y+yy[2],2);
		else if(check(x+xx[1],y+yy[1])) dfs2(x+xx[1],y+yy[1],1);
	}
	else if(op==4)
	{
		if(check(x+xx[1],y+yy[1])) dfs2(x+xx[1],y+yy[1],1);
		else if(check(x+xx[4],y+yy[4])) dfs2(x+xx[4],y+yy[4],4);
		else if(check(x+xx[3],y+yy[3])) dfs2(x+xx[3],y+yy[3],3);
		else if(check(x+xx[2],y+yy[2])) dfs2(x+xx[2],y+yy[2],2);
	}
}
void bfs3(int x,int y)
{
	int d[50][50]={0};
	int vis[50][50]={0};
	vis[x][y]=1;
	d[x][y]=1;
	queue<pair<int,int> >q;
	q.push({x,y});
	while(!q.empty())
	{
		pair<int,int>op=q.front();
		q.pop();
		x=op.first,y=op.second;
		for(int i=1;i<=4;i++)
		{
			int nx=x+xx[i],ny=y+yy[i];
			if(check(nx,ny) && vis[nx][ny]==0)
			{
				vis[nx][ny]=1;
				d[nx][ny]=d[x][y]+1;
				q.push({nx,ny});
			}
		}
	}
	sum3=d[ex][ey];
}
signed main()
{
	int n;
	cin>>n;
	while(n--)
	{
		cin>>w>>h;
		for(int i=1;i<=h;i++)
		 for(int j=1;j<=w;j++)
		 {
		 	cin>>a[i][j];
		 	if(a[i][j]=='S')
		 	{
		 		sx=i;
		 		sy=j;
			}
			else if(a[i][j]=='E')
			{
				ex=i;
				ey=j;
			}
		 }
		int op;
		sum1=1,sum2=1,sum3=1;
		if(check(sx-1,sy)) op=1;
		else if(check(sx,sy+1)) op=2;
		else if(check(sx+1,sy)) op=3;
		else op=4;
		dfs1(sx,sy,op);
		dfs2(sx,sy,op);
		bfs3(sx,sy);
		cout<<sum1<<" "<<sum2<<" "<<sum3<<endl;
	}
	return 0;
}
