#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int a[1005][1005];
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		memset(dp,0,sizeof dp);
		memset(a,0,sizeof a);
		int n,m;
		cin>>n>>m;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				cin>>a[j][k];
			}
		}
		dp[1][1]=a[1][1];
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				dp[j][k]=max(dp[j-1][k]+a[j][k],dp[j][k-1]+a[j][k]);
			}
		}
		cout<<dp[n][m]<<endl;
	}
	return 0;
} 
