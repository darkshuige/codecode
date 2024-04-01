#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
using namespace std;
const int maxn=110005,INF=(1<<30)+1;;
int root,idx;
struct node
{
	int p,v,cnt,size,s[2];
	void init(int p1,int v1)
	{
		p=p1;
		v=v1;
		cnt=size=1;
	}
}tr[maxn];
void push(int x)
{
	tr[x].size=tr[tr[x].s[0]].size+tr[tr[x].s[1]].size+tr[x].cnt;
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
	push(y);push(x);//��������push 
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
void find(int v)//����v ���ڵĽڵ� 
{
	int x=root;//��root��ʼ��;
	while(tr[x].s[v>tr[x].v] && v!=tr[x].v)//���������߲��ǿղ��Ҳ�����v 
	{
		x=tr[x].s[v>tr[x].v];//���������ߣ�Ҫ��v��x.v����ô���ұ��� 
	}
	splay(x,0);//�ҵ�֮��x����v���ڵĵ㣬ֱ���õ����ڵ� 
}
int get_pre(int v)//��ǰ����Ҳ��������v�����С��v��ֵ���ڵĵ� 
{
	find(v);
	int x=root;//�˿�Ҫ��v������ôxָ��v��Ҫ��v��������ôָ����v�����
	if(tr[x].v<v) return x;//v�����ڵ������
	x=tr[x].s[0];//��ȥ����������ô�������ĵ㶼�Ǳȸ��ڵ�С�ģ� 
	while(tr[x].s[1]) x=tr[x].s[1];//һֱ���ұ��ߣ��ҵ����� 
	splay(x,0);
	return x;
}
int get_suc(int v)
{
	find(v);
	int x=root;
	if(tr[x].v>v) return x;
	x=tr[x].s[1];
	while(tr[x].s[0]) x=tr[x].s[0];
	splay(x,0);
	return x;
}
void del(int v)//ɾ��v��������ڵĵ� 
{
	int pre=get_pre(v);
	int suc=get_suc(v);
	splay(pre,0);
	splay(suc,pre);//��vֵ���ڵĵ��Ƶ�Ҷ�ӽ������ 
	int del=tr[suc].s[0];//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if(tr[del].cnt>1)//Ҫ���������Ǿͼ�һ����������Ӱ�� 
	{
		tr[del].cnt--;
		splay(del,0);//Ϊ�˸����������ֵ;	
	}
	else
	{
		tr[suc].s[0]=0;//sĬ��Ϊ0��Ϊ0��ʾ�� 
		splay(suc,0);
	}
}
void insert(int v)
{
	int x=root,p=0;//pָ�򸸽ڵ�
	while(x && tr[x].v!=v)//�����ң�ֱ���ҵ������ߵ���λ 
	{
		p=x;
		x=tr[x].s[v>tr[x].v];
	}
	if(x)//�ҵ���,˵���г��ֹ��� 
	{
		tr[x].cnt++;
	}
	else// û���ֹ����ߵ���λ�ˣ����� 
	{
		x=++idx;
		tr[p].s[v>tr[p].v]=x;
		tr[x].init(p,v);
	}
	splay(x,0);
}
int get_rank(int v)//�ҵ�vֵ������//Ҫ��û��vҪ�Ȳ���v 
{
	insert(v);
	int res=tr[tr[root].s[0]].size;
	del(v);
	return res;
}
int get_val(int k)//��ѯ����Ϊk��ֵ 
{
	int x=root;
	while(1)
	{
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
	int n;
	int x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		cin>>x;
		if(op==1) insert(x);
		else if(op==2) del(x);
		else if(op==3) cout<<get_rank(x)<<endl;
		else if(op==4) cout<<get_val(x+1)<<endl;
		else if(op==5) cout<<tr[get_pre(x)].v<<endl;
		else if(op==6) cout<<tr[get_suc(x)].v<<endl;
	}
	return 0;
}
