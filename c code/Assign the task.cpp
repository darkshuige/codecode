#include <iostream>
#include <cstdio>
#include <algorithm>
#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#include<iomanip>
#include<string>
#include<stack>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int maxn=50008;
struct Node
{
    int l,r,val,lazy;
}tr[maxn<<4];
int h[maxn],cnt,in[maxn],out[maxn],f[maxn],vis[maxn],ti;
struct edge
{
	int to,ne;
}g[maxn];
void init()
{
	memset(h,0,sizeof h);memset(f,-1,sizeof f);memset(vis,0,sizeof vis);
	cnt=1;ti=0;
}
void add(int a,int b)
{
	g[cnt].to=b;g[cnt].ne=h[a];
	h[a]=cnt++;
}
void dfs(int u)
{
	vis[u]=1;
	in[u]=++ti;
	for(int i=h[u];i;i=g[i].ne)
	{
		int v=g[i].to;
		if(vis[v]==0)
		 dfs(v);
	}
	out[u]=ti;
}
void build(int p,int l,int r)
{
    tr[p]={l,r,-1,-1};
    if(l==r) return;
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void pushdown(int p)
{
	if(tr[p].lazy!=-1)
	{
		tr[lc].lazy=tr[rc].lazy=tr[p].lazy;
		tr[lc].val=tr[rc].val=tr[p].lazy;
	}
	tr[p].lazy=-1;
}
void update(int p,int x,int y,int k)
{
	if(x<=tr[p].l && y>=tr[p].r)
	{
		tr[p].val=k;
		tr[p].lazy=k;
		return ;
	}
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x,y,k);
	if(y>m) update(rc,x,y,k);
}
int query(int p,int x,int y,int k)
{
	if(tr[p].lazy!=-1 && x<=tr[p].l && y>=tr[p].r) return tr[p].val;
	if(tr[p].l==tr[p].r && tr[p].l==k) return tr[p].val;
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	if(k<=m) return query(lc,x,y,k);
	if(k>m) return query(rc,x,y,k);
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
    	init();
    	cout<<"Case #"<<k<<endl;
    	int n;
    	cin>>n;
    	build(1,1,n);
    	for(int i=0;i<n-1;i++)
    	{
    		int a,b;
    		cin>>a>>b;
    		add(b,a);
    		f[a]=b;
		}
		int root;
		for(int i=1;i<=n;i++) if(f[i]==-1) root=i;
		dfs(root);
		int m;
		cin>>m;
		while(m--)
		{
			char op;
			int x,y;
			cin>>op;
			if(op=='C')
			{
				cin>>x;
				cout<<query(1,1,n,in[x])<<endl;
			}
			if(op=='T')
			{
				cin>>x>>y;
				update(1,in[x],out[x],y);
			}
		}
	}
    return 0;
}
