#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=105;
int a[maxn],dp1[maxn],dp2[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	 cin>>a[i];
	for(int i=0;i<n;i++)//从前往后求最大上升子串 
	{
		dp1[i]=1;
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i])
			{
				dp1[i]=max(dp1[i],dp1[j]+1);
			}
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		dp2[i]=1;
		for(int j=n-1;j>i;j--)
		{
			if(a[j]<a[i])
			{
				dp2[i]=max(dp2[i],dp2[j]+1);
			}
		}
	}
	int ans=INT_MAX;
	for(int i=0;i<n;i++)
	 ans=min(n-dp1[i]-dp2[i]+1,ans);
	cout<<ans<<endl;
	return 0;
}
