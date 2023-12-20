#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=5000005;
double PI=acos(-1);
const int mod=1000000007;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int sum=n;
		int p=3;
		int k=2;
		while(p<=n)
		{
			sum+=(n-p)/k+1;
			sum%=mod;
			p=p*2+1;
			k*=2;
		}
		cout<<sum%mod<<endl;
	}
	return 0;
}
