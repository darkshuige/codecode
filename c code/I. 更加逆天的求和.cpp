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
//	cin>>t;
//	for(int i=0;i<t;i++)
//	{
		int n;
		for(int n=1;n<=20;n++)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			 for(int j=1;j<=n;j++)
			  sum+=(i/j);
			cout<<n<<" "<<sum<<endl;	
		}
		
//	}
	return 0;
} 
