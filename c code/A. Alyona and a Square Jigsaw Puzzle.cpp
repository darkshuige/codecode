#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1005;
signed main()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int t; cin>>t;
		int ct=1; int ans=0;
		int sum=0; int sum2=0;
		for(int i=0;i<t;i++)
		{
			int k; cin>>k;
			sum+=k;
			while(sum>sum2)
			{
				sum2=ct*ct;
				ct+=2;
			}
			if(sum==sum2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
