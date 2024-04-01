#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1 | 1
using namespace std;
const int maxn=300050;
int x[maxn];//l用来放线段，x用来放点 
struct line
{
	int x1,x2,y;
	int tag; //入变+1，出边-1 
}L[maxn*2];
int cmp(line a,line b)
{
	return a.y<b.y;
}
struct node
{
	int l,r,mama,lazy;	
}tr[maxn*10];
void pushup(int p)
{
	tr[p].mama=max(tr[lc].mama,tr[rc].mama);
}
void pushdown(int p)
{
	if(tr[p].lazy!=0)
	{
		tr[lc].lazy+=tr[p].lazy;tr[rc].lazy+=tr[p].lazy;
		tr[lc].mama+=tr[p].lazy;tr[rc].mama+=tr[p].lazy;
		tr[p].lazy=0;
	}
}
void build(int p,int x,int y)
{
	tr[p]={x,y,0,0};
	if(x==y) return ;
	int m=x+y>>1;
	build(lc,x,m);build(rc,m+1,y);
	pushup(p);
}
void update(int p,int x,int y,int k)
{
	if(x<=tr[p].l && y>=tr[p].r)
	{
		tr[p].mama+=k;
		tr[p].lazy+=k;
		return ;
	}
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x,y,k);
	if(y>m) update(rc,x,y,k);
	pushup(p);
}
signed main()
{
	jiasu;
	int n,x1,x2,y1,y2,d,w;
	cin>>n>>d>>w;
	int up=0;
	for(int i=1;i<=n;i++)
	{
		int X,T;
		cin>>T>>X;
		x1=X,x2=X+w-1,y1=T,y2=T+d-1;
		L[i]={x1,x2,y1,+1};//入编 
		L[i+n]={x1,x2,y2,-1};//出边
		up=max(up,x2);
	}
	n*=2;
	sort(L+1,L+n+1,cmp);
	build(1,1,up);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		update(1,L[i].x1,L[i].x2,L[i].tag);
		ans=max(ans,tr[1].mama);
	} 
	cout<<ans<<endl;
	return 0;
} 
