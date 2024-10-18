#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=100005;
const int mod=1000000007;
int a[maxn];
signed main() 
{
    jiasu;
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ma=LLONG_MIN,mi=LLONG_MAX;
	sort(a+1,a+1+n);
	if(n%2==0)
	{
		for(int i=1;i<=n/2;i++)
		{
			int now=a[i]*a[n-i+1];
			ma=max(ma,now);
			mi=min(mi,now);
		}
	}
	else
	{
		ma=a[n];
		mi=a[n];
		n--;
		for(int i=1;i<=n/2;i++)
		{
			int now=a[i]*a[n-i+1];
			ma=max(ma,now);
			mi=min(mi,now);
		}
	}
	cout<<ma-mi<<endl;
    return 0;
}
