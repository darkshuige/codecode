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
	int l,r,s;//���ұ߽�Ͷ��ٸ��� 
}tr[maxn*20];
int root[maxn],idx=0;//root���������ڼ�����ʱ����idx�ӵ�
int n,m,a[maxn];
vector<int>b;//������ɢ��
void build(int &x,int l,int r)//���ã��ݹ鸳ֵ 
{	
	x=++idx;
	if(l==r) return ;
	int m=l+r>>1;
	build(lc(x),l,m);//��lc(x)��ֵ˳�� 
	build(rc(x),m+1,r);
}
void insert(int x,int &y,int l,int r,int k)//x��ʾ������һ�������y��ʾ��ǰ��Ҳ�Ǻ�build�ַ�һ�� 
{
	y=++idx; tr[y]=tr[x]; tr[y].s++;//y��x�Ĳ�����y����һ��insert��ȥ����
	if(l==r) return ;
	int m=l+r>>1;
	if(k<=m) insert(lc(x),lc(y),l,m,k);//lc(x)�Ǵ��ڵģ�rc(x)��û����ȥ֮��Ÿ�rcx��ֵ 
	else insert(rc(x),rc(y),m+1,r,k); 
}
int query(int x,int y,int l,int r,int k)//x��֮ǰ��root y�����ڵģ�l r��ֵ��k�ǵڼ��� 
{
	if(l==r) return l;
	int m=l+r>>1;
	int s=tr[lc(y)].s-tr[lc(x)].s;
	if(k<=s) return query(lc(x),lc(y),l,m,k);//�������
	else return query(rc(x),rc(y),m+1,r,k-s);//���ѱ��ң�Ҫ��ȥ��ߵĸ��� 
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
	int bn=b.size();//��ɢ������������ȥ�� ���ֲ��� ֮�����1�� bn������
	build(root[0],1,bn);
	for(int i=1;i<=n;i++)
	{
		int id=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;//+1����Ϊ��b�����Ǵ�0��ʼ������+1
		insert(root[i-1],root[i],1,bn,id);
	}
	while(m--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		int id=query(root[l-1],root[r],1,bn,k);//l-1��r ǰ׺��˼�� 
		cout<<b[id-1]<<endl;//����Ҫ-1����Ϊ֮ǰ+��1�� 
	}
	return 0;
}
