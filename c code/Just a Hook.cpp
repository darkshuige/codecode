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
	int l,r,sum,k;
}tr[maxn*4];
int w[maxn];
void pushup(int p)
{
	tr[p].sum=tr[lc].sum+tr[rc].sum;
}
void pushdown(int p)
{
	if(tr[p].k==0) return ;
	tr[lc].sum=tr[p].k*(tr[lc].r-tr[lc].l+1);
	tr[rc].sum=tr[p].k*(tr[rc].r-tr[rc].l+1);
	tr[lc].k=tr[rc].k=tr[p].k;
	tr[p].k=0;
}
void build(int p,int l,int r)//p是根节点，l表示左边界，r是又边界 
{
	tr[p]={l,r,w[l],1};
	if(l==r)//是叶子结点就返回 
	 return ;
	int mid=l+r>>1;//不是就裂开 
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(p);
}
void update(int p,int x,int y,int k)
{
	if(x<=tr[p].l && y>=tr[p].r)
	{
		tr[p].sum=k*(tr[p].r-tr[p].l+1);
		tr[p].k=k;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);
	if(x<=m)
	 update(lc,x,y,k);
	if(y>m)//注意是y>m 
	 update(rc,x,y,k);
	pushup(p);
}
signed main()
{
	jiasu;
	int t;
	cin>>t;
	for(int cnt=1;cnt<=t;cnt++)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) w[i]=1;
		build(1,1,n);
		int m;
		cin>>m;
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			update(1,a,b,c);
		}
		cout<<"Case "<<cnt<<": The total value of the hook is "<<tr[1].sum<<"."<<endl;
	}
	return 0;
} 
