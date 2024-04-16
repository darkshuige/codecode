#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
const double PI=3.141592;
int a[20];
signed main()
{
	int n,k; cin>>n>>k;
	//左边界推右边界，右边界=n/(n/i)
	int ans=n*k,r;
	for(int l=1;l<=n;l=r+1)
	{
		if(k/l==0) break;
		r=min(k/(k/l),n);
		ans-=(k/l)*(r-l+1)*(l+r)/2;
	}
	cout<<ans<<endl;
	return 0;
} 	