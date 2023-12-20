#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	int n;
	cin>>n;
	int maxn=-1;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		if(a%2==1)
		 maxn=max(maxn,a);
	}
	cout<<maxn<<endl;
	return 0;
}
