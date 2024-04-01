#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=20;

signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		if(n%2==0)
		{
			cout<<(k-1)%n+1<<endl;
		}
		else
		{
			int g=(k/(n/2));
			int yu=(k%(n/2));
			
		}
	}
	return 0;
}
