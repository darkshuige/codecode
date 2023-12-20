#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 2e5 + 10, INF = 1e9 + 10;
int n, k, p;
int c[150];//代价
int a[150][10];//每一位的价值
LL dp[100005];//目标为i时所花费的最小代价,i最大55555，dp[i]最大1e11
int m;//10进制目标值，每一位都为p
int main() 
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k >> p;
	for (int i = 1; i <= k; i++) 
	 m = m * 10 + p;//目标值
	for (int i = 1; i <= n; i++) 
	{
		cin >> c[i];
		for (int j = 1; j <= k; j++) 
		 cin >> a[i][j];
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= 0; j--)//555 
		{   //01背包
			//十进制转换
			int w[6] = {0};
			for (int x = j, l = 1; l <= k; l++, x /= 10) //l表示第几位从后往前 
			{
				w[l] = max(0, x % 10 - a[i][l]);//计算每一位的转移
			}
			int x = 0;
			for (int l = k; l > 0; l--) 
			 x = x * 10 + w[l];//确立j由谁转移  x就表示变大了夺少 
			//十进制转换
			//01背包
			dp[j] = min(dp[j], dp[x] + c[i]);//选第i个，目标为j时由x转移的最小代价
		}
	}
	cout << (dp[m] > 1e11 ? -1 : dp[m]);
	return 0;
}
