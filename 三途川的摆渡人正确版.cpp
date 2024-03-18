#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=300;
int dp[2][maxn];//dp[i][j]表示一位是i时最少几个可以达到j
set<int>st;
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		memset(dp,0x3f,sizeof dp);
		st.clear();
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int x; cin>>x;
			st.insert(x);
		}
		for(int i=0;i<=200;i++)//枚举i
		{
			if(st.count(i))
			{
				dp[1][i]=1;
				for(int j=0;j<=200;j++)
				 dp[1][i & j]=min(dp[1][i & j],dp[0][j]+1);
			}
			memcpy(dp[0],dp[1],sizeof dp[0]);
		}                                                                  
		if(dp[0][0]>n) cout<<-1<<endl;    
		else cout<<n-dp[0][0]<<endl;
	}
	return 0;
}