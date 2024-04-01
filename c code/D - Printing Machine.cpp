#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=500005;
const int mod=998244353;
vector<pair<int,int> >v;
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int l,r;
	cin>>l>>r;
	r+=l;
	v.push_back({l,r});
	int ans=1;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		b+=a;
		int flag=0;
		for(auto k:v)
		{
			if(a>=k.first && b<=k.second)
			{
				flag=1;
				break;
			}
			else if(a<k.first && b>=k.first && b<=k.second)
			{
				flag=1;
				k.first=a;
				ans++;
				break;
			}
			else if(b>k.second && a>k.first && a<k.second)
			{
				flag=1;
				k.second=b;
				ans++;
				break;
			}
		}
		if(flag==0)
		{
			v.push_back({a,b});
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
