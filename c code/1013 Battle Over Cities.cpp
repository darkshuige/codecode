#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1005;
int a[maxn];
vector<pair<int,int> >v;
int f[maxn];
int ans[maxn];
int find(int x)
{
	if(f[x]==x) return f[x];
	else return f[x]=find(f[x]);
}
signed main()
{
	jiasu;
	int n,m,k; cin>>n>>m>>k;
	while(m--)
	{
		int a,b; cin>>a>>b;
		v.push_back({a,b});
	}
	for(int l=1;l<=k;l++) //从1到n哪个不要
	{
		int cnt=n-1;
		int i; cin>>i;
		for(int i=1;i<=n;i++) f[i]=i;
		for(auto k:v)
		{
			int x=k.first,y=k.second;
			if(x==i || y==i) continue;
			int xx=find(x),yy=find(y);
			if(xx!=yy)
			{
				f[xx]=yy;
				cnt--;
			}
		}
		cout<<cnt-1<<endl;
	}
	return 0;
} 