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
const double A=0.7;
int g[maxn],cnt;
double ans=2e18;
int n,K,root,cur;
struct node
{
	int l,r;
	double v[2];
	double L[2],U[2];
	int siz;
}t[maxn];
void pushup(int p)
{
	t[p].siz=t[lc].siz+t[rc].siz+1;
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
bool cmp(int a,int b)
{
	return t[a].v[K]<t[b].v[K];
}
int rebuild(int l,int r,int k)
{
	if(l>r) return 0;
	int m=l+r>>1;
	K=k; nth_element(g+l,g+m,g+r+1,cmp);
	t[g[m]].l=rebuild(l,m-1,k^1);
	t[g[m]].r=rebuild(m+1,r,k^1);
	pushup(g[m]);
	return g[m];
}
void dfs(int p)
{
	if(!p) return ;
	g[++cnt]=p;
	dfs(lc);
	dfs(rc);
}
void check(int &p,int k)
{
	if(A*t[p].siz<max(t[lc].siz,t[rc].siz))
	{
		cnt=0;
		dfs(p);
		p=rebuild(1,cnt,k);
	}
}
void insert(int &p,int k)
{
	if(!p)
	{
		p=cur;
		pushup(p);
		return ;
	}
	insert(t[cur].v[k]<=t[p].v[k]?lc:rc,k^1);
	pushup(p);
	check(p,k);
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
void query(int p)
{
	if(!p) return ;
	if(p!=cur) ans=min(ans,dis(p));
	double dl=dis2(lc),dr=dis2(rc);
	if(dl<dr)
	{
		if(dl<ans) query(lc);
		if(dr<ans) query(rc);
	}
	else
	{
		if(dr<ans) query(rc);
		if(dl<ans) query(lc);
	}
}
signed main()
{
	jiasu;
	int n; cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>t[i].v[0]>>t[i].v[1];
	for(cur=1;cur<=n;cur++) insert(root,0);
	for(cur=1;cur<=n;cur++)
	 query(root);
	cout<<fixed<<setprecision(4)<<sqrt(ans)<<endl;
	return 0;
}