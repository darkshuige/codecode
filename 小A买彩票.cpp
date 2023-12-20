#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=35;
int dp[maxn][maxn*4];
int gcd(int a,int b)
{
	int t=a%b;
	while(t)
	{
		a=b;
		b=t;
		t=a%b;
	}
	return b;
}
signed main()
{
	jiasu;
	int n;
	cin>>n;
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i*4;j++)
		{
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+dp[i-1][j-3]+dp[i-1][j-4];
		}
	}
	int b=pow(4,n),a=0;
	for(int i=3*n;i<=4*n;i++)
	{
		a+=dp[n][i];
	}
	int g=gcd(a,b);
	cout<<a/g<<"/"<<b/g<<endl;
	return 0;
}
