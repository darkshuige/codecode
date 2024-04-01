#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
signed main()
{
	jiasu;
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	int maxn=INT_MIN;
	int k=min(n/2,m);
	for(int i=0;i<=k;i++)
	{
		int sum=0;
		sum+=i*a;
		int op=min(n-2*i,(m-i)/2);
		sum+=op*b;
		maxn=max(maxn,sum);
	}
	cout<<maxn<<endl;
	return 0;
} 
