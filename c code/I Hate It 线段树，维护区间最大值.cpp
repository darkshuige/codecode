#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=200005;
struct node
{
	int l,r,sum;
}tr[maxn*4];
int w[maxn];
void pushup(int p)//维护的是最大值 
{
	tr[p].sum=max(tr[lc].sum,tr[rc].sum);
}
void build(int p,int l,int r)
{
	tr[p]={l,r,w[l]};//这个sum在这里不关键，是要通过pushup或者直接赋值的
	if(l==r) return ;//l==r的时候就等于w[l]，l r表示维护的是w数组中的位置，l=r那维护的就是w[l]的位置 
	int mid=l+r>>1;
	build(lc,l,mid);build(rc,mid+1,r);
	pushup(p);
}
int query(int p,int a,int b)
{
	if(tr[p].l>=a && tr[p].r<=b) return tr[p].sum;//包含
	int m=tr[p].l+tr[p].r>>1;
	int ans=0;
	if(a<=m) ans=max(ans,query(lc,a,b));
	if(b>m) ans=max(ans,query(rc,a,b));
	return ans; 
}
void update(int p,int a,int b)
{
	if(tr[p].l==tr[p].r && tr[p].l==a)
	{
		tr[p].sum=b;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(a<=m) update(lc,a,b);
	else update(rc,a,b);
	pushup(p);
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
			char c;
			int a,b;
			cin>>c>>a>>b;
			if(c=='Q')
			 cout<<query(1,a,b)<<endl;
			else if(c=='U')
			 update(1,a,b);
		}
	}	
	return 0;
} 
