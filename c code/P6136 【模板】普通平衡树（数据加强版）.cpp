#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
using namespace std;
const int maxn=1100050,INF=(1<<30)+1;;
int root,idx;
struct node
{
	int p,v,cnt,siz,s[2];
	void init(int p1,int v1)
	{
		p=p1;
		v=v1;
		cnt=siz=1;
	}
}tr[maxn];
void push(int x)
{
	tr[x].siz=tr[tr[x].s[0]].siz+tr[tr[x].s[1]].siz+tr[x].cnt;
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
	push(y);push(x);//从下往上push 
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
void find(int v)//查找v 所在的节点 
{
	int x=root;//从root开始找;
	while(tr[x].s[v>tr[x].v] && v!=tr[x].v)//继续往下走不是空并且不等于v 
	{
		x=tr[x].s[v>tr[x].v];//继续往下走，要是v比x.v大那么往右边走 
	}
	splay(x,0);//找到之后，x就在v所在的点，直接拿到根节点 
}
void insert(int v)
{
	int x=root,p=0;//p指向父节点
	while(x && tr[x].v!=v)//往下找，直到找到或者走到空位 
	{
		p=x;
		x=tr[x].s[v>tr[x].v];
	}
	if(x)//找到了,说明有出现过了 
	{
		tr[x].cnt++;
	}
	else// 没出现过，走到空位了，插入 
	{
		x=++idx;
		tr[p].s[v>tr[p].v]=x;
		tr[x].init(p,v);
	}
	splay(x,0);
}
int get_pre(int v){ //前驱
  find(v);
  int x=root;
  if(tr[x].v<v) return x;
  x=ls(x);
  while(rs(x)) x=rs(x);
  splay(x, 0);
  return x;
}
int get_suc(int v){ //后继
  find(v);
  int x=root;
  if(tr[x].v>v) return x;
  x=rs(x);
  while(ls(x)) x=ls(x);
  splay(x, 0);
  return x;
}
void del(int v)//删除v这个是所在的点 
{
	int pre=get_pre(v);
	int suc=get_suc(v);
	splay(pre,0);
	splay(suc,pre);//把v值所在的点移到叶子结点上面 
	int del=tr[suc].s[0];//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if(tr[del].cnt>1)//要是数量多那就减一个数量，不影响 
	{
		tr[del].cnt--;
		splay(del,0);//为了更新上面的数值;	
	}
	else
	{
		tr[suc].s[0]=0;//s默认为0，为0表示空 
		splay(suc,0);
	}
}

int get_rank(int v)//找到v值的排名//要是没有v要先插入v 
{
	insert(v);
	int res=tr[tr[root].s[0]].siz;
	del(v);
	return res;
}
int get_val(int k)//查询排名为k的值 
{
	int x=root;
	while(1)
	{
		int y=tr[x].s[0];
		if(tr[y].siz+tr[x].cnt<k)//还得往右边找 //左子树加自己 
		{
			k-=tr[y].siz+tr[x].cnt;
			x=tr[x].s[1];
		}
		else if(tr[y].siz>=k)//往左边走 
		{
			x=y;
		}
		else
		{
			break;
		}
	}
	splay(x,0);
	return tr[x].v;
}
signed main()
{
	jiasu;
	insert(-INF);
	insert(INF);
	int n,m;
	int x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		insert(x);
	}
	int last=0,res=0;
	for(int i=0;i<m;i++)
	{
		int op;
		cin>>op;
		cin>>x;
		x^=last;
		if(op==1) insert(x);
		if(op==2) del(x);
		if(op==3) res^=(last=get_rank(x));
	    if(op==4) res^=(last=get_val(x+1));
	    if(op==5) res^=(last=tr[get_pre(x)].v);
	    if(op==6) res^=(last=tr[get_suc(x)].v);
	}
	cout<<res<<endl;
	return 0;
}
