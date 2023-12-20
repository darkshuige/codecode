#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(fasle),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
const int maxn=110;
struct node
{
	int x,y,z;
};
signed main()
{
	int n;
	cin>>n;
	node a[maxn]={0};
	int sum1=0,sum2=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		sum2+=a[i].z;
		if(a[i].x>a[i].y)
		{
			sum1+=a[i].z;
			a[i].x=0;
			a[i].y=0;
			a[i].z=0;
		}
	}
	if(sum1>sum2/2)
	{
		cout<<0<<endl;
		return 0;
	}
	if(n==1)
	{
		cout<<(a[0].y-a[0].x)/2+1<<endl;
		return 0;
	}
	int dp[100005]={0};
	for(int i=0;i<100005;i++)
	 dp[i]=inf;
	int v[100005];
	for(int i=1;i<=n;i++)
	 v[i]=(a[i-1].y-a[i-1].x)/2+1;
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum2;j>=a[i-1].z;j--)
		 dp[j]=min(dp[j],dp[j-a[i-1].z]+v[i]);
	}
	int ans=dp[sum2/2-sum1];
	for(int i=sum2/2-sum1+1;i<100005;i++)
	{
		if(ans>=dp[i])
		{
			ans=dp[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
