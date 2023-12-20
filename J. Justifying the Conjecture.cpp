#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=30;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n<=5)
		 cout<<-1<<endl;
		else if(n%2==0)
		 cout<<2<<" "<<n-2<<endl;
		else if(n%2==1)
		 cout<<3<<" "<<n-3<<endl;
	}
	return 0;
} 
