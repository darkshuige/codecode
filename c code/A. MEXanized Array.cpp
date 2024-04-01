#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f
using namespace std;
const int maxn=100005;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,x;
		cin>>n>>k>>x;
		if(n<k || x<k-1)
		{
			cout<<-1<<endl;	
		}
		else
		{
			int ans=0;
			ans+=(k-1)*(k)/2;
			if(x>k)
			 ans+=(n-k)*x;
			else
			 ans+=(n-k)*(k-1);
			cout<<ans<<endl;
		}
	} 
	return 0;
}
