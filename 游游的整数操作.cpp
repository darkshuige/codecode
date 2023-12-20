#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=100005;
const int mod=1000000007;
int a[maxn];
signed main()
{
	jiasu;
	int n,k;
	cin>>n>>k;
	int sum=0,sub=0; 
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	for(int i=0;i<k;i++)
	{
		int op,x;
		cin>>op>>x;
		if(op==1)
		{
			sum+=x;
		}
		else if(op==2)
		{
			sum-=x;
			sub=min(sub,sum);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]+sub>=0)
		 ans=(ans+a[i]+sum)%mod;
		else
		 ans=(ans+sum-sub)%mod;
	}
	cout<<ans<<endl;
	return 0;
}
