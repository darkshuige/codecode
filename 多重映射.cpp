#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2000005;
int a[maxn],f[maxn];
int n,m;
void init()
{
	for(int i=0;i<maxn;i++) f[i]=i;
}
int find(int x)
{
	if(f[x]==x)
	 return f[x];
	else
	 return f[x]=find(f[x]);
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		 cin>>a[i];
		init();
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			int ex=find(a),ey=find(b);
			if(ex!=ey && ex==a)
			 f[ex]=ey;
		}
		for(int i=1;i<=n;i++)
		{
			cout<<find(a[i])<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
