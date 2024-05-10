#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=100005;
int n,m;
int fa[maxn],pay[maxn],lead[maxn];
int lc[maxn],rc[maxn],dis[maxn],siz[maxn],root[maxn];//左偏树
int sum[maxn],ans;
int merge(int x,int y)//递归合并
{
	if(!x || !y) return x+y;
	if(pay[x]<pay[y]) swap(x,y);
	rc[x]=merge(rc[x],y);
//	fa[rc[x]]=x;
	if(dis[lc[x]]<dis[rc[x]]) swap(lc[x],rc[x]);
	dis[x]=dis[rc[x]]+1;
	return x;
}
signed main()
{
	jiasu;
	cin>>n>>m;
	dis[0]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>fa[i]>>pay[i]>>lead[i];
		root[i]=i;
		siz[i]=1;
		sum[i]=pay[i];
		ans=max(ans,lead[i]);//选一个节点的贡献
	}
	for(int i=n;i>=1;i--)
	{
		int f=fa[i];
		root[f]=merge(root[i],root[f]);
		siz[f]+=siz[i]; sum[f]+=sum[i];
		while(sum[f]>m)
		{
			siz[f]--; sum[f]-=pay[root[f]];
			root[f]=merge(lc[root[f]],rc[root[f]]);
		}
		ans=max(ans,lead[f]*siz[f]);
	}
	cout<<ans<<endl;
	return 0;
}

