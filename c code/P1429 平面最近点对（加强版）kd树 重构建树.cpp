#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
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
int n,K,root,cur,op;
int x1,x2,yy,y2,ans;
struct node
{
	int l,r;
	int v[2],w;
	int L[2],U[2];
	int siz,sum;
}t[maxn];
void pushup(int p)
{
	t[p].siz=t[lc].siz+t[rc].siz+1;
	t[p].sum=t[lc].sum+t[rc].sum+t[p].w;
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
int query(int p)
{
	if(!p || x2<t[p].L[0] || x1>t[p].U[0] || y2<t[p].L[1] || yy>t[p].U[1])
	 return 0;
	if(x1<=t[p].L[0] && x2>=t[p].U[0] && yy<=t[p].L[1] && y2>=t[p].U[1])
	 return t[p].sum;
	int res=0;
	if(x1<=t[p].v[0]&&t[p].v[0]<=x2&&   //部分覆盖
     yy<=t[p].v[1]&&t[p].v[1]<=y2) res+=t[p].w;
  	return query(lc)+query(rc)+res;
}
signed main()
{
	jiasu;
	int n; cin>>n;
	while(cin>>op)
	{
		if(op==3) break;
		if(op==1)
		{
			cur++;
			cin>>t[cur].v[0]>>t[cur].v[1]>>t[cur].w;
			t[cur].v[0]^=ans; t[cur].v[1]^=ans; t[cur].w^=ans;
			insert(root,0);
		}
		else if(op==2)
		{
			cin>>x1>>yy>>x2>>y2;
			x1^=ans; yy^=ans; x2^=ans; y2^=ans;
      		cout<<query(root)<<endl;
      		ans=query(root);
		}
	}
	return 0;
}