#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=12;
//状态压缩dp
//用二进制表示状态，用十进制储存状态
//用位运算筛选出合法状态
//用位运算判断状态转移的条件
//计算时每个类累加上一行的兼容类
int n,k,cnt;
int s[1<<12];//一行合法状态的集合
int num[1<<12];//每个合法状态包含的国王数
long long f[12][144][1<<12];//f[i][j][k]表示第i行放了j个国王放的是方案k时候的个数
signed main()
{
	jiasu;
	cin>>n>>k;
	cnt=0;
	for(int i=0;i<(1<<n);i++)//枚举所有状态
	{
		if((i & (i>>1))==0)//不存在相邻的1
		{
			s[cnt++]=i;
			for(int j=0;j<n;j++)
			{
				if((i>>j) & 1)
				 num[i]++;//合法状态的国王数
			}
		}
	}//预处理
	f[0][0][0]=1;
	for(int i=1;i<=n+1;i++)//直接循环到n+1行，那么f[n+1][k][0]就表示n行的总和也就是ans
	{
		for(int j=0;j<=k;j++)//可以从0开始
		{
			for(int a=0;a<cnt;a++)//枚举第i行的形态 前面是循环行数和个数，后面两个循环的是策略，思想和完全背包类似
			{
				for(int b=0;b<cnt;b++)//枚举第i-1行的形态  
				{
					int c=num[s[a]];//第i行用了c个皇帝
					if(j>=c && !(s[b] & s[a]) && !(s[b] & (s[a]>>1)) && !(s[b] & (s[a]<<1)))
					{
						f[i][j][a]+=f[i-1][j-c][b];
					}
				}
			}
		}
	}
	cout<<f[n+1][k][0]<<endl;
	return 0;
} 
