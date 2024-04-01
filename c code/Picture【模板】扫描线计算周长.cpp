#include <iostream>
#include <cstdio>
#include <algorithm>
#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
#include<iomanip>
#include<string>
#include<stack>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1 | 1
using namespace std;
const int maxn=200005;
int x[maxn];//l用来放线段，x用来放点 
struct line
{
	int x1,x2,y;
	int tag; //入变+1，出边-1 
}L[maxn];
int cmp(line a,line b)
{
	return a.y<b.y;
}
struct node
{
	int l,r,cnt,len,num,ll,rr;//num表示有几个不重复的线段，用来算y的个数 
}tr[maxn*8];                  //ll rr标记这个节点的左右两个端点是否被覆盖
void build(int p,int x,int y)
{
	tr[p]={x,y,0,0,0,0};
	if(x==y) return ;
	int m=x+y>>1;
	build(lc,x,m);build(rc,m+1,y);
}
void pushup(int p)
{
	if(tr[p].cnt>0) //被覆盖了
	{
		tr[p].len=x[tr[p].r+1]-x[tr[p].l];//传参的时候r向右边偏移一个
		tr[p].num=tr[p].ll=tr[p].rr=1;
	}
	else 
	{
		tr[p].len=tr[lc].len+tr[rc].len;
		tr[p].ll=tr[lc].ll; tr[p].rr=tr[rc].rr;
		tr[p].num=tr[lc].num+tr[rc].num-(tr[lc].rr & tr[rc].ll);//全1出1 
	}
}
void update(int p,int x,int y,int k)
{
	if(x<=tr[p].l && y>=tr[p].r)
	{
		tr[p].cnt+=k;
		pushup(p);
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x,y,k);
	if(y>m) update(rc,x,y,k);
	pushup(p);
}
signed main()
{
	jiasu;
	int n,x1,x2,y1,y2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		L[i]={x1,x2,y1,+1};//入编 
		L[i+n]={x1,x2,y2,-1};//出边
		x[i]=x1;x[i+n]=x2;//x反正用来去重的离散的后面用x当操作数 
	}
	n*=2;
	sort(L+1,L+n+1,cmp);
	sort(x+1,x+n+1);//离散三部曲，排序、去重、二分查找下标
	int s=unique(x+1,x+n+1)-x-1;//unique去重返-x回最后一位的下标， -1因为从1开始
	build(1,1,s-1);
	int ans=0,last=0;
	for(int i=1;i<=n;i++)//只用找n-1条边就可以算出面积
	{
		int l=lower_bound(x+1,x+1+s,L[i].x1)-x;
		int r=lower_bound(x+1,x+1+s,L[i].x2)-x;
		update(1,l,r-1,L[i].tag);//update的时候r向左边偏移一位，传参的时候r向右边偏移一位不然中间会有漏洞这样就连在一起了
		ans+=abs(tr[1].len-last)+2*(L[i+1].y-L[i].y)*tr[1].num;
		last=tr[1].len;
	} 
	cout<<ans<<endl;
	return 0;
} 
