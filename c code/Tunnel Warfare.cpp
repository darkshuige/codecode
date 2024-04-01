#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1 | 1
using namespace std;
const int maxn=50005;
struct node
{
	int l,r,lmax,rmax;
}tr[maxn*4];
void pushup(node &fa, node &ls, node &rs)
{
	fa.lmax=ls.lmax+(ls.lmax==ls.r-ls.l+1?rs.lmax:0);//�������������max==��������ȫ�����Ǹ��ڵ��lmax�������ȫ�����ұߵ�lmax
	fa.rmax=rs.rmax+(rs.rmax==rs.r-rs.l+1?ls.rmax:0);
}
void pushup(int p)
{
	pushup(tr[p],tr[lc],tr[rc]);
}
void build(int p,int l,int r)
{
	tr[p]={l,r,1,1};
	if(l==r) return ;
	int mid=l+r>>1;
	build(lc,l,mid);build(rc,mid+1,r);
	pushup(p);
}
int query(int p,int x)
{
	if(tr[p].l==tr[p].r) return tr[p].lmax;
	int mid=tr[p].l+tr[p].r>>1;
	node ls=tr[lc],rs=tr[rc];//������������
	if(x<=mid) //����ҵĵ��������� 
	{
		if((ls.r-x)<ls.rmax)//���x��rmaxn�ķ�Χ���棬��ô��Χ��ߵ�rmax+�ұߵ�lmax 
		{
			return ls.rmax+rs.lmax;
		}
		else
		{
			return query(lc,x);//�������������ô���������	
		} 
	}
	else
	{
		if((x-rs.l)<rs.lmax)
		{
			return rs.lmax+ls.rmax;
		}
		else
		{
			return query(rc,x);
		}
	}
	
}
void update(int p,int x,int k)
{
	if(tr[p].l==tr[p].r)
	{
		tr[p].lmax=tr[p].rmax=k;
		return ;
	}
	int mid=tr[p].l+tr[p].r>>1;
	if(x<=mid) update(lc,x,k);
	else update(rc,x,k);
	pushup(p);
}
signed main()
{
	int n,m;
	while(cin>>n>>m)
	{
		stack<int>last;
		build(1,1,n);
		while(m--)
		{
			char op;
			cin>>op;
			if(op=='D')
			{
				int x;
				cin>>x;
				update(1,x,0);
				last.push(x); 
			}
			else if(op=='Q')
			{
				int x;
				cin>>x;
				cout<<query(1,x)<<endl;
			}
			else
			{
				update(1,last.top(),1);
				last.pop();
			}
		}
	}
	return 0;
}
