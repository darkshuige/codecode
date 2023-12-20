#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000050;
const int mod=998244353;
int f[maxn];
void init()
{
	f[1]=1;
	for(int i=2;i<=maxn-50;i++)
	 f[i]=(f[i-1]*i)%mod;
}
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		 ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
signed main()
{
	jiasu;
	init();
	int n;
	while(cin>>n)
	{
		int fm=f[2*n+1];
		int fz=f[n];
		fz=ksm(fz,2);
		cout<<fz*ksm(fm,mod-2)%mod<<endl;
	}
	return 0;
}
