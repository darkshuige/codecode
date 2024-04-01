#include<bits/stdc++.h>
using namespace std;
long long dp[55];
void init()
{
	dp[1]=0;
	dp[2]=1;
	dp[3]=2;
	for(int i=4;i<55;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
}
int main()
{
	init();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int l,r;
		cin>>l>>r;
		cout<<dp[r-(l-1)]<<endl;
	}
	return 0;
}
