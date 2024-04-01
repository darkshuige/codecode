#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int sum=(n-1+(1+n)*n/2);
		for(int i=2;i<=n-1;i++)
		 for(int j=i+1;j<=n;j++)
		  sum+=(j/i);
		cout<<sum<<endl;  
	}
	return 0;
} 
