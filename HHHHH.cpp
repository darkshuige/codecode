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
	int l,r,sum,add;
}tr[maxn*4];
int w[maxn];
void pushup(int p)
{
	tr[p].sum=tr[lc].sum+tr[rc].sum;
}
void pushdown(int p)
{
	auto &u=tr[p],&l=tr[lc],&r=tr[rc];
	if(u.add)
	{
		l.sum+=u.add*(l.r-l.l+1),
		r.sum+=u.add*(r.r-r.l+1),
		l.add+=u.add,
		r.add+=u.add,
		u.add=0;      
	}
}
void build(int p,int l,int r)
{
	tr[p]={l,r,w[l],0};
	if(l==r)//是叶子结点就返回 
	 return ;
	int mid=l+r>>1;//不是就裂开 
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(p);
}
void update(int p,int x,int y,int k)
{
	if(x<=tr[p].l && y>=tr[p].r)//覆盖则修改并且add欠着 
	{
		tr[p].sum+=k*(tr[p].r-tr[p].l+1);
		tr[p].add+=k;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);//第一次的时候不会但是后面可能就会 
	if(x<=m)
	 update(lc,x,y,k);
	if(y>m)//注意是y>m 
	 update(rc,x,y,k);
	pushup(p);
}
int query(int p,int x,int y)
{
	if(x<=tr[p].l && y>=tr[p].r)//如果全部包含 
	 return tr[p].sum;
	int m=tr[p].l+tr[p].r>>1;
	pushdown(p);//查成分的时候可能会去叶子结点，就得把钱还清 
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
	int t;
	cin>>t;
	while(t--)
	{
		memset(w,0,sizeof w);
		string s="#",k;
		cin>>k;
		s+=k;
		if(s[1]=='1')
		 w[1]=1;
		else
		 w[1]=2;
		int ans=w[1];
		for(int i=2;i<s.size();i++)
		{
			if(s[i]==s[i-1])
			 w[i]=w[i-1]+2;
			else
			 w[i]=w[i-1]+1;
			ans+=w[i];
		}
		build(1,1,s.size()-1);
		for(int i=2;i<s.size();i++)
		{
			if(!(s[i]=='0' && s[i-1]=='1'))
			 update(1,i,s.size()-1,-2);
			ans+=query(1,i,s.size()-1);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
