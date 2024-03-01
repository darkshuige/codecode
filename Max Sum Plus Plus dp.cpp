#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1e6+5;
int dp[maxn],f[maxn],a[maxn];
//二维的时候dp[i][j]表示取第j个的时候，分成i组的最大值
//两种可能第j个放在连着的里面dp[i][j]=dp[i][j-1]+a[j];
//可能第j个另开一组，dp[i][j]=max(dp[i-1][k])+a[j]    i-1<=k<=j-1
signed main()
{
	jiasu;
	int n,m,ma;
	while(cin>>m)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		memset(dp,0,sizeof dp);
		memset(f,0,sizeof f);
		//f[j-1]是前面j-1个数取i-1组的最大值
        //dp[j-1]是前面j-1个数取i组的最大值
        //那么dp[j]就是j个数分i组的最大值
		for(int i=1;i<=m;i++)
		{
			ma=-1<<30;
			for(int j=i;j<=n;j++)
			{
				dp[j]=max(dp[j-1],f[j-1])+a[j];
				f[j-1]=ma;
				//这里j-1是因为maxx是上个循环得到的，就是前面dp[j-1]和maxx的较大值
				//假设当前是循环到i组的时候，这个f数组是会在i+1组的时候用到
				ma=max(dp[j],ma);
			}
		}
		cout<<ma<<endl;
	}
	return 0;
}