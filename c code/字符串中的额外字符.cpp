#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int dp[maxn];
map<string,int>mp;
signed main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		string dic;
		cin>>dic;
		mp[dic]++;
	}
	for(int i=0;i<s.size();i++)
	{
		dp[i+1]=dp[i]+1;
		for(int j=0;j<=i;j++)
		{
			if(mp.count(s.substr(j,i+1-j)))
			 dp[i+1]=min(dp[i+1],dp[j]);	
		}
	}
	cout<<dp[s.size()]<<endl;
	return 0;
}