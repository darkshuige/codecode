#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
int w[maxn],v[maxn];
pair<int,int>dp[maxn][2];
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];
	}
	int j;
	cin>>j;
	for(int i=1;i<=n;i++)
	{
		if(w[i]<=j)
		{
			dp[1][1]={v[i],i};
		}
	}
	for(int i=2;i<=m;i++)
	{
		cin>>j;
		for(int i=1;i<=n;i++)
		{
			
		}
	}
	return 0;
}
