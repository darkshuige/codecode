#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
const int maxn=300000;
int n,m,cnt;
int u[maxn],d[maxn],l[maxn],r[maxn];
int row[maxn],col[maxn];
int h[maxn];//ͷ���
int s[maxn];//ÿ�еĽڵ��� 
int ans[maxn];
int aannss;
void init()
{
	aannss=-1;
	memset(h,0,sizeof h);
	memset(s,0,sizeof s);
	for(int i=0;i<=m;i++)
	{
		u[i]=d[i]=i;
		l[i]=i-1;
		r[i]=i+1;
	}
	l[0]=m;
	r[m]=0;
	cnt=m;
}
void link(int x,int y)// ��x��y�в���㣬ֻ����1�ĵ�
{
	row[++cnt]=x;col[cnt]=y;s[y]++;
	u[cnt]=u[y];
	d[u[y]]=cnt;
	d[cnt]=y;
	u[y]=cnt;
	if(h[x]==0)
	{
		h[x]=r[cnt]=l[cnt]=cnt;
	}
	else
	{
		l[cnt]=l[h[x]];
		r[l[h[x]]]=cnt;
		r[cnt]=h[x];
		l[h[x]]=cnt;
	}
}
void remove(int y) //�ѵ�y��ɾ�����Ұѵ�y����1���ж�ɾ�ˣ�ֻ��ѡһ������ɾ�����⼸��֮��ѡһ��
{
	r[l[y]]=r[y],l[r[y]]=l[y];
	for(int i=d[y];i!=y;i=d[i])
	{
		for(int j=r[i];j!=i;j=r[j])
		{
			u[d[j]]=u[j],d[u[j]]=d[j],s[col[j]]--;
		}
	}
}
void resume(int y)
{
	r[l[y]]=y,l[r[y]]=y;
	for(int i=u[y];i!=y;i=u[i])
	{
		for(int j=l[i];j!=i;j=l[j])
		{
			u[d[j]]=j,d[u[j]]=j,s[col[j]]++;
		}
	}
}
void dance(int dep)//��ĳһ����1����ȫ���г�������ɾ������Ϊͬһ��ֻ��ѡһ���У�Ȼ��ݹ�ÿһ�а�ÿһ������1���ж�ɾ�ˣ�
					//��������ɾ�����Ǿͳɹ���Ȼ��ʧ�� 
{
	if(r[0]==0)
	{
		if(aannss==-1)
		 aannss=dep;
		else
		 aannss=min(aannss,dep);
	}
	int y=r[0];
	for(int i=r[0];i;i=r[i])
	 if(s[i]<s[y])
	  y=i;
	remove(y);
	for(int i=d[y];i!=y;i=d[i])
	{
		ans[dep]=row[i];
		for(int j=r[i];j!=i;j=r[j]) remove(col[j]);
		dance(dep+1);
		for(int j=l[i];j!=i;j=l[j]) resume(col[j]);
	}
	resume(y);
}
int pos[35][35];
void get_pos(int n, int m)
{
    int idx = 1;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
        pos[i][j] = idx ++;
}
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		n=c;m=a*b;
		init();
		get_pos(a, b);
		for(int i=1;i<=c;i++)
		{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			for(int j=x1+1;j<=x2;j++)
			{
				for(int k=y1+1;k<=y2;k++)
				{
					link(i,pos[j][k]);
				}
			}
		}
		dance(0);
		cout<<aannss<<endl;
	}
	return 0;
}
