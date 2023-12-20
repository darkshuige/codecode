#include<bits/stdc++.h>
using namespace std;
int cmp(pair<int,int>a,pair<int,int>b)
{
	if(a.first!=b.first)
	{
		return a.first<b.first;
	}
	else
	{
		return a.second<b.second;
	}
}
int main()
{
	int t,m;
	pair<int,int>a[110];
	cin>>t>>m;
	int dp[105][1005]={0};//i个物品//选出不大于j的最大值 
	for(int i=0;i<m;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	sort(a,a+m,cmp);
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=t;j++)
		{
			if(j<a[i].first)
			{
				dp[i+1][j]=dp[i][j];
			}
			else
			{
				dp[i+1][j]=max(dp[i][j],dp[i][j-a[i].first]+a[i].second);
			}
		}
	}
	cout<<dp[m][t]<<endl;
	
	return 0;
} 
