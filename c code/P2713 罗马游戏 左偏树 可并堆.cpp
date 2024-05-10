#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=1000005;
int v[maxn],lc[maxn],rc[maxn],dis[maxn];//左偏树
int f[maxn];
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int merge(int x,int y)//递归合并
{
	if(!x || !y) return x+y;
	if(v[x]>v[y]) swap(x,y);
	rc[x]=merge(rc[x],y);
	f[rc[x]]=x;
	if(dis[lc[x]]<dis[rc[x]]) swap(lc[x],rc[x]);
	dis[x]=dis[rc[x]]+1;
	return x;
}
signed main()
{
	jiasu;
	int n,m; cin>>n;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++) cin>>v[i];
	dis[0]=-1;
	cin>>m;
	while(m--)
	{
		char op; cin>>op;
		if(op=='M')
		{
			int x,y; cin>>x>>y;
			if(v[x]==-1 || v[y]==-1) continue;
			x=find(x),y=find(y);
			if(x!=y) f[x]=f[y]=merge(x,y);
		}
		else
		{
			int x; cin>>x;
			if(v[x]==-1)
			{
				cout<<0<<endl;
				continue;
			}
			x=find(x);
			cout<<v[x]<<endl;
			v[x]=-1;
			f[lc[x]]=f[rc[x]]=f[x]=merge(lc[x],rc[x]);
		}
	}
	return 0;
}

