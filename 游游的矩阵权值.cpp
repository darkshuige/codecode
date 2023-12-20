#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int mod=1000000007;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	if(n==2)
	{
		cout<<20<<endl;
		return 0;
	}
	int sum=0;
	sum+=20;
	sum+=((((4*n%mod+1)%mod*(2*n%mod-4)%mod)%mod)%mod*3)%mod;
	sum+=(((((n*n)%mod+4*n%mod-3+mod)%mod*(4+n*n%mod-4*n%mod+mod)%mod)%mod)%mod*2)%mod;
	cout<<sum%mod<<endl;
	return 0;
} 
