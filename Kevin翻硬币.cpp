#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=200005;
signed main()
{
	jiasu;
	int t ;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		if(n%k==0)
		{
			cout<<n/k<<endl;
			for(int i=1;i<=n-k+1;i+=k)
			{
				if(i!=1)
				 cout<<" ";
				cout<<i;
			}
			cout<<endl;
		}
		else if(k%2==0)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<n<<endl;
			for(int i=1;i<=n;i++)
			{
				if(i!=1) cout<<" ";
				cout<<i;
			}
			cout<<endl;
		}
	}
	return 0;
} 
