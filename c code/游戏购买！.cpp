#include<bits/stdc++.h>
using namespace std;
int a[2005][2005]={0};
bool vis[2005][2005];
int nx[]={-1,0,0,1};
int ny[]={0,-1,1,0};
int n,m;
pair<int,int>p;
int bfs(pair<int,int>op1,pair<int,int>op2)
{
	memset(vis,0,sizeof vis);
	int sum=0;
	queue<pair<int,int> >que;
	que.push(pair<int,int>(op1.first,op1.second));
	vis[op1.first][op1.second]=1;
	int posx,posy;
	while(que.size())
	{
		p=que.front();que.pop();
		if(abs(p.first-posx)==1 || abs(p.second-posy)==1)
		 sum++;
		for(int i=0;i<=3;i++)
		{
			int sx=p.first+nx[i],sy=p.second+ny[i];
			if(sx>0 && sx<=n && sy>0 && sy<=m && vis[sx][sy]==0 && a[sx][sy]!=-1)
			{
				if(sx==op2.first && sy==op2.second)
				{
					return sum;
				}
				que.push(pair<int,int>(sx,sy));
			}
			posx=sx,posy=sy;
		}
		
		
	}
	return INT_MAX;
}
int main()
{
	int x;
	int count=0;
	int flag=0;
	memset(a,0,sizeof a);
	cin>>n>>m>>x;
	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>x)
			{
				count++;
			}
		}
	}
	int minx=INT_MAX;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]>x)
			{
				int sum1,sum2,sum;
				sum1=bfs(pair<int,int>(sx,sy),pair<int,int>(i,j));
				sum2=bfs(pair<int,int>(i,j),pair<int,int>(ex,ey));
				sum=sum1+sum2;
				if(sum1!=INT_MAX || sum2!=INT_MAX)
				{
					flag=1;
				}
				if(sum<minx)
				 minx=sum;
			}
		}
	}
	if(flag==0 || count==0)
	 cout<<"-1"<<endl;
	else
	 cout<<minx<<endl;
	return 0;
}
