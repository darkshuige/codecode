#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ull unsigned long long
#define lc(x) tr[x].l
#define rc(x) tr[x].r
using namespace std;
const int maxn=200005;
int v[maxn];
struct node
{
	int l,r;
	int v;
}tr[maxn*25];
int root[maxn],idx;
void build(int &x,int l,int r)
{
	x=++idx;
	if(l==r)
	{
		tr[x].v=v[l];
		return ;
	}
	int mid=l+r>>1;
	build(lc(x),l,mid);
	build(rc(x),mid+1,r);
}
void modify(int &x,int y,int l,int r,int pos,int k)
{
	x=++idx;
	tr[x]=tr[y];
	if(l==r)
	{
		tr[x].v=k;
		return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) modify(lc(x),lc(y),l,mid,pos,k);
	else modify(rc(x),rc(y),mid+1,r,pos,k);
}
int query(int x,int l,int r,int pos)
{
	if(l==r) return tr[x].v;
	int mid=l+r>>1;
	if(pos<=mid) return query(lc(x),l,mid,pos);
	else return query(rc(x),mid+1,r,pos);
}
signed main()
{
	jiasu;
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	build(root[0],1,n);
	for(int i=1;i<=m;i++)
	{
		int ver,op; cin>>ver>>op;
		if(op==1)
		{
			int x,y; cin>>x>>y;
			modify(root[i],root[ver],1,n,x,y);
		}
		else
		{
			int x; cin>>x;
			cout<<query(root[ver],1,n,x)<<endl;
			root[i]=root[ver];//查询叶也算新版本
		}
	}
	return 0;
}
