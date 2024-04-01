#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1 | 1
using namespace std;
const int maxn=200005;
int x[maxn];//l�������߶Σ�x�����ŵ� 
struct line
{
	int x1,x2,y;
	int tag; //���+1������-1 
}L[maxn];
int cmp(line a,line b)
{
	return a.y<b.y;
}
struct node
{
	int l,r,mama;	
}tr[maxn*8];
void pushup(int p)
{
	tr[p].mama=max(max(tr[lc].mama,tr[rc].mama),tr[p].mama);
}
void build(int p,int x,int y)
{
	tr[p]={x,y,0};
	if(x==y) return ;
	int m=x+y>>1;
	build(lc,x,m);build(rc,m+1,y);
	pushup(p);
}
void update(int p,int x,int y,int k)
{
	if(x<=tr[p].l && y>=tr[p].r)
	{
		tr[p].mama+=k;
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
	int n,x1,x2,y1,y2,d,w;
	cin>>n>>d>>w;
	for(int i=1;i<=n;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		x1=t1,x2=t1+w-1,y1=t2,y2=t2+d-1;
		L[i]={x1,x2,y1,+1};//��� 
		L[i+n]={x1,x2,y2,-1};//����
		x[i]=x1;x[i+n]=x2;//x��������ȥ�ص���ɢ�ĺ�����x�������� 
	}
	n*=2;
	sort(L+1,L+n+1,cmp);
	sort(x+1,x+n+1);//��ɢ������������ȥ�ء����ֲ����±�
	int s=unique(x+1,x+n+1)-x-1;//uniqueȥ�ط�-x�����һλ���±꣬ -1��Ϊ��1��ʼ
	build(1,1,s-1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=lower_bound(x+1,x+1+s,L[i].x1)-x;
		int r=lower_bound(x+1,x+1+s,L[i].x2)-x;
		update(1,l,r-1,L[i].tag);//update��ʱ��r�����ƫ��һλ�����ε�ʱ��r���ұ�ƫ��һλ��Ȼ�м����©������������һ����
		ans=max(ans,tr[1].mama);
	} 
	cout<<ans<<endl;
	return 0;
} 
