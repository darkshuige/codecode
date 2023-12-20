#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a,b,c;
		cin>>a>>b>>c;
		if((n*n*n)%2==0)
		 cout<<"Alice"<<endl;
		else 
		 cout<<"Bob"<<endl;
	}
	return 0;
} 
