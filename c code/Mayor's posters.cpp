#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=100005;
int ll,rr;
struct node
{
	int l,r,val,lazy;
}tr[maxn*4];
int w[maxn];
void pushup(int p)
{
	if(tr[lc].val!=tr[rc].val) tr[p].val=-1;
	else tr[p].val=tr[lc].val;
}
void build(int p,int l,int r)//p是根节点，l表示左边界，r是又边界 
{
	tr[p]={l,r,0,0};
	if(l==r)//是叶子结点就返回 
	 return ;
	int mid=l+r>>1;//不是就裂开 
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(p);
}
void pushdown(int p)
{
	if(tr[p].lazy)
	{
		tr[lc].lazy=tr[rc].lazy=tr[p].lazy;
		tr[lc].val=tr[rc].val=tr[p].val;
	}
	tr[p].lazy=0;
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
	pushup(p);
}
set<int>st;
void query(int p,int x,int y)
{
	if(tr[p].l<x || tr[p].r>y) return ;
	if(tr[p].val!=-1)
	{
		st.insert(tr[p].val);
		return ;
	}
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	query(lc,x,y);query(rc,x,y);
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		st.clear();
		build(1,1,100000);
		for(int i=1;i<=n;i++)
		{
			int a,b;
			cin>>a>>b;
			update(1,a,b,i);
		}
		query(1,1,100000);
		if(st.count(0))
		 cout<<st.size()-1<<endl;
		else
		 cout<<st.size()<<endl;
	}
	return 0;
} 
