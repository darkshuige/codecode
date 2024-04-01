#include<iostream>
#include<math.h>
#include <cstring>
#include <algorithm>
#include<stdio.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200;
double f[maxn][maxn];//f[i][j]表示第i轮j赢得概率
double g[maxn][maxn];
signed main()
{
	int n;
	while(scanf("%d",&n),n!=-1)
	{
		int m=1<<n;
		memset(f,0,sizeof f);
		for(int i=0;i<m;i++)
		 for(int j=0;j<m;j++)
		  scanf("%lf",&g[i][j]);
		for(int i=0;i<m;i++) f[0][i]=1;
		for(int i=1;i<=n;i++)//第i轮
		{
			for(int j=0;j<m;j++)//第一队
			{
				for(int k=0;k<m;k++)//第二队
				{
					if((1^(j>>(i-1)))==(k>>(i-1)))
					 f[i][j]+=g[j][k]*f[i-1][j]*f[i-1][k];
				}
			}
		}
		double ma=-1; int ans;
		for(int i=0;i<m;i++)
		 if(f[n][i]>ma)
		  ma=f[n][i],ans=i;
		printf("%d\n",ans+1);
	}
	return 0;
} 
