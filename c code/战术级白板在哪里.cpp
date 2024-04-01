#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=600;
signed main()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s; cin>>s;
		int ma=LLONG_MIN;
		int now=0;
		for(int j=0;j<s.size();j++)
		{
			now=now*10+(s[j]-'0');
			if(j & 1)
			{
				ma=max(ma,now);
				now=0;
			}
		}
		cout<<ma<<endl;
	}
	return 0;
}