#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=100005;
struct node
{
	int l,r,sum,add,mul;
}tr[maxn*4];
int w[maxn];
void calc(node &t,int m,int a)//m表示父节点的mul，a表示父节点的add
{
	t.sum=(t.sum*m+(t.r-t.l+1)*a) ;
	t.mul=t.mul*m ;
	t.add=(t.add*m+a) ;
} 
void pushup(int p)
{
	tr[p].sum=(tr[lc].sum+tr[rc].sum) ;
}
void pushdown(int p)
{
	calc(tr[lc],tr[p].mul,tr[p].add);
	calc(tr[rc],tr[p].mul,tr[p].add);
	tr[p].mul=1;
	tr[p].add=0;
}
void build(int p,int l,int r)
{
	tr[p]={l,r,w[l] ,0,1};
	if(l==r)//是叶子结点就返回 
	 return ;
	int mid=l+r>>1;//不是就裂开 
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(p);
}
void update(int p,int l,int r,int m,int a)//当加法的时候m=1，乘法的时候a=0  l,r表示要修改区间的范围，u是根节点 
{
	if(r<tr[p].l || l>tr[p].r) return ;
	if(l<=tr[p].l && r>=tr[p].r)
	{
		calc(tr[p],m,a); return ;//如果覆盖那么直接计算p这个点的sum,add,mul 
	}
	pushdown(p);
	update(lc,l,r,m,a);
	update(rc,l,r,m,a);
	pushup(p);
}
int query(int p,int x,int y)
{
	if(x<=tr[p].l && y>=tr[p].r)//如果全部包含 
	 return tr[p].sum;
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);//查成分的时候可能会去叶子结点，就得把钱还清 
	int sum=0;
	if(x<=m)
	 sum=(sum+query(lc,x,y)) ;
	if(y>m)
	 sum=(sum+query(rc,x,y)) ;//注意是y>m的时候 
	return sum;
}
signed main()
{
	jiasu;
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
		 cin>>w[i];
		build(1,1,n);
		for(int i=0;i<m;i++)
		{
			
		}
	}	
	return 0;
} 
