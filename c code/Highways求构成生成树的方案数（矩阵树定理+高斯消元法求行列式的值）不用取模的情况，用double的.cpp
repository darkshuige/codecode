#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
//我们可以高斯消元得到上三角矩阵。
//然后把主对角线上的数都乘起来取绝对值就是行列式的绝对值了。
//无向图G的生成树个数就是基尔霍夫矩阵的任一n-1阶主子式的行列式的绝对值。
//d[g]度数矩阵dij=du[i] i==j ; 0 i!=j
//a[g]邻接矩阵aij=1 ij有边
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
		 if(fabs(a[j][i])>fabs(a[r][i]))//找到主对角线以下每列最大的数Max所在的行数k
		  r=j;
		if(fabs(a[r][i])<eps)//如果有一个0 
		{
			cout<<0<<endl;
			return ;
		}
		if(r!=i)
		 for(int j=i;j<=n;j++) swap(a[r][j],a[i][j]);//利用初等行变换——换行变换，将k行与当前主元行互换（记录总共换行次数n）
		for(int j=i+1;j<=n;j++)//以当前主元行为基，利用初等行变换——消法变换，将主对角线下方消0
		{
			double t=a[j][i]/a[i][i];
			for(int k=i;k<=n;k++) a[j][k]-=t*a[i][k];//行列式每次换行需变号，行列式最后的符号为-1^{n}
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
