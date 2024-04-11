#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
const double PI=3.141592;
vector<int>g[27];
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		int a,b; cin>>a>>b;
		if(a>=b) cout<<abs(a-b)<<endl;
		else // a < b
		{
			int ans=LLONG_MAX;
			int kk=min(b%a,abs(b-a*(b/a+1)));
			ans=kk;
			kk-=1;
			for(int pos=1;pos<=kk;pos++)
			{
				if(pos>=ans) break;
				int now=a+pos;
				ans=min(ans,pos+min(b%now,abs(b-now*(b/now+1))));
				if(a-pos>0)
				{
					now=a-pos;
					ans=min(ans,pos+min(b%now,abs(b-now*(b/now+1))));		
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 	