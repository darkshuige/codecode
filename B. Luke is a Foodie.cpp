#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200005;
int a[maxn];
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		int n,x; cin>>n>>x;
		for(int i=1;i<=n;i++) cin>>a[i];
		int sum=0,l=-1e9,r=1e9;
		for(int i=1;i<=n;i++)
		{
			int rr=a[i]+x,ll=a[i]-x;
			l=max(l,ll);r=min(r,rr);
			if(l>r)
			{
				sum++;
				l=ll;
				r=rr;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}