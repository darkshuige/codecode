#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10000;
double dp[maxn][1005];//f[i][j]表示第i次拿了j个
signed main()
{
	int n,q;
	cin>>n>>q;
	dp[0][0]=1;
	for(int i=1;i<maxn;i++)
	 for(int j=1;j<=n;j++)
	  dp[i][j]+=dp[i-1][j]*j*1.0/n+dp[i-1][j-1]*1.0*(n-j+1)/n;
	while(q--)
	{
		double p;
		cin>>p;
		double res=p/2000;
		int l=0,r=maxn-1;
		int ans;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(dp[mid][n]>=res)
			{
				ans=mid;
				r=mid-1;
			}
			else
			 l=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
