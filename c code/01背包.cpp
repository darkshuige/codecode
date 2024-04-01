#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000;
int dp[maxn][maxn];//01背包中，dp[i][j]表示到第i个东西容量为j的时候取得的最大值
int f[maxn];
int w[maxn],c[maxn];
signed main()
{
	jiasu;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j<w[i])
			 dp[i][j]=dp[i-1][j];//从上面
			else
			 dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i])//从左上角
		}
	}
	return 0;
}

//演化为一维数组，因为只要上面一行
for(int i=1;i<=n;i++)
{
	for(int j=m;j>=w[i];j--)//如果是正序，那么就会把前面的变了会出错会加多次
	{
		f[j]=max(f[j],f[j-w[i]]+c[i]);//一维就是把i给去了
	}
}