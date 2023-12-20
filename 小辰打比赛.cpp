#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200005;
signed main()
{
	jiasu;
	int n,x;
	cin>>n>>x;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		if(x>op)
		 ans+=op;
	}
	cout<<ans<<endl;
	return 0;
} 
