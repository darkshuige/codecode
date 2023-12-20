#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=35;
char a[maxn][maxn][maxn];
int l,c,r;
int st1,st2,st3;
int ed1,ed2,ed3;
int ex[]={0,-1,+0,+1,+0};
int ey[]={0,+0,+1,+0,-1};
bool vis[maxn][maxn][maxn];
int d[maxn][maxn][maxn];
struct node
{
	int x,y,z;
};
void bfs(node u)
{
	queue<node>q;
	memset(d,inf,sizeof d);
	int x=u.x,y=u.y,z=u.z;
	d[x][y][z]=0;
	memset(vis,0,sizeof vis);
	vis[st1][st2][st3]=1;
	q.push(u);
	while(!q.empty())
	{
		node u=q.front();
		q.pop();
		int x=u.x,y=u.y,z=u.z;
		for(int i=1;i<=4;i++)
		{
			int xx=x+ex[i],yy=y+ey[i];
			if(xx<0 || xx>=c || yy<0 || yy>=r) continue;
			if(vis[xx][yy][z] || a[xx][yy][z]=='#') continue;
			d[xx][yy][z]=d[x][y][z]+1;
			vis[xx][yy][z]=1;
			q.push({xx,yy,z});
		}
		int zz=z-1;
		if(!(zz<0 || zz>=l))
		{
			if(!(vis[x][y][zz] || a[x][y][zz]=='#'))
			{
				d[x][y][zz]=d[x][y][z]+1;
				vis[x][y][zz]=1;
				q.push({x,y,zz});
			}
		}
		zz=z+1;
		if(!(zz<0 || zz>=l))
		{
			if(!(vis[x][y][zz] || a[x][y][zz]=='#'))
			{
				d[x][y][zz]=d[x][y][z]+1;
				vis[x][y][zz]=1;
				q.push({x,y,zz});
			}
		}	
	}
}
signed main()
{
	while(cin>>l>>c>>r)
	{
		if(l==0 && c==0 && r==0) break;
		for(int k=0;k<l;k++)
		{
			for(int i=0;i<c;i++)
			{
				for(int j=0;j<r;j++)
				{
					cin>>a[i][j][k];
					if(a[i][j][k]=='S')
					 st1=i,st2=j,st3=k;
					if(a[i][j][k]=='E')
					 ed1=i,ed2=j,ed3=k;
				}
			}
		}
		bfs({st1,st2,st3});
		if(d[ed1][ed2][ed3]!=inf)
		 cout<<"Escaped in "<<d[ed1][ed2][ed3]<<" minute(s)."<<endl;
		else
		 cout<<"Trapped!"<<endl;
	}
	return 0;
} 
