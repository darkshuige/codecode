#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1 | 1
using namespace std;
const int maxn=2000;
int dp[maxn][maxn]={0};
signed main()//用动态规划求解，dp[i][j]表示a字符串到第i位，b字符串到第j位时最大的子串
           // 当a[i]==b[j]的时候 dp[i][j]=dp[i-1][j-1]+1反之则等于0
           //时间复杂度为O(a.length*b.length) 
           //若要实现求出第一个以及所有，就枚举找到ma为最大时的i，j并且往前枚举，直到a[i]!=b[j]
		   //求出其他子串同理 
{
	jiasu;
	string a="1324564313216546321316548978";
	string b="4134135465134687465321321464654654513215";
	int ma=0;
	for(int i=1;i<=a.size();i++)
	{
		for(int j=1;j<=b.size();j++)
		{
			if(a[i]==b[j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=0;
			}
			ma=max(ma,dp[i][j]);
		}
	}
	cout<<ma<<endl;
	return 0;
} 
