#include<bits/stdc++.h>
using namespace std;
char mp[10000][10000]={0};
bool vis[10005][10005]={0};
int ld=0,bz=0;
int flag=0;
void dfs(int x,int y,int n,int m)
{
	vis[x][y]=1;
	if(mp[x][y]!='1')
	 flag=1;
	if(x+1<n && mp[x+1][y]!='0' && vis[x+1][y]==0) dfs(x+1,y,n,m);
	if(x-1>=0 && mp[x-1][y]!='0' && vis[x-1][y]==0) dfs(x-1,y,n,m);
	if(y+1<m && mp[x][y+1]!='0' && vis[x][y+1]==0) dfs(x,y+1,n,m);
	if(y-1>=0 && mp[x][y-1]!='0' && vis[x][y-1]==0) dfs(x,y-1,n,m);
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>mp[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]!='0' && vis[i][j]==0)
			{
				flag=0;
				dfs(i,j,n,m);
				if(flag)
				 bz++;
				ld++;
			}
		}
	}
	cout<<ld<<" "<<bz<<endl;
	return 0;
} 
