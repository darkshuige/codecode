#include<iostream>
#include <iomanip>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2000;
double dp[maxn][maxn];//f[i][j]表示拿了i个和拿了j个还要几步才能到终点
//求期望，因为终点比较好求，所以从后往前推
signed main()
{
	int n,s;
	cin>>n>>s;
	dp[n][s]=0;//终点，要求的是dp[0][0]
	for(int i=n;i>=0;i--)
	{
		for(int j=s;j>=0;j--)
		{
			if(i==n && j==s) continue;
			dp[i][j]+=(dp[i][j+1]*(1.0*i/n)*(1.0-1.0*j/s)+dp[i+1][j]*(1.0-1.0*i/n)*(1.0*j/s)+dp[i+1][j+1]*(1-1.0*i/n)*(1-1.0*j/s)+1.0)/(1.0-(1.0*i/n)*(1.0*j/s));
		}
	}
	cout<<fixed<<setprecision(4)<<dp[0][0]<<endl;
	return 0;
} 
