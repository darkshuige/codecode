#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=200005;
int mod;
struct node
{
	int l,r;
	int maxn,remaxn;
	int mnum,rnum;
}tr[maxn*4];
int w[maxn];
void pushup(node &root,node &left,node &right)
{
	if(left.maxn == right.maxn)
	{
        root.maxn = left.maxn;
        root.mnum = left.mnum + right.mnum;
        if(left.remaxn == right.remaxn)
		{
            root.remaxn = left.remaxn;
            root.rnum = left.rnum + right.rnum;
        }
        else if(left.remaxn > right.remaxn)
		{
            root.remaxn = left.remaxn;
            root.rnum = left.rnum;
        }
        else if(left.remaxn < right.remaxn)
		{
            root.remaxn = right.remaxn;
            root.rnum = right.rnum;
        }
    }
    else if(left.maxn > right.maxn)
	{
        root.maxn = left.maxn;
        root.mnum = left.mnum;
        if(left.remaxn == right.maxn)
		{
            root.remaxn = left.remaxn;
            root.rnum = left.rnum + right.mnum;
        }
        else if(left.remaxn > right.maxn)
		{
            root.remaxn = left.remaxn;
            root.rnum = left.rnum;
        }
        else if(left.remaxn < right.maxn)
		{
            root.remaxn = right.maxn;
            root.rnum = right.mnum;
        }
    }
    else if(left.maxn < right.maxn)
	{
        root.maxn = right.maxn;
        root.mnum = right.mnum;
        if(left.maxn == right.remaxn)
		{
            root.remaxn = left.maxn;
            root.rnum = left.mnum + right.rnum;
        }
        else if(left.maxn > right.remaxn)
		{
            root.remaxn = left.maxn;
            root.rnum = left.mnum;
        }
        else if(left.maxn < right.remaxn)
		{
            root.remaxn = right.remaxn;
            root.rnum = right.rnum;
        }
    }
}
void build(int p,int l,int r)
{
	tr[p]={l,r,w[l],0,1,0};
	if(l==r) return ;
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(tr[p],tr[lc],tr[rc]);
}
void update(int p,int pos,int x)
{
	if(tr[p].l==tr[p].r && tr[p].l==pos)
	 tr[p].maxn=x;
	else
	{
		int mid=tr[p].l+tr[p].r>>1;
		if(pos<=mid) update(lc,pos,x);
		else update(rc,pos,x);
		pushup(tr[p],tr[lc],tr[rc]);
	}	
}
node query(int p,int l,int r)
{
	if(tr[p].l>=l && tr[p].r<=r) return tr[p];
	else
	{
		int mid=tr[p].l+tr[p].r>>1;
		node a,b;
		int f1=0,f2=0;
		if(l<=mid)
		{
			f1++;
			a=query(lc,l,r);
		}
		if(r>mid)
		{
			f2++;
			b=query(rc,l,r);
		}
		if(f1 && f2)
		{
			node c={l,r};
			pushup(c,a,b);
			return c;
		}
		else
		{
			if(f1) return a;
			if(f2) return b;
		}
	}
}
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>w[i];
	build(1,1,n);
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int b,c;
			cin>>b>>c;
			update(1,b,c);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			cout<<query(1,l,r).rnum<<endl;
		}
	}
	return 0;
} 
