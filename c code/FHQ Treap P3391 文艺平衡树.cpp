#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
using namespace std;
const int maxn=100005;
int n,m;
struct node
{
	int l,r;//儿子
	int val,key;//权值 随机数
	int size;
	int tag;
}tr[maxn];
int root,idx;
int newnode(int v)//编号，值
{
	int x=++idx;
	tr[x].val=v;
	tr[x].key=rand();
	tr[x].size=1;
	return idx;
}
void pushup(int p)
{
	tr[p].size=tr[tr[p].l].size+tr[tr[p].r].size+1;
}
void pushdown(int p)
{
	if(!tr[p].tag) return ;
	swap(tr[p].l,tr[p].r);
	tr[tr[p].l].tag^=1;
	tr[tr[p].r].tag^=1;
	tr[p].tag=0;
}
void split(int p,int k,int &x,int &y)//递归
{
	if(!p)
	{
		x=y=0;
		return ;
	}
	pushdown(p);
	if(k>tr[tr[p].l].size)//往右边走
	{
		k-=tr[tr[p].l].size+1;
		x=p;
		split(tr[x].r,k,tr[x].r,y);//左边为根
	}
	else
	{
		y=p;
		split(tr[y].l,k,x,tr[y].l);//有边为根
	}
	pushup(p);
}
int merge(int x,int y)//递归
{
	if(!x || !y) return x+y; //有0的时候
	if(tr[x].key<tr[y].key)//谁小谁在上面
	{
		pushdown(x);
		tr[x].r=merge(tr[x].r,y);
		pushup(x); return x;
	}
	else
	{
		pushdown(y);
		tr[y].l=merge(x,tr[y].l);
		pushup(y); return y;
	}
}
void output(int p)
{
	if(!p) return ;
	pushdown(p);
	output(tr[p].l);
	cout<<tr[p].val<<" ";
	output(tr[p].r);
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 root=merge(root,newnode(i));
	for(int i=1;i<=m;i++)
	{
		int l,r,x,y,z;
		cin>>l>>r;
		split(root,r,x,z);//[1,r] [r+1,n];
		split(x,l-1,x,y); //[1,l-1] [l,r]
		tr[y].tag^=1;
		root=merge(merge(x,y),z);
	}
	output(root);
	return 0;
}
