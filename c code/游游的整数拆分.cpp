#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	if(n%3==0)
	{
		cout<<n/3-1<<endl;
	}
	else
	{
		cout<<n/3*2<<endl;
	}
	return 0;
}
