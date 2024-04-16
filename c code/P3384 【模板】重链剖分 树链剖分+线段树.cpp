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
	int add,sum;
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
	tr[u].sum=tr[lc].sum+tr[rc].sum;
}
void pushdown(int u)
{
	if(tr[u].add)
	{
		tr[lc].sum+=tr[u].add*(tr[lc].r-tr[lc].l+1);
		tr[rc].sum+=tr[u].add*(tr[rc].r-tr[rc].l+1);
		tr[lc].add+=tr[u].add;
		tr[rc].add+=tr[u].add;
		tr[u].add=0;
	}
}
void build(int u,int l,int r)
{
	tr[u]={l,r,0,nw[r]};
	if(l==r) return ;
	int mid=l+r>>1;
	build(lc,l,mid); build(rc,mid+1,r);
	pushup(u);
}
int query(int u,int l,int r)
{
	if(l<=tr[u].l && r>=tr[u].r) return tr[u].sum;
	pushdown(u);
	int mid=tr[u].l+tr[u].r>>1;
	int res=0;
	if(l<=mid) res+=query(lc,l,r);
	if(r>mid) res+=query(rc,l,r);
	return res;
}
int query_path(int u,int v) //查询路径
{
	int res=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v); //u始终是深的那个
		res+=query(1,id[top[u]],id[u]);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v); //最后一段
	res+=query(1,id[v],id[u]);
	return res;
}
int query_tree(int u) //查询子树
{
	return query(1,id[u],id[u]+sz[u]-1);
}
void update(int u,int l,int r,int k){ //线段树修改
  if(l<=tr[u].l&&tr[u].r<=r){
    tr[u].add+=k;
    tr[u].sum+=k*(tr[u].r-tr[u].l+1);
    return;
  }
  pushdown(u);
  int mid=tr[u].l+tr[u].r>>1;
  if(l<=mid) update(lc,l,r,k);
  if(r>mid) update(rc,l,r,k);
  pushup(u);
}
void update_path(int u,int v,int k)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v); //u始终是深的那个
		update(1,id[top[u]],id[u],k);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v); //最后一段
	update(1,id[v],id[u],k);
}
void update_tree(int u,int k) //查询子树
{
	update(1,id[u],id[u]+sz[u]-1,k);
}
signed main()
{
	jiasu;
	cin>>n>>m>>root>>p;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		e[a].push_back(b);e[b].push_back(a);
	}
	dfs1(root,0);
	dfs2(root,root);
	build(1,1,n);
	while(m--)
	{
		int t,u,v,k; cin>>t>>u;
		if(t==1)
		{
			cin>>v>>k;
			update_path(u,v,k);
		}
		else if(t==3)
		{
			cin>>k;
			update_tree(u,k);
		}
		else if(t==2)
		{
			cin>>v;
			cout<<query_path(u,v)%p<<endl;
		}
		else
		{
			cout<<query_tree(u)%p<<endl;
		}
	}
	return 0;
} 	