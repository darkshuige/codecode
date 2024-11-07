#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10005;
int dp[maxn],sum[maxn];
signed main()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>sum[i];
		dp[i]=sum[i];
	}
	int sta=1,ed=1,sta2=1;
	int ans=sum[1];
	for(int i=2;i<=n;i++)
	{
		dp[i]=max(sum[i],dp[i-1]+sum[i]);
		if(dp[i-1]<0) sta2=i;
		if(dp[i]>ans)
		{
			if(dp[i-1]<0) sta=sta2;
			ed=i;
			ans=max(ans,dp[i]);		
		}
	}
	if(ans>=0)
	 cout<<ans<<" "<<sum[sta]<<" "<<sum[ed]<<endl;
	else
	 cout<<0<<" "<<sum[1]<<" "<<sum[n]<<endl;
	return 0;
} 