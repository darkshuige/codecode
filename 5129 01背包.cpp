#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int dp[5005]={0};
		int v[5005]={0};
		int sum=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			sum+=v[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=sum/2;j>=v[i];j--)
			{
				dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
			}
		}
		cout<<dp[sum/2]<<endl;
	}
	return 0;
}
