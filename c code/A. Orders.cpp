#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200;
map<int,int>mp;
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		mp.clear();
		int flag=1;
		int n,kk; cin>>n>>kk;
		for(int i=1;i<=n;i++)
		{
			int a,b; cin>>a>>b;
			mp[a]+=b;
		}
		int now=0,pre=0,mo=0;
		for(auto k:mp)
		{
			now=k.first;
			mo+=(now-pre)*kk;
			if(mo>=k.second)
			 mo-=k.second;
			else
			{
				flag=0;
				break;
			}
			pre=now;
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}