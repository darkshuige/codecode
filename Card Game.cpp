#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(flase),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244353;
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
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		n--;
		cout<<ksm(2,n)%mod-1<<endl;
	}
	return 0;
}
 
