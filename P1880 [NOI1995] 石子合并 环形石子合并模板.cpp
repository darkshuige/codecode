#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
//时间复杂度O(2*n^3)
const int maxn=200;
int f[maxn][maxn];//f[l][r]表示合并l到r最大的费用
int g[maxn][maxn];
int a[maxn],s[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n+1;i<=2*n;i++) a[i]=a[i-n];  //断链成环
	memset(s,0,sizeof s); memset(f,-inf,sizeof f); memset(g,inf,sizeof g);
	for(int i=1;i<=2*n;i++)
	{
		s[i]=s[i-1]+a[i];
		g[i][i]=0;
		f[i][i]=0;//只有一个合并费用就是0
	}
	for(int len=2;len<=n;len++)//枚举区间长度,1的话没有意义从2开始
	{
		for(int l=1;l+len-1<=2*n;l++)//枚举起始点  //环的区别在这里 r要到2*n结束
		{
			int r=l+len-1;//终点
			for(int k=l;k<r;k++)//枚举决策，因为右边是k+1~r所以不用=r
			{
				f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);//两边大的合并就是左边的费用+右边的费用再加上左右两边总和
				g[l][r]=min(g[l][r],g[l][k]+g[k+1][r]+s[r]-s[l-1]);
			}
		}
	}
	int ma=INT_MIN,mi=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		ma=max(ma,f[i][i+n-1]);
		mi=min(mi,g[i][i+n-1]);
	}
	cout<<mi<<endl<<ma<<endl;
	return 0;
} 
