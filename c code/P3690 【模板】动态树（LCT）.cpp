#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fa(x) tr[x].p
#define lc(x) tr[x].s[0]
#define rc(x) tr[x].s[1]
#define notroot(x) lc(fa(x))==x||rc(fa(x))==x  //�ж�x���Ƿ���ƽ�����ĸ��ڵ㣬����Ǹ��ڵ㸸�׽ڵ�Ķ��Ӳ����Լ� 
using namespace std;
const int maxn=100010;
int n,m;
struct node
{
	int s[2],p,v,sum;
	int lazy;//��ת��� 
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
void rotate(int x)//��xת��ȥ 
{
	int y=fa(x);int z=fa(y);
	int k=rc(y)==x;//0 �� 1 ��x�ǲ��Ǹ��ڵ�
	if(notroot(y))
	 tr[z].s[rc(z)==y]=x; //�������ǰ����
	fa(x)=z;//�ϵ����϶�
	tr[y].s[k]=tr[x].s[k^1];
	fa(tr[x].s[k^1])=y;
	tr[x].s[k^1]=y;
	fa(y)=x;
	pushup(y),pushup(x);
}
void pushall(int x)//�Ҹ��ڵ�Ȼ��ȫ��push����Ҳ���ǰѵ�xΪֹ�ķ�ת��� 
{
	if(notroot(x)) pushall(fa(x));
	pushdown(x);
}
void splay(int x)//��չ��������ͨƽ��������һ������ ��xת����ǰƽ�����ĸ��ڵ� 
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
void access(int x)//��x������ĸ��ڵ��ͨ ��ʵ�ߣ��������� 
{
	for(int y=0;x;)//x=0ʱ���� 
	{
		splay(x);
		rc(x)=y;
		pushup(x);
		y=x,x=fa(x);//���������Ǹ�ƽ���� 
	}
}
void makeroot(int x)//���� 
{
	access(x);//��ͨ· 
	splay(x);//��x���������� 
	tr[x].lazy^=1;//��ת 
}
void split(int x,int y)//�Ѵ�x��y��·��������� ��·�����һ��ʵ������yת���� 
{
	makeroot(x);//�Ȱ�x������
	access(y);//��ͨy
	splay(y);//��y������ 
}
void output(int x,int y)
{
	split(x,y);
	cout<<tr[y].sum<<endl;
}
int findroot(int x)//�Ҹ����Ȱ�x���������棬��ԭ���ĸ����������½� 
{
	access(x);
	splay(x);
	while(lc(x))
	 pushdown(x),x=lc(x);
	splay(x);//��ֹ���� 
	return x;
}
void link(int x,int y)//����
{
	makeroot(x);//�Ȱ�x���ɸ�
	if(findroot(y)!=x) fa(x)=y;//�������ͬһ������	
}
void cut(int x,int y) //�ϱ�
{
	makeroot(x);//�Ȱ�x���ɸ� 
	if(findroot(y)==x && fa(y)==x && !lc(y))//���y�ĸ���x����x��y�ϸ��������ܶ� 
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
