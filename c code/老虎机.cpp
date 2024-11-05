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
int ksm(int a, int b, int p)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = res*a%p;
		a = a*a%p;
		b >>= 1;
	}
	return res;
}
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		int m,a,b,c; cin>>m>>a>>b>>c;
		int m1,m2,m3;
		int z1,z2,z3;
		if(m==1)
		{
			int fz=c,fm=1;
			cout<<fz*(ksm(fm,mod-2,mod)%mod)%mod<<endl;
		}
		else if(m==2)
		{
			int fz=3*b+c,fm=4;
			cout<<fz*(ksm(fm,mod-2,mod)%mod)%mod<<endl;
		}
		else if(m>=3)
		{
			z1=c%mod; z2=((3*(m-1))%mod*b%mod)%mod; z3=((a%mod*(m-1)%mod)%mod*(m-2)%mod)%mod;
			int fz=(z1+z2+z3)%mod;
			int fm=(m%mod*m%mod)%mod;
			cout<<fz*(ksm(fm,mod-2,mod)%mod)%mod<<endl;
		}
	}
	return 0;
}

