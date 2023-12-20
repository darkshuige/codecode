#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=400005;
int num[maxn],ans;
vector<int>g[maxn];
signed main()
{
	jiasu;
	int n,m,q;
	cin>>n>>m>>q;
	memset(num,0,sizeof num);ans=0;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		num[a]++,num[b]++;
	}
	for(int i=1;i<=n;i++) if(num[i]==1) ans++;
	for(int i=0;i<q;i++)
	{
		int a,b;
		cin>>a>>b;
		num[a]--;
		if(num[a]==1) ans++; else if(num[a]==0) ans--;
		num[b]--;
		if(num[b]==1) ans++; else if(num[b]==0) ans--;
		cout<<ans<<endl;
	}
	return 0;
} 
