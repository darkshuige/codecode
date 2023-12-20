#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=500005;
struct node
{
	int l,r,sum;
}tr[maxn*4];
int w[maxn];
void build(int p,int l,int r)
{
	tr[p]={l,r,w[l]};
	if(l==r)//��Ҷ�ӽ��ͷ��� 
	 return ;
	int mid=l+r>>1;//���Ǿ��ѿ� 
	build(lc,l,mid);
	build(rc,mid+1,r);
	tr[p].sum=tr[lc].sum+tr[rc].sum;//pushup 
}
void update(int p,int x,int k)
{
	if(tr[p].l==x && tr[p].r==x)//�ҵ�Ҷ�ӽ���� 
	{
		tr[p].sum+=k;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m)
	 update(lc,x,k);
	else
	 update(rc,x,k);
	tr[p].sum=tr[lc].sum+tr[rc].sum;
}
int query(int p,int x,int y)
{
	int sum=0;
	if(x<=tr[p].l && y>=tr[p].r)//���ȫ������ 
	 return tr[p].sum;
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m)
	 sum+=query(lc,x,y);
	if(y>m)
	 sum+=query(rc,x,y);//ע����y>m��ʱ�� 
	return sum;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>w[i];
	build(1,1,n);
	for(int i=0;i<m;i++)
	{
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1)
		 update(1,x,y);
		else if(op==2)
		 cout<<query(1,x,y)<<endl;
	}
	return 0;
} 
