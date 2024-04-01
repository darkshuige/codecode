#include<bits/stdc++.h>
using namespace std;
int dp[105];
void init()
{
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<105;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
		dp[i]%=1000000007;
	}
}
int main()
{
	int n;
	init();
	while(cin>>n)
	{
		cout<<dp[n]<<endl;
	}
	return 0;
}
