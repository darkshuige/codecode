#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200005;
const int mod=1e9+7;
int dp[200005][3];
char s[maxn];
//1 [1,9]xxxxx
//2 [1,9]xxxx0,2,4,6,8
signed main()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	 if((s[i]-'0')%2==0) ans++;//处理单个的情况
	
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=dp[i-1][1];
		dp[i][2]=dp[i-1][2];
		dp[i][1]=(dp[i][1]+dp[i-1][1])%mod;//无论后面加的什么数，都可以构成一个新方案
		if((s[i]-'0')%2==0)
		{
			dp[i][2]=(dp[i][2]+dp[i-1][1])%mod;
		}
		if(s[i]!='0')
		{
			dp[i][1]=(dp[i][1]+1)%mod;//一个空串通过加第一个数字
		}
	}
	ans=(ans+dp[n][2])%mod;
	cout<<ans<<endl;
	return 0;
}