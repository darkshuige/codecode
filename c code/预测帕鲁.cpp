#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
map<int,int>mp;
const int maxn=100005;
const double PI=3.141592;
int k[maxn];
signed main()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>k[i];
	int a,b; cin>>a>>b;
	int now=ceil(1.0*(k[a]+k[b])/2);
	int pos=0;
	int mi=LLONG_MAX;
	for(int i=1;i<=n;i++)
	{
		if(abs(now-k[i])<mi)
		{
			mi=abs(now-k[i]);
			pos=i;
		}
	}
	cout<<pos<<endl;
	return 0;
} 	