#include<bits/stdc++.h>
using namespace std;
int vis[10][10];
int x[]={-1,0,0,1};
int y[]={0,-1,1,0};
char a[10][10];
int sx,sy;
int gx,gy;
int flag=0;
pair<int,int>p;
int bfs(int n,int m)
{
	queue<pair<int,int> >que;
	int i;
	que.push(pair<int,int>(sx,sy));
	vis[sx][sy]=1;
	while(que.size())
	{
		p=que.front(); que.pop();	
		if(p.first==gx && p.second==gy)
		{
			flag=1;	
		} 
		for(i=0;i<4;i++)
		{
			int nx=p.first+x[i],ny=p.second+y[i];
			if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0 && a[nx][ny]!='*')
			{
				que.push(pair<int,int>(nx,ny));
				vis[nx][ny]=1;
			}
		}
	}
	return flag;
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		memset(vis,0,sizeof vis);
		flag=0;
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='S')
				{
					sx=i;
					sy=j;	
				}	
				if(a[i][j]=='T')
				{
					gx=i;
					gy=j;
				}
			}	
		} 
		if(bfs(n,m))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
