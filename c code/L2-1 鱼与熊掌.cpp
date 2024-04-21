#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int maxn=100005;
set<int>st[maxn];
signed main()
{
	jiasu;
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		for(int j=1;j<=k;j++)
		{
			int jb; cin>>jb;
			st[i].insert(jb);
		}
	}
	int q; cin>>q;
	while(q--)
	{
		int a,b; cin>>a>>b;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(st[i].count(a) && st[i].count(b))
			 sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}