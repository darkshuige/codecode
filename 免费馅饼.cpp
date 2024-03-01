#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int dp[maxn][20],a[maxn][20];
signed main()
{
	jiasu;
	int n,t,x;
	while(cin>>n)
	{
		int ma=0;
		if(n==0) break;
		memset(dp,0,sizeof dp);
		memset(a,0,sizeof a);
		for(int i=0;i<n;i++)
		{
			cin>>x>>t;
			x++;
			a[t][x]++;
			ma=max(ma,t);
		}
		for(int i=ma;i>=0;i--)
		{
			for(int j=1;j<=11;j++)
			{
				dp[i][j]=max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]))+a[i][j];
			}
		}
		cout<<dp[0][6]<<endl;
	}
	return 0;
}