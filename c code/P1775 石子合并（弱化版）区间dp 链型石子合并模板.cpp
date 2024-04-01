#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
//时间复杂度O(n^3)
const int maxn=400;
int f[maxn][maxn];//f[l][r]表示合并l到r最小的费用
int a[maxn],s[maxn];
signed main()
{
	jiasu;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(s,0,sizeof s); memset(f,inf,sizeof f);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		f[i][i]=0;//只有一个合并费用就是0
	}
	for(int len=2;len<=n;len++)//枚举区间长度,1的话没有意义从2开始
	{
		for(int l=1;l+len-1<=n;l++)//枚举起始点
		{
			int r=l+len-1;//终点
			for(int k=l;k<r;k++)//枚举决策，因为右边是k+1~r所以不用=n
			{
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);//两边大的合并就是左边的费用+右边的费用再加上左右两边总和
			}
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
} 
