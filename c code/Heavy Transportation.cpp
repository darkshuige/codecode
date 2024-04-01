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
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1050;
int d[maxn],mp[maxn][maxn];
int vis[maxn],n,m;
void djst() 
{
    for (int i = 1; i <= n; ++i) 
     d[i] = mp[1][i];
    memset(vis, false, sizeof vis);
    while(1)
	{
        int v = -1, m = 0;
        for (int j = 1; j <= n; ++j) 
		{
            if (vis[j]) continue;     
            if (d[j] > m) 
			{
                v = j;
                m = d[j];
            }
        }
		if (v == -1)
		 break;
		vis[v] = true;
		if(vis[n]==1) break;
        for (int j = 1; j <= n; ++j) 
		{
			if(vis[j]) continue;
			if(d[j]<min(d[v],mp[v][j]))
             d[j]=min(d[v],mp[v][j]);
        }
        
    }
}
signed main()
{
	jiasu;
	int t;
	while(cin>>t)
	{
		for(int cnt=1;cnt<=t;cnt++)
		{
			cin>>n>>m;
			memset(mp,0,sizeof mp);
			for(int i=0;i<m;i++)
			{
				int x,y,z;
				cin>>x>>y>>z;
				mp[x][y]=z;mp[y][x]=z;
			}
			djst();
			cout<<"Scenario #"<<cnt<<":"<<endl;
			cout<<d[n]<<endl<<endl;
		}	
	}
	return 0;
}
