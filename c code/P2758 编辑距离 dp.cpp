#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
const int maxn=2020;
int dp[maxn][maxn];//dp[i][j]表示把第一个到i变成第二个到j要用的步数
//删除，添加，修改
signed main()
{
	jiasu;
	string a,b;
	cin>>a>>b;
	int n=a.size(),m=b.size();
	a="#"+a;b="#"+b;
	memset(dp,0,sizeof dp);
	for(int i=0;i<=n;i++) dp[i][0]=i;
	for(int i=0;i<=m;i++) dp[0][i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
			if(a[i]==b[j])
			 dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
		}
	}
	cout<<dp[n][m]<<endl;
    return 0;
}