#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=500005;
int a[maxn];
signed main()
{
	jiasu;
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n-1;i++)
	{
		int v,u,w; cin>>u>>v>>w;
		a[u]^=w; a[v]^=w;
	}
	while(q--)
	{
		int op; cin>>op;
		if(op==1)
		{
			int u,v,w; cin>>u>>v>>w;
			a[u]^=w; a[v]^=w;
		}
		else
		{
			int u; cin>>u;
			cout<<a[u]<<endl;
		}
	}
	return 0;
}