#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f
using namespace std;
const int maxn=500005;
int a[maxn];
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,x;
		cin>>n>>k>>x;
		int l=(1+k)*k/2,r=(2*n-k+1)*k/2;
		if(x>=l && x<=r)
		 cout<<"YES"<<endl;
		else
		 cout<<"NO"<<endl;
	} 
	return 0;
 } 
