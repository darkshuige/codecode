#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1005;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,op;
		cin>>n;
		int ans=1;
		cin>>op;
		for(int i=0;i<n-1;i++)
		{
			int k;
			cin>>k;
			if((op^k)<(min(op,k)))
			 ans++;
			op^=k;
		}
		cout<<ans<<endl;
	}
	return 0;
}
