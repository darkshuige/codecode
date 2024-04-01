#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=50005;
int ll,rr;
struct node
{
	int l,r,sum,lazy;
}tr[maxn*4];
int w[maxn];
void pushup(int p)
{
	tr[p].sum=tr[lc].sum+tr[rc].sum;
}
void build(int p,int l,int r)//p是根节点，l表示左边界，r是又边界 
{
	tr[p]={l,r,r-l+1,-1};
	if(l==r)//是叶子结点就返回 
	 return ;
	int mid=l+r>>1;//不是就裂开 
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(p);
}
void pushdown(int p)
{
	if(tr[p].lazy!=-1)
	{
		tr[lc].sum=(1-tr[p].lazy)*(tr[lc].r-tr[lc].l+1);
		tr[rc].sum=(1-tr[p].lazy)*(tr[rc].r-tr[rc].l+1);
		tr[lc].lazy=tr[rc].lazy=tr[p].lazy;	
	}
	tr[p].lazy=-1;
}
int findleft(int p)
{
	if(tr[p].l==tr[p].r) return tr[p].l;
	pushdown(p);
	if(tr[lc].sum) return findleft(lc);
	if(tr[rc].sum) return findleft(rc); 
}
int findright(int p)
{
	if(tr[p].l==tr[p].r) return tr[p].l;
	pushdown(p);
	if(tr[rc].sum) return findright(rc);
	if(tr[lc].sum) return findright(lc);
}
void update(int p,int x,int y,int &k)
{
	if(!k || !tr[p].sum) return ;
	if(x<=tr[p].l && y>=tr[p].r)
	{
		if(tr[p].sum<=k)
		{
			ll=min(ll,findleft(p));rr=max(rr,findright(p));
			k-=tr[p].sum;
			tr[p].sum=0;
			tr[p].lazy=1;
			return ;
		}
		if(tr[p].l==tr[p].r) return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(x<=m) update(lc,x,y,k);
	if(y>m) update(rc,x,y,k);
	pushup(p);
}
int query(int p,int x,int y)
{
	if(x<=tr[p].l && y>=tr[p].r)
	{
		tr[p].lazy=0;
		int num=tr[p].r-tr[p].l+1-tr[p].sum;
		tr[p].sum=tr[p].r-tr[p].l+1;
		return num;
	}
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	int sum=0;
	if(x<=m) sum+=query(lc,x,y);
	if(y>m) sum+=query(rc,x,y);
	pushup(p);
	return sum;
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		build(1,1,n);
		while(m--)
		{
			int op,a,b;
			cin>>op>>a>>b;
			if(op==1)
			{
				ll=n;rr=0;
				int temp=b;
				update(1,a+1,n,temp);
				if(temp!=b)
				 cout<<ll-1<<" "<<rr-1<<endl;
				else
				 cout<<"Can not put any one."<<endl;
			}
			else
			{
				cout<<query(1,a+1,b+1)<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
} 
