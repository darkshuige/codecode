#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=300005;
unordered_set<int>st[maxn];
signed main()
{
	jiasu;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		int op; cin>>op;
		st[i].insert(op);
	}
	while(q--)
	{
		int a,b;cin>>a>>b;
		st[b].insert(st[a].begin(),st[a].end());st[a].clear();
		cout<<st[b].size()<<endl;
	}
	return 0;
} 
