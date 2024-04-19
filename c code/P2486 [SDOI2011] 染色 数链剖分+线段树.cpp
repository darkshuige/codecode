#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc u<<1
#define rc u<<1|1 
using namespace std;
const int maxn=100010;
int root,p,w[maxn];
int n,m,s,a,b;
vector<int>e[maxn];//记录边
int fa[maxn],son[maxn],dep[maxn],sz[maxn];//父节点，重儿子节点，深度，子节点个数
int top[maxn],id[maxn],nw[maxn],cnt;//u所在重链的顶点,剖分后新编号，新编号在树中所对应节点的权值
struct tree
{
	int l,r;
	int num,tag,ll,rr;
}tr[maxn*4];//线段树
void dfs1(int u,int f) // fa,son,dep
{
	fa[u]=f; sz[u]=1; dep[u]=dep[f]+1;
	for(auto v:e[u])
	{
		if(v==f) continue;
		dfs1(v,u);
		//回来的时候
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v]) son[u]=v;//一开始都是0
	}
}
void dfs2(int u,int t)// top id nw
{
	top[u]=t; id[u]=++cnt; nw[cnt]=w[u];//记录链头  
	if(!son[u]) return ;//无重儿子，叶子结点
	dfs2(son[u],t);     //搜重儿子
	//回来的时候
	for(auto v:e[u])
	{
		if(v==fa[u] || v==son[u]) continue;//搜过
		dfs2(v,v);//搜轻儿子 
	}
}
void pushup(int u)
{
    tr[u].ll=tr[lc].ll; tr[u].rr=tr[rc].rr;
    int ans=tr[lc].num+tr[rc].num;
    if(tr[lc].rr==tr[rc].ll) ans--;
    tr[u].num=ans;
}
void pushdown(int u)
{
	if(tr[u].tag)
	{
		tr[lc].tag=tr[rc].tag=tr[u].tag;
		tr[lc].num=tr[rc].num=1;
		tr[lc].ll=tr[lc].rr=tr[u].ll;
		tr[rc].ll=tr[rc].rr=tr[u].ll;
		tr[u].tag=0;
	}
}
void build(int u,int l,int r)
{
	tr[u]={l,r,0,0,nw[l],nw[r]};
	if(l==r) return ;
	int mid=l+r>>1;
	build(lc,l,mid); build(rc,mid+1,r);
	pushup(u);
}
int query(int u,int l,int r,int L,int R)
{
	if(l==tr[u].l) Lc=tr[u].ll;
	if(r==tr[u].r) Rc=tr[u].rr;
	if(l==tr[u].l && r==tr[u].r) return tr[u].num;
	pushdown(u);
	int mid=tr[u].l+tr[u].r>>1;
	int res=0;
	if(r<=mid) query(lc,l,r,L,R);
	else if(l>mid) query(rc,l,r,L,R);
	else
	{
		res+=query(lc,l,mid,L,R);
		res+=query(rc,mid+1,r,L,R);
		if(tr[lc].rr==tr[rc].ll) res--;
		return res;
	}
	pushup(u);
}
void update(int u,int l,int r,int k) //线段树修改
{
	if(l==tr[u].l && r==tr[u].r)
	{
		tr[u].num=tr[u].tag=1;
		tr[u].ll=tr[u].rr=k;
		return ;
	}
	pushdown(u);
	int mid=tr[u].l+tr[u].r>>1;
	if(r<=mid) update(lc,l,r,k);
	else if(l>mid) update(rc,l,r,k);
	else
	{
		update(lc,l,mid,x);
		update(rc,mid+1,r,x);
	}
	pushup(u);
int solve(int u,int v,int id,int c)
{
	int ans=0;
	
}
signed main()
{
	jiasu;
	cin>>n>>m>>root>>p;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<n;i++)
	{
		int u,v; cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);	
	}
	dfs1(1,0);
	dfs2(1,1);
	while(m--)
	{
		char op;
		cin>>op;
		if(op=='C')
		{
			int a,b,c; cin>>a>>b>>c;
			update(1,a,b,c);
		}
		else
		{
			int a,b; cin>>a>>b;
			cout<<query(a,b)<<endl;
		}
	}
	return 0;
} 	