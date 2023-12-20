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
void rotate(int x)//��xת��ȥ��һ������ת����ת��ת 
{
	int y=tr[x].p,z=tr[y].p;
	int k=tr[y].s[1]==x;//���x���Ҷ��ӣ�k=1,����� k=0;
	tr[y].s[k]=tr[x].s[k^1];
	tr[tr[x].s[k^1]].p=y; //y
	tr[x].s[k^1]=y;
	tr[y].p=x;       //x;
	tr[z].s[tr[z].s[1]==y]=x;//���y���Ҷ����Ǿ���s[1]����֮s[2] 
	tr[x].p=z;
	pushup(y);pushup(x);//��������pushup 
}
void splay(int x,int k)//��x��ת��k������һ�����ж�������ת������
{
	while(tr[x].p!=k)
	{
		int y=tr[x].p,z=tr[y].p;
		if(z!=k)//���z==k��ֻ��תһ�� 
		{
			(tr[y].s[0]==x)^(tr[z].s[0]==y)?rotate(x):rotate(y);//�����1˵�������ߣ���ôӦ�����ζ�תx�������0˵����ֱ������תy 
		}
		rotate(x);
	}
	if(k==0) root=x;
} 
void insert(int v)
{
	int x=root,p=0;//pָ�򸸽ڵ�
	while(x)//�������ߵ���λ 
	{
		p=x;
		x=tr[x].s[v>tr[x].v];
	}
	x=++idx;
	tr[p].s[v>tr[p].v]=x;
	tr[x].init(p,v);
	splay(x,0);
}
int get_k(int k)//���ص�k����ı�� 
{
	int x=root;
	while(1)
	{
		pushdown(x);
		int y=tr[x].s[0];
		if(tr[y].size+tr[x].cnt<k)//�������ұ��� //���������Լ� 
		{
			k-=tr[y].size+tr[x].cnt;
			x=tr[x].s[1];
		}
		else if(tr[y].size>=k)//������� 
		{
			x=y;
		}
		else
		{
			return x;
		}
	}
}
void output(int x)//�������
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
		l=get_k(l);r=get_k(r+2);//Ҫ�ҵ�l-1 r+1�����䣬��Ϊ���ڱ�����l r+2 ����ͨƽ������delһ��ԭ�� 
		splay(l,0);splay(r,l);
		tr[tr[r].s[0]].lazy^=1;
	}
	output(root);
	return 0;
}
