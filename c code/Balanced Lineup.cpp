#include<iostream>
#include<set>
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int maxn=50005;
struct Node
{
    int l,r,ma,mi;
}tr[maxn<<4];
int w[maxn];
void pushup(int p)
{
	tr[p].ma=max(tr[lc].ma,tr[rc].ma);
	tr[p].mi=min(tr[lc].mi,tr[rc].mi);
}
void build(int p,int l,int r)
{
    tr[p]={l,r,w[l],w[l]};
    if(l==r) return;
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
}
int qu1(int p,int l,int r)
{
	if(l<=tr[p].l && r>=tr[p].r) return tr[p].ma;
	int m=tr[p].l+tr[p].r>>1;
	int ans=-1e9;
	if(l<=m) ans=max(ans,qu1(lc,l,r));
	if(r>m) ans=max(ans,qu1(rc,l,r));
	return ans;
}
int qu2(int p,int l,int r)
{
	if(l<=tr[p].l && r>=tr[p].r) return tr[p].mi;
	int m=tr[p].l+tr[p].r>>1;
	int ans=1e9;
	if(l<=m) ans=min(ans,qu2(lc,l,r));
	if(r>m) ans=min(ans,qu2(rc,l,r));
	return ans;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    build(1,1,n);
    while(m--)
    {
    	int a,b;
    	cin>>a>>b;
    	cout<<qu1(1,a,b)-qu2(1,a,b)<<endl;
	}
    return 0;
}
