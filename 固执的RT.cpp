#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=100005;
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		sum+=op;
	}
	if(sum>=m)
	 cout<<"YES"<<endl;
	else
	 cout<<"NO"<<endl;
	return 0;
} 
