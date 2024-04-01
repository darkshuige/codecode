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
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=100005;
struct node
{
	int l,r,sum;
}tr[maxn*4];
int w[maxn];
void pushup(int p)
{
	tr[p].sum=tr[lc].sum+tr[rc].sum;
}
void build(int p,int l,int r)//p是根节点，l表示左边界，r是又边界 
{
	node op;
	tr[p]={l,r,w[l]};
	if(l==r)//是叶子结点就返回 
	 return ;
	int mid=l+r>>1;//不是就裂开 
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(p);
}
void update(int p,int x,int y)
{
	if(tr[p].r-tr[p].l+1==tr[p].sum) return ;
	if(tr[p].l==tr[p].r)
	{
		tr[p].sum=(int)sqrt(tr[p].sum);
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x,y);
	if(y>m) update(rc,x,y);
	pushup(p);
}
int query(int p,int x,int y)
{
	if(x<=tr[p].l && y>=tr[p].r)//如果全部包含 
	 return tr[p].sum;
	int m=tr[p].l+tr[p].r>>1;
	int sum=0;
	if(x<=m)
	 sum+=query(lc,x,y);
	if(y>m)
	 sum+=query(rc,x,y);//注意是y>m的时候 
	return sum;
}
signed main()
{
	jiasu;
	int n,m;
	int cnt=1;
	while(cin>>n)
	{
		cout<<"Case #"<<cnt<<":"<<endl; cnt++;
		for(int i=1;i<=n;i++) cin>>w[i];
		build(1,1,n);
		cin>>m;
		while(m--)
		{
			int op,a,b;
			cin>>op>>a>>b;
			if(a>=b) swap(a,b);
			if(op==1)
			 cout<<query(1,a,b)<<endl;
			else
			 update(1,a,b);
		}
	}
	return 0;
} 
