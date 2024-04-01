#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
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
		int cnt=0;
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		n--;
		while(n)
		{
			n/=2;
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
