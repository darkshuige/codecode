#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int maxn=1005;
int v[maxn],w[maxn],dp[maxn];
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	 cin>>v[i]>>w[i];
	memset(dp,0,sizeof dp);
	for(int i=0;i<m;i++)
	{
		for(int j=n;j>=v[i];j--)
		{
			dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;	
} 
