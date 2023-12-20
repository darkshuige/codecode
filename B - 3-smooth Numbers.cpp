#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000050;
const int mod=998244353;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int flag=0;
	while(n%2==0)
	 n/=2;
	while(n%3==0)
	 n/=3;
	if(n==1)
	 cout<<"Yes"<<endl;
	else
	 cout<<"No"<<endl;
	return 0;
}
