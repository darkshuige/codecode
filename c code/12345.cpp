#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll,ll>
#define fi first
#define se second
ll n,m,t,k,q;
double a[100010];
 
ll qpow(ll x, ll q)
{
	ll ans=1;
	while(q)
	{
		if(q & 1) ans=ans*x%n;
		q>>=1;
		x=x*x%n;
	}
	return ans;
}
 
void solve()
{
	cin>>n;
	double sum=0;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		sum+=a[i];
	}
	double x=sum/(n+1);
	ll y=qpow(2022,1204); 
	for(int i=0;i<n;i++)
	{
		if(i==y) cout<<fixed<<setprecision(7)<<2*x<<" ";
		else cout<<fixed<<setprecision(7)<<x<<" ";
	}
	cout<<"\n"; 
} 
      
int main()
{
  	ios::sync_with_stdio(false);
   	cin.tie(0);cout.tie();
	solve();
//	cin>>t;
//	while(t--) solve();
	return 0;
}
