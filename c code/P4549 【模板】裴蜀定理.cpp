#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1000005*3+6;
//裴蜀定理
//一定存在整数x,y满足 ax+by=gcd(a,b)
//一定存在整数x1.....xi 满足 求和i=1~n ai*xi==gcd(a1,a2,a3....an)
signed main()
{
	jiasu;
	int n,ans;
	cin>>n>>ans;
	for(int i=2;i<=n;i++)
	{
		int k; cin>>k;
		ans=__gcd(abs(ans),abs(k));
	}
	cout<<ans<<endl;
	return 0;
}