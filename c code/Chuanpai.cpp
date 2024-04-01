#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1000005*3+6;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		if(k>12) cout<<0<<endl;
		else
		{
			int sum=0;
			for(int i=1;i<=k/2;i++)
			 if(k-i<=6 && k-i>=1) sum++;
			cout<<sum<<endl;
		}
	}
	return 0;
}