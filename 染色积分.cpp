#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=100005;
int dp[maxn][2],w[maxn];
signed main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>w[i];
	string s;
	cin>>s;
	for(int i=1;i<n;i++)
	{
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		if(s[i]!=s[i-1])
		{
			dp[i][1]=max(dp[i-1][0]+w[i-1]+w[i],dp[i-1][1]-w[i-2]+w[i]);
		}
	}
	int ans=max(dp[n-1][0],dp[n-1][1]);
	cout<<ans<<endl;
	return 0;
} 
