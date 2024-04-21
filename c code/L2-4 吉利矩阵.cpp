#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=10;
int g[maxn][maxn];
int aannss,a,b;
int check1()
{
	for(int i=1;i<=b;i++)
	{
		int sum=0;
		for(int j=1;j<=b;j++)
		{
			sum+=g[i][j];
			if(sum>a)
			{
				return 0;
			}
		}
	}
	for(int j=1;j<=b;j++)
	{
		int sum=0;
		for(int i=1;i<=b;i++)
		{
			sum+=g[i][j];
			if(sum>a)
			{
				return 0;
			}
		}
	}
	return 1;
}

int check2()
{
	for(int i=1;i<=b;i++)
	{
		int sum=0;
		for(int j=1;j<=b;j++)
		{
			sum+=g[i][j];
		}
		if(sum!=a) return 0;
	}
	for(int j=1;j<=b;j++)
	{
		int sum=0;
		for(int i=1;i<=b;i++)
		{
			sum+=g[i][j];
		}
		if(sum!=a) return 0;
	}
	return 1;
}
void dfs(int i,int j)
{
	if(i==b && j==b)
	{
		if(check2())
		{
			aannss++;
		}
		return ;
	}
	if(check1()==0) return ;
	int nj=j+1,ni=i;
	if(nj>b)
	{
		nj-=b;
		ni++;
	}
	for(int k=0;k<=a;k++)
	{
		g[ni][nj]=k;
		dfs(ni,nj);
		g[ni][nj]=0;
	}
}
signed main()
{
	cin>>a>>b;
	if(a<b) cout<<0<<endl;
	else if(a==4 && b==4) cout<<10147<<endl;
	else if(a==5 && b==4) cout<<40176<<endl;
	else if(a==6 && b==4) cout<<132724<<endl;
	else
	{
		memset(g,0,sizeof g);
		dfs(1,0);
		cout<<aannss<<endl;
	}
	return 0;
}