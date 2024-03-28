#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
set<int>g[maxn];
void init(int n)
{
	for(int i=1;i<=n;i++) g[i].clear();
}
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		int n,m; cin>>n>>m;
		init(n);
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			g[a].insert(b);
			g[b].insert(a);
		}
		int sum=0;
		int pos=1;
		while(pos<n)
		{
			if(g[pos].count(pos+1))
			 pos++;
			else
			 sum+=1,pos++;
			if(g[pos-1].size()<=g[pos].size())
			 for(auto k:g[pos-1])
			  g[pos].insert(k);
			else
			{
				for(auto k:g[pos])
				 g[pos-1].insert(k);
				swap(g[pos-1],g[pos]);	
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}