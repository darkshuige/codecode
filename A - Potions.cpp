#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(fasle),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int n,h,x;
	cin>>n>>h>>x;
	int op=x-h;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		if(k>=op && ans==0)
		 ans=i;
	}
	cout<<ans<<endl;
	return 0;
}
