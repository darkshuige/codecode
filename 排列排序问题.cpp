#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=4000005;
int mod;
int a[maxn];
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
int n,p;
void init()
{
	a[0]=1;
	a[1]=1;
	for(int i=2;i<=p;i++)
	{
		if(i%p==0) a[i]=a[i-1];
		else
		 a[i]=(a[i-1]*i)%p;
	}
	 
}
signed main()
{
	jiasu;
	cin>>n>>p;
	init();
	mod=p;
	for(int i=0;i<n;i++)
	{
		int ans=1;
		int op;
		cin>>op;
		int t=(op/p);
		int yu=(op%p);
		if(op<p)
		{
			ans=a[op];
		}
		else
		{
			ans=(ans*ksm(a[p],t))%p;
			ans=(ans*a[yu])%p;
			t%=p;
			ans=(ans*a[t])%p;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
