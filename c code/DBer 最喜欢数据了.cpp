#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2000005;
const int p=998244353;
int ksm(int a,int n)
{
	int res=1;
	while(n)
	{
		if(n & 1)
		 res=(res*a)%p;
		a=(a*a)%p;
		n>>=1;
	}
	return res;
}
int a[maxn];
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(n%2==0)
			{
				if(i<=n/2)
				{
					int x; cin>>x;
					a[i]=((i%p)*((n-(i-1)))*x%p)%p;
					sum=(sum+a[i])%p;
				}
				else
				{
					sum=(sum+a[n-i+1])%p;
				}
			}
			else if(n%2!=0)
			{
				if(i<=n/2+1)
				{
					int x; cin>>x;
					a[i]=((i%p)*((n-(i-1)))*x%p)%p;
					sum=(sum+a[i])%p;
				}
				else
				{
					sum=(sum+a[n-i+1])%p;
				}
			}
		}
		cout<<ksm(sum,p)<<endl;
	}
	return 0;
}