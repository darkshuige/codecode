#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2000005;
int a[maxn];
signed main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n+1;i<maxn;i++) a[i]=a[(i-1)%n+1];
	while(q--)
	{
		int l,r,t; cin>>l>>r>>t;
		int num=0;
		for(int i=l;i<=r;i++)
		 if(a[i]==t) num++;
		cout<<num*(num-1)/2<<endl;
	}
	return 0;
}