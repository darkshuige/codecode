#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=1000005;
int a[maxn],b[maxn];
int dp[maxn][2];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	for(int i=1;i<=n;i++)
	 cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		if(b[i])
		{
			dp[i+1][1]=max(dp[i][0],dp[i][1])+a[i+1];
			dp[i][1]=max(dp[i][0]+a[i],dp[i][1]);
			dp[i][0]=max(dp[i-1][0]+a[i-1],dp[i][0]);
		}
	}
	cout<<max(dp[n][0],dp[n][1])<<endl;
	return 0;
} 
