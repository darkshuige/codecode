#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=10005;
int dp[maxn][110],a[maxn];
signed main()
{
	jiasu;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	memset(dp,-INF,sizeof dp);
	for(int i=1;i<=k;i++)
	 dp[i][1]=a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j==1)
			 dp[i][j]=max(dp[i-1][j],a[i]);
			else if(i>k)
			 dp[i][j]=max(dp[i-1][j],dp[i-k][j-1]+a[i]);
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
