#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10005;
int a[maxn];
int b[maxn];
int dp[300][maxn];
signed main()
{
	jiasu;
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	cin>>k;
	for(int i=1;i<=k;i++) cin>>b[i];
	memset(dp,0,sizeof dp);
	int ma=-1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=k;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(a[i]==b[j])
			 dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
			ma=max(ma,dp[i][j]);
		}
	}
	cout<<ma<<endl;
	return 0;
} 
