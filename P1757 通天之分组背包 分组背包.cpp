#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=1000;
int f[maxn];
vector<pair<int,int> >g[maxn];
signed main()
{
	jiasu;
	int n,m;
	cin>>m>>n;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		g[cc].push_back({aa,bb});
		cnt=max(cnt,cc);
	}//本来f是二维，f[i][j]表示第i组，体积为j的最大值，但是只用到i和i-1所以可以压缩成一维，但是体积要倒序和01背包一样
	for(int i=1;i<=cnt;i++)
	{
		for(int j=m;j>=1;j--)
		{
			for(int k=0;k<g[i].size();k++)
			{
				if(j>=g[i][k].first)
				{
					f[j]=max(f[j],f[j-g[i][k].first]+g[i][k].second);
				}
			}
		}		
	}
	cout<<f[m]<<endl;
	return 0;
} 
