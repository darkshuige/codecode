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
#include<iomanip>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=110;
int g[maxn][maxn];
int n,m;
void floyd()
{
	for(int k=1;k<=n;k++)
	 for(int i=1;i<=n;i++)
	  for(int p=1;p<=n;p++)
	   if(g[i][k]==1 && g[k][p]==1)
	    g[i][p]=1;
}
signed main()
{
	jiasu;
	cin>>n>>m;
	memset(g,0,sizeof g);
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x][y]=1;
	}
	floyd();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(g[i][j]==g[j][i])
			 flag=0;
		}
		if(flag) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
