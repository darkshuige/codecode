#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int mod=1000000007;
const int maxn=400010;
vector<int>g[maxn];
int k[maxn],b[maxn];
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		if(n>=3)
		{
			for(int i=1;i<=n-3;i+=3)
			{
				cin>>k[i];
				cin>>k[i+1];
				cin>>k[i+2];	
			}
			if(n%3!=0)
			{
				for(int i=(n/3)*3+1;i<=n;i++)
				  cin>>k[i];	
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			 cin>>k[i];
		}
		if(n>=3)
		{
			for(int i=1;i<=n-3;i+=3)
			{
				cin>>b[i];
				cin>>b[i+1];
				cin>>b[i+2];	
			}
			if(n%3!=0)
			{
				for(int i=(n/3)*3+1;i<=n;i++)
				  cin>>b[i];	
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			 cin>>b[i];
		}
		for(int i=1;i<=n;i++)
		{
			int x=i,y;
			cin>>y;
			g[x].push_back(y);
		}
		while(q--)
		{
			int sx,st,p;
			cin>>sx>>st>>p;
			while(st--)
			{
				sx=g[sx].front();
				p=((p%mod*k[sx]%mod)%mod+b[sx])%mod;
			}
			cout<<p<<endl;
		}
	}
	return 0;
}
