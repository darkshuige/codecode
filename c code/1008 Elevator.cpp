#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10005;
signed main()
{
	int n; cin>>n;
	int sum=0;
	int now=0;
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		if(k>now)
		{
			sum+=(k-now)*6;
			now=k;
		}
		else
		{
			sum+=(now-k)*4;
			now=k;
		}
		sum+=5;
	}
	cout<<sum<<endl;
	return 0;
} 