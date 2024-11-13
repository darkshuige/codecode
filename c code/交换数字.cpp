#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=200005;
const int mod=998244353;
char a[maxn],b[maxn];
signed main()
{
	jiasu;
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
	 if(a[i]>b[i]) swap(a[i],b[i]);
	int aa=0,bb=0;
	for(int i=1;i<=n;i++)
	{
		aa=aa*10+(a[i]-'0');
		bb=bb*10+(b[i]-'0');
		aa%=mod; bb%=mod;
	}
	cout<<aa*bb%mod<<endl;
	return 0;
}

