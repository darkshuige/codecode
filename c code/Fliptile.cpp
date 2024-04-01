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
const int maxn=20;
int a[maxn][maxn];
int ans[maxn][maxn];
int temp[maxn][maxn];
int n,m;
int ex[]={+0,-1,+0,+1,+0};
int ey[]={+0,+0,+1,+0,-1};
int work()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<m;j++)
		{
			int t=a[i][j];
			for(int k=0;k<=4;k++)
			{
				int x=i+ex[k],y=j+ey[k];
				if(x<0 || x>=n || y<0 || y>=m) continue;
				t+=temp[x][y];
			}
			if(t & 1)
			{
				temp[i+1][j]=1;
			}
		}
	}
	int i=n-1;
	for(int j=0;j<m;j++)
	{
		int t=a[i][j];
		for(int k=0;k<=4;k++)
		{
			int x=i+ex[k],y=j+ey[k];
			if(x<0 || x>=n || y<0 || y>=m) continue;
			t+=temp[x][y];
		}
		if(t & 1)
		{
			return -1;
		}
	}
	int t=0;
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++)
	  if(temp[i][j] & 1)
	   t++;
	return t;
}
signed main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	int tt=inf;
	for(int i=0;i<(1<<m);i++)
	{
		memset(temp,0,sizeof temp);
		for(int j=0; j<m; j++)
         temp[0][j]= i>>(m-(j+1)) & 1;
        int t=work();
        if(t==-1) continue;
        if(t<tt)
        {
        	tt=t;
        	memcpy(ans,temp,sizeof temp);
		}
	}
	if(tt!=inf)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(j!=0) cout<<" ";
				cout<<ans[i][j];
			}
			cout<<endl;
		}
	}
	else
	 cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
