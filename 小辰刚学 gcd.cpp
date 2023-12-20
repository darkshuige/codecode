#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ls u<<1
#define rs u<<1|1
const int N=500010;
typedef long long LL;
int n,m; LL a[N],b[N];
struct Tree
{ //线段树
  int l,r;
  LL sum,d; //差分序列的区间和,最大公约数
}tr[N*4];
LL gcd(LL a,LL b)
{
  return b ? gcd(b,a%b) : a;
}
void pushup(Tree &u,Tree l,Tree r)
{
  u.sum=l.sum+r.sum;
  u.d=gcd(l.d,r.d);
}
void build(int u,int l,int r)
{
  tr[u]={l,r,b[l],b[l]};
  if(l==r) return;
  int mid=l+r>>1;
  build(ls,l,mid);
  build(rs,mid+1,r);
  pushup(tr[u],tr[ls],tr[rs]);
}
void change(int u,int x,LL v)
{
  if(tr[u].l==tr[u].r)
  {
    tr[u].sum+=v; tr[u].d+=v;
    return;
  }
  int mid=tr[u].l+tr[u].r>>1;
  if(x<=mid) change(ls,x,v);
  else change(rs,x,v);
  pushup(tr[u],tr[ls],tr[rs]);
}
Tree query(int u,int l,int r)
{
  if(l<=tr[u].l && tr[u].r<=r) return tr[u];
  int mid=tr[u].l+tr[u].r>>1;
  if(r<=mid) return query(ls,l,r);
  if(l>mid) return query(rs,l,r);
  Tree T;
  pushup(T,query(ls,l,r),query(rs,l,r));
  return T;
}
int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) 
    scanf("%lld",&a[i]), b[i]=a[i]-a[i-1];
  build(1,1,n);
  while(m --)
  {
    char c[1]; int l,r; scanf("%d%d",&l,&r);
//    if(*c=='C')
//	{
//      LL v; scanf("%lld",&v); 
//      change(1,l,v);
//      if(r+1<=n) change(1,r+1,-v);
//    }
//    else
//	{
      Tree L, R={0,0,0,0};
      L=query(1,1,l);
      if(l+1<=r) R=query(1,l+1,r);
      printf("%lld\n",abs(gcd(L.sum, R.d)));
//    }
  }
  return 0;
}
