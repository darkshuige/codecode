#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=110;
const double eps=1e-6;
string s;
signed main()
{
	jiasu;
	int n,k;
	cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		sum+=x;
	}
	cout<<sum/n<<".";
	sum%=n; 
	for(int i=0;i<k;i++)
	{
		sum*=10;
		cout<<sum/n;
		sum%=n;
	}
	cout<<endl;
	return 0;
}