#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define lc t[p].l
#define rc t[p].r
#define INF 2147483647
using namespace std;
const int maxn=200005;
double ans=-2e18,ans1,ans2;
int n,K,root,cur;
struct node
{
	int l,r;
	double v[2];
	double L[2],U[2];
	bool operator<(const node &b) const{return v[K]<b.v[K];}
}t[maxn];
void pushup(int p)
{
	for(int i=0;i<=1;i++)
	{
		t[p].L[i]=t[p].U[i]=t[p].v[i];
		if(lc)
		{
			t[p].L[i]=min(t[p].L[i],t[lc].L[i]);
			t[p].U[i]=max(t[p].U[i],t[lc].U[i]);
		}
		if(rc)
		{
			t[p].L[i]=min(t[p].L[i],t[rc].L[i]);
			t[p].U[i]=max(t[p].U[i],t[rc].U[i]);
		}
	}
}
int build(int l,int r,int k)
{
	if(l>r) return 0;
	int m=(l+r)>>1;
	K=k; nth_element(t+l,t+m,t+r+1);
	t[m].l=build(l,m-1,k^1);
	t[m].r=build(m+1,r,k^1);
	pushup(m);
	return m;
}
double sq(double x) {return x*x;}
double dis(int p)
{
	double s=0;
	for(int i=0;i<=1;i++)
	 s+=sq(t[cur].v[i]-t[p].v[i]);
	return s;
}
double dis2(int p)
{
	if(!p) return 2e18;
	double s=0;
	for(int i=0;i<=1;i++)
	{
		s+=sq(max(0.0,t[cur].v[i]-t[p].U[i]))+
			sq(max(0.0,t[p].L[i]-t[cur].v[i]));
	}
	return s;
}
double dis3(int p)
{
	if(!p) return 0;
	double s=0;
	for(int i=0;i<=1;i++)
	{
		s+=sq(max(t[p].U[i]-t[cur].v[i],
		          t[cur].v[i]-t[p].L[i]));
	}
	return s;
}
void query(int p)
{
	if(!p) return ;
	if(p!=cur) ans1=min(ans1,dis(p));
	double dl=dis2(lc),dr=dis2(rc);
	if(dl<dr)
	{
		if(dl<ans1) query(lc);
		if(dr<ans1) query(rc);
	}
	else
	{
		if(dr<ans1) query(rc);
		if(dl<ans1) query(lc);
	}
}
void query2(int p)
{
	if(!p) return ;
	if(p!=cur) ans2=max(ans2,dis(p));
	double dl=dis3(lc),dr=dis3(rc);
	if(dl>dr)
	{
		if(dl>ans2) query2(lc);
		if(dr>ans2) query2(rc);
	}
	else
	{
		if(dr>ans2) query2(rc);
		if(dl>ans2) query2(lc);
	}
}
signed main()
{
	jiasu;
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>t[i].v[0]>>t[i].v[1];
	root=build(1,n,0);
	ans1=2e18,ans2=0;
	for(cur=1;cur<=n;cur++)
	{
		query(root);
		query2(root);
	}
	cout<<fixed<<setprecision(2)<<sqrt(ans1)<<" "<<sqrt(ans2)<<endl;
	return 0;
}