#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fa(x) tr[x].p
#define lc(x) tr[x].s[0]
#define rc(x) tr[x].s[1]
#define notroot(x) lc(fa(x))==x||rc(fa(x))==x  //判断x点是否不是平衡树的跟节点，如果是根节点父亲节点的儿子不是自己 
using namespace std;
const int maxn=100010;
int n,m;
struct node
{
	int s[2],p,v,sum;
	int lazy;//翻转标记 
}tr[maxn];
void pushup(int x)
{
	tr[x].sum=tr[lc(x)].sum^tr[rc(x)].sum^tr[x].v;
}
void pushdown(int x)
{
	if(tr[x].lazy)
	{
		swap(lc(x),rc(x));
		tr[lc(x)].lazy^=1;
		tr[rc(x)].lazy^=1;
		tr[x].lazy=0;
	}
}
void rotate(int x)//把x转上去 
{
	int y=fa(x);int z=fa(y);
	int k=rc(y)==x;//0 或 1 看x是不是根节点
	if(notroot(y))
	 tr[z].s[rc(z)==y]=x; //这个调到前面来
	fa(x)=z;//认爹不认儿
	tr[y].s[k]=tr[x].s[k^1];
	fa(tr[x].s[k^1])=y;
	tr[x].s[k^1]=y;
	fa(y)=x;
	pushup(y),pushup(x);
}
void pushall(int x)//找根节点然后全部push下来也就是把到x为止的翻转搞好 
{
	if(notroot(x)) pushall(fa(x));
	pushdown(x);
}
void splay(int x)//伸展，比起普通平衡树少了一个参数 把x转到当前平衡树的根节点 
{
	pushall(x);
	while(notroot(x))
	{
		int y=fa(x);int z=fa(y);
		if(notroot(y))
		 (rc(y)==x)^(rc(z)==y) ? rotate(x):rotate(y);
		rotate(x);
	}
}
void access(int x)//把x到最跟的根节点打通 连实线，自下往上 
{
	for(int y=0;x;)//x=0时结束 
	{
		splay(x);
		rc(x)=y;
		pushup(x);
		y=x,x=fa(x);//跳到上面那个平衡树 
	}
}
void makeroot(int x)//换根 
{
	access(x);//打通路 
	splay(x);//把x换到最上面 
	tr[x].lazy^=1;//翻转 
}
void split(int x,int y)//把从x到y的路径分离出来 把路径变成一条实链，把y转到根 
{
	makeroot(x);//先把x换到根
	access(y);//打通y
	splay(y);//把y换到根 
}
void output(int x,int y)
{
	split(x,y);
	cout<<tr[y].sum<<endl;
}
int findroot(int x)//找跟，先把x拉到最上面，那原来的跟就在最左下脚 
{
	access(x);
	splay(x);
	while(lc(x))
	 pushdown(x),x=lc(x);
	splay(x);//防止卡链 
	return x;
}
void link(int x,int y)//连边
{
	makeroot(x);//先把x换成根
	if(findroot(y)!=x) fa(x)=y;//如果不在同一棵树上	
}
void cut(int x,int y) //断边
{
	makeroot(x);//先把x换成根 
	if(findroot(y)==x && fa(y)==x && !lc(y))//如果y的根是x并且x和y严格相连才能断 
	{
		fa(y)=0;
		pushup(x);
	}
}
void change(int x,int y)
{
	splay(x);
	tr[x].v=y;
	pushup(x);
}
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>tr[i].v;
	while(m--)
	{
		int op,a,b;
		cin>>op>>a>>b;
		if(op==0)
		 output(a,b);
		else if(op==1)
		 link(a,b);
		else if(op==2)
		 cut(a,b);
		else
		 change(a,b);
	}
	return 0;
}
