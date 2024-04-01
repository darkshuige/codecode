#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200;
int f[maxn][maxn];//f[l][r]表示合并l到r最大的费用
int a[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n+1;i<=2*n;i++) a[i]=a[i-n];  //断链成环
	for(int len=3;len<=n+1;len++)//枚举区间长度,1,2的话没有意义从3开始
	{
		for(int l=1;l+len-1<=2*n;l++)//枚举起始点  //环的区别在这里 r要到2*n结束
		{
			int r=l+len-1;//终点
			for(int k=l+1;k<r;k++)//枚举决策，因为这个是相乘，k不能和l或者r相等
			{
				f[l][r]=max(f[l][r],f[l][k]+f[k][r]+a[l]*a[r]*a[k]);
			}
		}
	}
	int ma=INT_MIN;
	for(int i=1;i<=n;i++)
	 ma=max(ma,f[i][i+n]);
	cout<<ma<<endl;
	return 0;
} 
