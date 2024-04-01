#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin,tie(0),cout.tie(0)
using namespace std;
const int maxn=400005;
char g[10][10];
int flag,n;
string a,b;
int ha[10]={0},hb[10]={0},hc[10]={0},la[10]={0},lb[10]={0},lc[10]={0};
void dfs(int x,int y)
{
	if(flag) return ;
	if(x==n)
	{
		flag=1;
		return ;
	}
	if((ha[x]==1 && hb[x]==1 && hc[x]==1) || la[y]==1 && lb[y]==1 && lc[y]==1)
	{
		if(y+1<n)
		 dfs(x,y+1);
		else
		 dfs(x+1,0);
	}
	if(x==0)
	{
		if(a[y]=='A' && ha[0]==0 && la[y]==0)
		{
			ha[0]=1;la[y]=1;
			g[x][y]='A';
			if(y+1<n)
			 dfs(x,y+1);
			else
			 dfs(x+1,0);
			ha[0]=0;la[y]=0;
			g[x][y]='.';
		}
		else if(a[y]=='B' && hb[0]==0 && lb[y]==0)
		{
			hb[0]=1;lb[y]=1;
			g[x][y]='B';
			if(y+1<n)
			 dfs(x,y+1);
			else
			 dfs(x+1,0);
			hb[0]=0;lb[y]=0;
			g[x][y]='.';
		}
		else if(a[y]=='C' && hc[0]==0 && lc[y]==0)
		{
			hc[0]=1;lc[y]=1;
			g[x][y]='C';
			if(y+1<n)
			 dfs(x,y+1);
			else
			 dfs(x+1,0);
			hc[0]=0;lc[y]=0;
			g[x][y]='.';
		}
	}
	else if(y==0)
	{
		if(b[x]=='A' && ha[x]==0 && la[0]==0)
		{
			ha[x]=1;la[0]=1;
			g[x][y]='A';
			if(y+1<n)
			 dfs(x,y+1);
			else
			 dfs(x+1,0);
			ha[x]=0;la[0]=0;
			g[x][y]='.';
		}
		else if(b[x]=='B' && hb[x]==0 && lb[0]==0)
		{
			hb[x]=1;lb[0]=1;
			g[x][y]='B';
			if(y+1<n)
			 dfs(x,y+1);
			else
			 dfs(x+1,0);
			hb[x]=0;lb[0]=0;
			g[x][y]='.';
		}
		else if(b[x]=='C' && hc[x]==0 && lc[0]==0)
		{
			hc[x]=1;lc[0]=1;
			g[x][y]='C';
			if(y+1<n)
			 dfs(x,y+1);
			else
			 dfs(x+1,0);
			hc[x]=0;lc[0]=0;
			g[x][y]='.';
		}
	}
	else
	{
		if(ha[x]==0 && la[y]==0)
		{
			ha[x]=1;la[y]=1;
			g[x][y]='A';
			if(y+1<n)
			 dfs(x,y+1);
			else
			 dfs(x+1,0);
			ha[x]=0;la[y]=0;
			g[x][y]='.';
		}
		else if(hb[x]==0 && lb[y]==0)
		{
			hb[x]=1;lb[y]=1;
			g[x][y]='B';
			if(y+1<n)
			 dfs(x,y+1);
			else
			 dfs(x+1,0);
			hb[x]=0;lb[y]=0;
			g[x][y]='.';
		}
		else if(hc[x]==0 && lc[y]==0)
		{
			hc[x]=1;lc[y]=1;
			g[x][y]='C';
			if(y+1<n)
			 dfs(x,y+1);
			else
			 dfs(x+1,0);
			hc[x]=0;lc[y]=0;
			g[x][y]='.';
		}
	}
}
signed main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	 for(int j=0;j<n;j++)
	  g[i][j]='.';
	cin>>a>>b;
	flag=0;
	dfs(0,0);
	if(flag)
	{
		cout<<"Yes"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<g[i][j];
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}


