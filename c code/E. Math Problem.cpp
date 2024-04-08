#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=10005;
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		int n,k,m,a,b; cin>>n>>k>>m>>a>>b;
		if(n%m==0) cout<<0<<endl;
		else if(k==1) cout<<-1<<endl;
		else
		{
			int sum=0;
			while(n>m)
			{
				n/=k;
				sum+=b;
			}
			int ma=LLONG_MAX;
			int cnt=0;
			int kk=n;
			while(kk)
			{
				cnt++;
				kk/=k;
			}
			ma=min(ma,cnt*b);
			int now=k;
			while(m%n>now)
			{
				n/=k;
				now*=k;
				sum+=b;
			}
			cout<<min(ma,sum+(m/(n*k)*a))<<endl;			
		}
	}
	return 0;
}