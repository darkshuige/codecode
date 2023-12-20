#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1010;
const int mod=1e9+7;
bitset<maxn>adj[maxn];
int d[maxn];//度
int c4(int x)
{
	return (x*(x-1)*(x-2)*(x-3)/24)%mod;
}
int c2(int x)
{
	return (x*(x-1)/2)%mod;
}
signed main()
{
	jiasu; 
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			adj[i].reset();
			d[i]=0;
		}
		while(m--)
		{
			int x,y;
			cin>>x>>y;
			d[x]++,d[y]++;
			adj[x].set(y);
			adj[y].set(x);
		}
		int res=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int a=(adj[i] & adj[j]).count();//看他们有几个共同的边
				int b=d[i],c=d[j];
				if(adj[i].test(j))//i和j之间有直接联系 
				 b--,c--;//那么这条不算
				if(a<4)
				 continue;
				res+=c4(a)*c2(b-4)%mod;
				res%=mod;
				res+=c4(a)*c2(c-4)%mod;
				res%=mod; 
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
 
