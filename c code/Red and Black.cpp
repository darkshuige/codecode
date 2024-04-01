#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdio>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=25;
bool used[maxn][maxn];
char mp[maxn][maxn];
int ans,n,m;
void search(int x,int y)
{
	if(x<1 || x>n || y<1 || y>m || used[x][y]==1 || mp[x][y]=='#')
	 return;
	used[x][y]=1;
	ans++;
	search(x-1,y);
	search(x+1,y);
	search(x,y+1);
	search(x,y-1);
}
signed main()
{
	jiasu;
	while(cin>>m>>n)
	{
		if(n==0 && m==0)
		 break;
		int x,y;
		memset(used,0,sizeof used);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[i][j];
				if(mp[i][j]=='@')
				 x=i,y=j;
			}
		}
		ans=0;
		search(x,y);
		cout<<ans<<endl;
	}
	return 0;
}
