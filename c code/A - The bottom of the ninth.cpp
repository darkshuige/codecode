#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ull unsigned long long
using namespace std;
const int maxn=200050;
signed main()
{
	jiasu;
	int sum1=0,sum2=0;
	for(int i=1;i<=9;i++)
	{
		int x; cin>>x;
		sum1+=x;
	}
	for(int i=1;i<=8;i++)
	{
		int x; cin>>x;
		sum2+=x;
	}
	cout<<sum1+1-sum2<<endl;
	return 0;
}
