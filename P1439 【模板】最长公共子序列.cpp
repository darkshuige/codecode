#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int ind[maxn],b[maxn];
int dp[maxn];
signed main()
{
    int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		b[t]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		ind[i]=b[t];
	}
	int len=1;
	dp[1]=ind[1];
	for(int i=2;i<=n;i++)
	{
		if(dp[len]<ind[i])//如果后面的比他大就放进去
		 dp[++len]=ind[i];
		else//如果小就找到第一个大于他的点然后放进去
		{
			int p=upper_bound(dp+1,dp+1+len,ind[i])-dp;
			dp[p]=ind[i];
		}
	}
	cout<<len<<endl;
    return 0;
}