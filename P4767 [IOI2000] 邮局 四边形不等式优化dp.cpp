#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=4000;
int f[maxn][400];//f[i][j]表示i个村庄j个邮局的最小值
int w[maxn][maxn];//w[i][j]表示以i，j为边界时候的差值最小值
int p[maxn][400];
int n,m;
int a[maxn];
signed main()
{
	jiasu;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	 for(int j=i+1;j<=n;j++)
	  w[i][j]=w[i][j-1]+a[j]-a[i+j>>1];
	memset(f,inf,sizeof f); f[0][0]=0;
	for(int i=1;i<=m;i++) p[n+1][i]=n;
	for(int j=1;j<=m;j++)//枚举邮局，因为要从左边拿，所以要先枚举列
	 for(int i=n;i>=j;i--)//因为要从下面拿，所以要从后往前枚举
	  for(int k=p[i][j-1];k<=p[i+1][j];k++)
	   if(f[k][j-1]+w[k+1][i]<f[i][j])//前k个用j-1个邮局，k+1到i用1个邮局
	    f[i][j]=f[k][j-1]+w[k+1][i],p[i][j]=k;
	cout<<f[n][m]<<endl;
	return 0;
} 
