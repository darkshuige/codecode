#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
int mod;
signed main()
{
	jiasu;
	int n;
	cin>>n>>mod;
	int ans=2;
	for(int i=0;i<n;i++)
	 ans=(ans*ans)%mod;
	cout<<ans<<endl;
	return 0;
}

