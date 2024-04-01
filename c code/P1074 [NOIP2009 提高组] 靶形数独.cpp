#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
const int w[9][9]=
{6,6,6,6,6,6,6,6,6,
 6,7,7,7,7,7,7,7,6,
 6,7,8,8,8,8,8,7,6,
 6,7,8,9,9,9,8,7,6,
 6,7,8,9,10,9,8,7,6,
 6,7,8,9,9,9,8,7,6,
 6,7,8,8,8,8,8,7,6,
 6,7,7,7,7,7,7,7,6,
 6,6,6,6,6,6,6,6,6};
const int maxn=5505;
int n,m,cnt;
int u[maxn],d[maxn],l[maxn],r[maxn];
int row[maxn],col[maxn];
int h,t;
int s[maxn];//每列的节点数 
int ans[maxn];
int a[maxn][maxn];
int aannss;
void init()
{
	aannss=-1;
	for(int i=0;i<=m;i++)
	{
		u[i]=d[i]=i;
		l[i]=i-1;
		r[i]=i+1;
	}
	l[0]=m;
	r[m]=0;
	cnt=m+1;
}
void link(int x,int y)// 在x行y列插入点，只插入1的点
{
	row[cnt]=x;col[cnt]=y;s[y]++;
	u[cnt]=u[y]; d[u[y]]=cnt; d[cnt]=y; u[y]=cnt;
	l[cnt]=t; r[t]=cnt; r[cnt]=h; l[h]=cnt;
	t=cnt++;
}
void remove(int y) //把第y列删掉并且把第y列是1的行都删了，只能选一个，在删掉的这几个之中选一个
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
void dance(int dep)//把某一列有1的行全部列出来并且删掉，因为同一列只能选一个行，然后递归每一行把每一行上有1的列都删了，
					//最后如果都删完了那就成功不然就失败 
{
	if(r[0]==0)
	{
		int sum=0;
		for(int i=0,x,y,v;i<dep;i++)
		{
			x=(ans[i]-1)/9/9;
			y=(ans[i]-1)/9%9;
			v=(ans[i]-1)%9+1;
			a[x][y]=v;
			sum+=w[x][y]*v;
		}
		aannss=max(aannss,sum);
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
signed main()
{
	jiasu;
	n=729,m=324; 
	init();
	for(int i=0;i<9;i++)
	{
		for(int j=0,x;j<9;j++)
		{
			cin>>x;
			a[i][j]=x;
			for(int k=1;k<=9;k++)
			{
				if(x==0 || x==k)
				{
					h=t=cnt;
					int r=i*9*9+j*9+k;
					link(r,i*9+j+1);
					link(r,81*1+i*9+k);
					link(r,81*2+j*9+k);
					link(r,81*3+(i/3*3+j/3)*9+k);
				}
			}
		}
	}
	dance(0);
	cout<<aannss<<endl;
	return 0;
}
