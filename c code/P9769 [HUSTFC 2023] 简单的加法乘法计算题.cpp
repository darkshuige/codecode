#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e6+5;
int a[maxn],dp[maxn],q[maxn];
const int inf = 1e9+5;
int main()
{
	int y,n,m;
	cin>>y>>n>>m;
	for(int i=0;i<m;i++)
	 cin>>a[i];
	for(int i=0;i<=y;i++)
	{
		if(i<=n)
		 dp[i]=1;
		else
		 dp[i]=inf;
	}
	int h=0,t=-1;
	for(int i=1;i<=n;i++)
	{
		if(t>=h && q[h]<i-n+1) h++;
		while(t>=h && dp[q[t]]>=dp[i]) t--;
		q[++t]=i;
	}
	for(int i=n+1;i<=y;i++)
	{
		dp[i]=dp[q[h]]+1;
		for(int j=0;j<m;j++)
		 if(i%a[j]==0) dp[i]=min(dp[i],dp[i/a[j]]+1);
		if(t>=h && q[h]<i-n+1) h++;
		while(t>=h && dp[q[t]]>=dp[i]) t--;
		q[++t]=i;
	}
	cout<<dp[y]<<endl;
    return 0;
}
