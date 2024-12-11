#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=205;
int n,m,l,t;
int g[1286][128][60];
int cnt=0;
int ex[6]={0,+0,+1,-1,+0,+0};
int ey[6]={0,+0,+0,+0,+1,-1};
int ez[6]={1,-1,+0,+0,+0,+0};
void dfs(int x,int y,int z)
{
	cnt++;
	g[x][y][z]=0;
	for(int i=0;i<6;i++)
	{
		int xx=x+ex[i],yy=y+ey[i],zz=z+ez[i];
		if(xx<0 || xx>=m || yy<0 || yy>=n || zz<0 || zz>=l) continue;
		if(g[xx][yy][zz])
		 dfs(xx,yy,zz);
	}
}
signed main()
{
	jiasu;
	cin>>m>>n>>l>>t;
	for(int z=0;z<l;z++)
	 for(int x=0;x<m;x++)
	  for(int y=0;y<n;y++)
	   cin>>g[x][y][z];
	int sum=0;
	for(int i=0;i<m;i++)
	 for(int j=0;j<n;j++)
	  for(int z=0;z<l;z++)
	   {
	   		cnt=0;
	   		if(g[i][j][z]) dfs(i,j,z);
	   		sum+=cnt<t?0:cnt;
	   }
	cout<<sum<<endl;
	return 0;
}