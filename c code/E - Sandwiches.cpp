#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=300005;
vector<int>g[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	int l=maxn,r=0;
	for(int i=1;i<=n;i++)
	{
		int op;
		cin>>op;
		g[op].push_back(i);
		if(op<l) l=op;
		if(op>r) r=op;
	}
	int ans=0;
	for(int i=l;i<=r;i++)
	{
		if(g[i].size()!=0)
		{
			int bef=g[i][0];
			for(auto k:g[i])
			{
				if(k!=bef)
				{
					ans+=k-bef-1;
					bef=k;	
				}
			}	
		}
	}
	cout<<ans<<endl;
	return 0;
}
