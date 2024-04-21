#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
signed main()
{
	int a,b; cin>>a>>b;
	int sum=0;
	for(int i=0;i<b;i++)
	{
		int x; cin>>x;
		sum+=x;
	}
	int k=1;
	while(k*a<=sum) k++;
	k--;
	int ans=sum-k*a;
	if(k>=b)
	 cout<<a<<endl;
	else
	 cout<<ans<<endl;
	return 0;
}	