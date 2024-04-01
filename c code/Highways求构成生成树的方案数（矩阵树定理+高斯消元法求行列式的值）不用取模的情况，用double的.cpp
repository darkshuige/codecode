#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
//���ǿ��Ը�˹��Ԫ�õ������Ǿ���
//Ȼ������Խ����ϵ�����������ȡ����ֵ��������ʽ�ľ���ֵ�ˡ�
//����ͼG���������������ǻ�������������һn-1������ʽ������ʽ�ľ���ֵ��
//d[g]��������dij=du[i] i==j ; 0 i!=j
//a[g]�ڽӾ���aij=1 ij�б�
//c[g]=d[h]-a[g] 
const int maxn=1010;
double eps=1e-8;
double a[maxn][maxn];
void gauss(int n)
{
	n--;
	for(int i=1;i<=n;i++)
	{
		int r=i;
		for(int j=i+1;j<=n;j++)
		 if(fabs(a[j][i])>fabs(a[r][i]))//�ҵ����Խ�������ÿ��������Max���ڵ�����k
		  r=j;
		if(fabs(a[r][i])<eps)//�����һ��0 
		{
			cout<<0<<endl;
			return ;
		}
		if(r!=i)
		 for(int j=i;j<=n;j++) swap(a[r][j],a[i][j]);//���ó����б任�������б任����k���뵱ǰ��Ԫ�л�������¼�ܹ����д���n��
		for(int j=i+1;j<=n;j++)//�Ե�ǰ��Ԫ��Ϊ�������ó����б任���������任�������Խ����·���0
		{
			double t=a[j][i]/a[i][i];
			for(int k=i;k<=n;k++) a[j][k]-=t*a[i][k];//����ʽÿ�λ������ţ�����ʽ���ķ���Ϊ-1^{n}
		}
	}
	double ans=1;
	for(int i=1;i<=n;i++) ans*=a[i][i];
	cout<<fixed<<setprecision(0)<<ans<<endl;
	return ;
}
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		memset(a,0,sizeof a);
		int n,m; cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			int x,y;cin>>x>>y;
			a[x][x]++;a[y][y]++;a[x][y]--;a[y][x]--;
		}
		gauss(n);
	}
	return 0;
}
