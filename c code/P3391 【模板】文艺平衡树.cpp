#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
using namespace std;
const int maxn=110005,INF=(1<<30)+1;;
int root,idx,n,m;
struct node
{
	int p,v,cnt,size,s[2],lazy;
	void init(int p1,int v1)
	{
		p=p1;
		v=v1;
		cnt=size=1;
	}
}tr[maxn];
void pushup(int x)
{
	tr[x].size=tr[tr[x].s[0]].size+tr[tr[x].s[1]].size+tr[x].cnt;
}
void pushdown(int x)
{
	if(tr[x].lazy)
	{
		swap(tr[x].s[0],tr[x].s[1]);
		tr[tr[x].s[0]].lazy^=1;
		tr[tr[x].s[1]].lazy^=1;
		tr[x].lazy=0;
	}
}
void rotate(int x)//把x转上去，一个函数转完左转右转 
{
	int y=tr[x].p,z=tr[y].p;
	int k=tr[y].s[1]==x;//如果x是右儿子，k=1,左儿子 k=0;
	tr[y].s[k]=tr[x].s[k^1];
	tr[tr[x].s[k^1]].p=y; //y
	tr[x].s[k^1]=y;
	tr[y].p=x;       //x;
	tr[z].s[tr[z].s[1]==y]=x;//如果y是右儿子那就是s[1]，反之s[2] 
	tr[x].p=z;
	pushup(y);pushup(x);//从下往上pushup 
}
void splay(int x,int k)//把x旋转到k的下面一个，判断三种旋转用哪种
{
	while(tr[x].p!=k)
	{
		int y=tr[x].p,z=tr[y].p;
		if(z!=k)//如果z==k就只用转一次 
		{
			(tr[y].s[0]==x)^(tr[z].s[0]==y)?rotate(x):rotate(y);//如果是1说明是折线，那么应该两次都转x，如果是0说明是直线那先转y 
		}
		rotate(x);
	}
	if(k==0) root=x;
} 
void insert(int v)
{
	int x=root,p=0;//p指向父节点
	while(x)//往下找走到空位 
	{
		p=x;
		x=tr[x].s[v>tr[x].v];
	}
	x=++idx;
	tr[p].s[v>tr[p].v]=x;
	tr[x].init(p,v);
	splay(x,0);
}
int get_k(int k)//返回第k个点的编号 
{
	int x=root;
	while(1)
	{
		pushdown(x);
		int y=tr[x].s[0];
		if(tr[y].size+tr[x].cnt<k)//还得往右边找 //左子树加自己 
		{
			k-=tr[y].size+tr[x].cnt;
			x=tr[x].s[1];
		}
		else if(tr[y].size>=k)//往左边走 
		{
			x=y;
		}
		else
		{
			return x;
		}
	}
}
void output(int x)//中序遍历
{
	pushdown(x);
	if(tr[x].s[0]) output(tr[x].s[0]);
	if(tr[x].v>=1 && tr[x].v<=n) cout<<tr[x].v<<" ";
	if(tr[x].s[1]) output(tr[x].s[1]);
} 
signed main()
{
	jiasu;
	insert(-INF);
	insert(INF);
	cin>>n>>m;
	for(int i=1;i<=n;i++) insert(i);
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		l=get_k(l);r=get_k(r+2);//要找到l-1 r+1的区间，因为有哨兵所以l r+2 和普通平衡树的del一个原理 
		splay(l,0);splay(r,l);
		tr[tr[r].s[0]].lazy^=1;
	}
	output(root);
	return 0;
}
