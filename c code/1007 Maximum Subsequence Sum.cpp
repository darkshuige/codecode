#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
<<<<<<< HEAD
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
=======
const int maxn=100005;
int a[maxn];
signed main()
{
	int n; cin>>n;
	int ma=0;
	int l,r,ll=0,rr=0;
	int sum=0;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	l=0,r=0,ma=a[0],sum=a[0];
	while(1)
	{
		if(r==n-1 && l==n-1) break;
		sum+=a[++r];
		if(sum>ma)
		{
			ma=sum;
			ll=l;
			rr=r;
		}
		while(sum+a[r+1]>0 && r<=n-1)
		{
			r++;
			sum+=a[r+1];
			if(sum>ma)
			{
				ma=sum;
				ll=l;
				rr=r;
			}
		}
		sum-=a[l++];
		if(sum>ma)
		{
			ma=sum;
			ll=l;
			rr=r;
		}
	}
	if(ma>0)
	 cout<<ma<<" "<<ll<<" "<<rr<<endl;
	else
	 cout<<0<<" "<<0<<" "<<n-1<<endl;
>>>>>>> 99bd31cfc9407c62b17c957c17647b60099340c4
	return 0;
} 