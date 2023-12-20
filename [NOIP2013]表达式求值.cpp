#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int mod=10000;
signed main()
{
	int sum=0;
	int a,c;
	char op;
	cin>>a;
	while(cin>>op>>c)
	{
		if(op=='+')
		{
			sum=(sum+a)%mod;
			a=c;
		}
		else
		{
			a=(a*c)%mod;
		}
	}
	sum=(sum+a)%mod;
	cout<<sum<<endl;
	return 0;
} 
