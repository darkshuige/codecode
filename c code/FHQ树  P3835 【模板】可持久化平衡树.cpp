#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
using namespace std;
const int maxn=500005;
struct node
{
	int l,r;//儿子
	int val,rnd;//权值 随机数
	int size;
}tr[maxn*50];
int root[maxn],idx;
void newnode(int &x,int v)//编号，值
{
	x=++idx;
	tr[x].val=v;
	tr[x].rnd=rand();
	tr[x].size=1;
}
void pushup(int p)
{
	tr[p].size=tr[tr[p].l].size+tr[tr[p].r].size+1;
}
void split(int p,int v,int &x,int &y)//递归
{
	if(!p)
	{
		x=y=0;
		return ;
	}
	if(tr[p].val<=v)//小于等于
	{
		x=++idx; tr[x]=tr[p];
		split(tr[x].r,v,tr[x].r,y);//左边为根
		pushup(x);
	}
	else
	{
		y=++idx; tr[y]=tr[p];
		split(tr[y].l,v,x,tr[y].l);//有边为根
		pushup(y);
	}
}
int merge(int x,int y)//递归
{
	if(!x || !y) return x+y; //有0的时候
	if(tr[x].rnd<tr[y].rnd)//谁小谁在上面
	{
		tr[x].r=merge(tr[x].r,y);
		pushup(x); return x;
	}
	else
	{
		tr[y].l=merge(x,tr[y].l);
		pushup(y); return y;
	}
}
void insert(int &root,int v)
{
	int x,y,z;
	split(root,v,x,y);
	newnode(z,v);
	root=merge(merge(x,z),y);
}
void del(int &root,int v)
{
	int x,y,z;
	split(root,v,x,z);
	split(x,v-1,x,y);//y里装的都是v
	y=merge(tr[y].l,tr[y].r);
	root=merge(merge(x,y),z);
}
int getrank(int &root,int v)
{
	int x,y;
	split(root,v-1,x,y);
	int ans=tr[x].size+1;
	root=merge(x,y);
	return ans;
}
int getval(int root,int v)
{
	if(v==tr[tr[root].l].size+1)
	 return tr[root].val;
	else if(v<=tr[tr[root].l].size)
	 return getval(tr[root].l,v);
	else
	 return getval(tr[root].r,v-tr[tr[root].l].size-1);
}
int getpre(int &root,int v)
{
	int x,y,ans;
	split(root,v-1,x,y);
	if(!x) return -2147483647;
	int s=tr[x].size;
	ans=getval(x,s);
	root=merge(x,y);
	return ans;
}
int getnxt(int &root,int v)
{
	int x,y,ans;
	split(root,v,x,y);
	if(!y) return 2147483647;
	ans=getval(y,1);
	root=merge(x,y);
	return ans;
}	
signed main()
{
	int n,ver,op,v;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ver>>op>>v;
		root[i]=root[ver];
		if(op==1)insert(root[i],v);
	    else if(op==2)del(root[i],v);
	    else if(op==3)printf("%d\n",getrank(root[i],v));
	    else if(op==4)printf("%d\n",getval(root[i],v));
	    else if(op==5)printf("%d\n",getpre(root[i],v));
	    else printf("%d\n",getnxt(root[i],v));
	}
	return 0;
}
