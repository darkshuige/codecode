#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;
const int maxn=200005;
int a[maxn]={0},b[maxn];
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			a[i]+=a[i-1];
		}
		int ma=-1e18,sum=-1e18;
		for(int i=k;i+k<=n;i++)
		{
			ma=max(ma,a[i]-a[i-k]);
			sum=max(sum,ma+a[i+k]-a[i]);
		}
		cout<<sum<<endl;
	}
	return 0;
}
