#include<bits/stdc++.h>
using namespace std;
#define int long long
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
signed main()
{
	jiasu;
	int n;
	int sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int op;
		cin>>op;
		if(op>=0)
		 sum+=op;
		else
		 sum+=op*i;
	}
	cout<<sum<<endl;
	return 0;
}
