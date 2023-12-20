#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;//���ǿ��Ը�˹��Ԫ�õ������Ǿ���
//Ȼ������Խ����ϵ�����������ȡ����ֵ��������ʽ�ľ���ֵ�ˡ�
//����ͼG���������������ǻ�������������һn-1������ʽ������ʽ�ľ���ֵ��
//d[g]��������dij=du[i] i==j ; 0 i!=j
//a[g]�ڽӾ���aij=1 ij�б�
//c[g]=d[h]-a[g] 
const int maxn=1010;
long double eps=1e-8;
int n,m,k;
long double a[maxn][maxn],d[maxn][maxn],c[maxn][maxn];
void gauss(int n)
{
	n--;
	for(int i=1;i<=n;i++)
	{
		int r=i;
		for(int j=i+1;j<=n;j++)
		 if(fabs(c[j][i])>fabs(c[r][i]))//�ҵ����Խ�������ÿ��������Max���ڵ�����k
		  r=j;
		if(fabs(c[r][i])<eps)//�����һ��0 
		{
			cout<<0<<endl;
			return ;
		}
		if(r!=i)
		 for(int j=i;j<=n;j++) swap(c[r][j],c[i][j]);//���ó����б任�������б任����k���뵱ǰ��Ԫ�л�������¼�ܹ����д���n��
		for(int j=i+1;j<=n;j++)//�Ե�ǰ��Ԫ��Ϊ�������ó����б任���������任�������Խ����·���0
		{
			long double t=c[j][i]/c[i][i];
			for(int k=i;k<=n;k++) c[j][k]-=t*c[i][k];//����ʽÿ�λ������ţ�����ʽ���ķ���Ϊ-1^{n}
		}
	}
	long double ans=1;
	for(int i=1;i<=n;i++) ans*=c[i][i];
	cout<<fixed<<setprecision(0)<<ans<<endl;
	return ;
}
signed main()
{
	jiasu;
	while(cin>>n>>m>>k)
	{
		memset(a,0,sizeof a);memset(c,0,sizeof c);memset(d,0,sizeof d);
		for(int i=1;i<=n;i++)
		{
			d[i][i]=n-1;
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				a[i][j]=-1;
			}
		}
		while(m--)
		{
			int x,y; cin>>x>>y;
			if(abs(a[x][y])<=eps) continue;
			a[x][y]=a[y][x]=0;
			d[x][x]--;d[y][y]--;
		}
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=n;j++)
		  c[i][j]=a[i][j]+d[i][j];
		gauss(n);
	}
	return 0;
}
