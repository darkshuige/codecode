#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int n,m,p;
	cin>>n>>m>>p;
	if(n>=m)
	 cout<<(n-m)/p+1<<endl;
	else
	 cout<<0<<endl;
	return 0;
}
