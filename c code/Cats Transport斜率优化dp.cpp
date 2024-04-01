#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int f[200][maxn];//f[i][j]表示前i个人带走j只猫的最小值
int q[maxn],h,t;
int n,m,p;
int d[maxn],tim[maxn],a[maxn],s[maxn];
//第i座山到起点 /第i只猫开始等待的时间 /人最早接走第i只猫的出发时刻//a的前缀和
double slope(int i,int j,int k)//算第i个点和第j个点之间的斜率
{
	return (double)(f[i-1][j]+s[j]-f[i-1][k]-s[k])/
					(j==k?1e-9:j-k);
}
signed main()
{
	jiasu;
	cin>>n>>m>>p;
	for(int i=2;i<=n;i++)
	{
		cin>>d[i];
		d[i]+=d[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		int h;
		cin>>h>>tim[i];
		a[i]=tim[i]-d[h];
	}	
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)
	 s[i]=s[i-1]+a[i];
	for(int i=1;i<=m;i++)
	 f[0][i]=LLONG_MAX;
	for(int i=1;i<=p;i++)
	{
		h=1,t=0;
		for(int j=1;j<=m;j++)
		{
			while(h<t && slope(i,j-1,q[t])<=slope(i,q[t],q[t-1])) t--;
			q[++t]=j-1;
			while(h<t && slope(i,q[h+1],q[h])<=a[j]) h++;
			int k=q[h];
			f[i][j]=f[i-1][k]+a[j]*(j-k)-(s[j]-s[k]);
		}
	}
	cout<<f[p][m]<<endl;
	return 0;
}