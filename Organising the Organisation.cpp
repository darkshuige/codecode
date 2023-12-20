#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;//我们可以高斯消元得到上三角矩阵。
//然后把主对角线上的数都乘起来取绝对值就是行列式的绝对值了。
//无向图G的生成树个数就是基尔霍夫矩阵的任一n-1阶主子式的行列式的绝对值。
//d[g]度数矩阵dij=du[i] i==j ; 0 i!=j
//a[g]邻接矩阵aij=1 ij有边
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
		 if(fabs(c[j][i])>fabs(c[r][i]))//找到主对角线以下每列最大的数Max所在的行数k
		  r=j;
		if(fabs(c[r][i])<eps)//如果有一个0 
		{
			cout<<0<<endl;
			return ;
		}
		if(r!=i)
		 for(int j=i;j<=n;j++) swap(c[r][j],c[i][j]);//利用初等行变换——换行变换，将k行与当前主元行互换（记录总共换行次数n）
		for(int j=i+1;j<=n;j++)//以当前主元行为基，利用初等行变换——消法变换，将主对角线下方消0
		{
			long double t=c[j][i]/c[i][i];
			for(int k=i;k<=n;k++) c[j][k]-=t*c[i][k];//行列式每次换行需变号，行列式最后的符号为-1^{n}
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
