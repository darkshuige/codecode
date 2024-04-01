#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define lc(x) tr[x].l
#define rc(x) tr[x].r
using namespace std;
const int maxn=200010;
struct node
{
	int l,r,s;//左右边界和多少个数 
}tr[maxn*20];
int root[maxn],idx=0;//root用来存存入第几个数时的树idx加点
int n,m,a[maxn];
vector<int>b;//用来离散化
void build(int &x,int l,int r)//引用，递归赋值 
{	
	x=++idx;
	if(l==r) return ;
	int m=l+r>>1;
	build(lc(x),l,m);//给lc(x)赋值顺便 
	build(rc(x),m+1,r);
}
void insert(int x,int &y,int l,int r,int k)//x表示的是上一层的树，y表示当前，也是和build手法一样 
{
	y=++idx; tr[y]=tr[x]; tr[y].s++;//y和x的差别就是y多了一个insert进去的数
	if(l==r) return ;
	int m=l+r>>1;
	if(k<=m) insert(lc(x),lc(y),l,m,k);//lc(x)是存在的，rc(x)还没，进去之后才给rcx赋值 
	else insert(rc(x),rc(y),m+1,r,k); 
}
int query(int x,int y,int l,int r,int k)//x是之前的root y是现在的，l r是值域，k是第几个 
{
	if(l==r) return l;
	int m=l+r>>1;
	int s=tr[lc(y)].s-tr[lc(x)].s;
	if(k<=s) return query(lc(x),lc(y),l,m,k);//往左边找
	else return query(rc(x),rc(y),m+1,r,k-s);//网友边找，要减去左边的个数 
}
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b.push_back(a[i]);
	}
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	int bn=b.size();//离散三部曲，排序去重 二分查找 之后就用1到 bn来操作
	build(root[0],1,bn);
	for(int i=1;i<=n;i++)
	{
		int id=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;//+1是因为在b里面是从0开始的所以+1
		insert(root[i-1],root[i],1,bn,id);
	}
	while(m--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		int id=query(root[l-1],root[r],1,bn,k);//l-1到r 前缀和思想 
		cout<<b[id-1]<<endl;//这里要-1是因为之前+了1； 
	}
	return 0;
}
