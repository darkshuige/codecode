#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
const int mod=1000000007;
const int maxn1=1000005;
vector<int>g[maxn1];
int cnt[maxn1];
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++)
		 g[i].clear();
		while(m--)
		{
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int ma=-1;
		for(int i=1;i<=n;i++)
		{
			cnt[g[i].size()]++;
			int l=g[i].size();
			ma=max(ma,l);
		}
		int s=0,sum=0;
		for(int i=ma-1;i>=2;i--)
		{
			if(i==ma-1)
			 cnt[i]=(cnt[i]%mod+(cnt[i+1]%mod*(i+1)%mod)%mod)%mod;
			else
			 cnt[i]=(cnt[i]%mod+(cnt[i+1]%mod*(i-1)%mod)%mod)%mod;	
		}
		for(int i=2;i<=n;i++)
		 s^=cnt[i];
		cout<<s<<endl;
	}
	return 0;
}
