#include<iostream>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=110;
const int maxm=1<<11;
//状态压缩dp
//用二进制表示状态，用十进制储存状态
//用位运算筛选出合法状态
//用位运算判断状态转移的条件
//计算时每个类累加上一行的兼容类
int n,k,cnt,m;
int s[maxm];//一行合法状态的集合
int num[maxm];
int f[2][maxm][maxm];//f[i][a][b]表示第i行的是方案a i-1行是方案b的最大值
int g[maxn];//g用来存玉米地原来的状态，也是二进制表示十进制储存
signed main()
{
	jiasu;
	cin>>n>>m;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char cc; cin>>cc; int x;
			if(cc=='P') x=1; else x=0;
			g[i]=(g[i]<<1)+x;//二进制转10
		}
	}
	for(int i=0;i<(1<<m);i++)//枚举所有状态
	{
		if((i & (i>>1))==0 && (i & (i>>2))==0)//不存在相邻的1
		{
			s[cnt++]=i;//预处理
			for(int j=0;j<m;j++)
			 if(((i>>j) & 1)==1)
			  num[i]++;
		}
	}
	for(int i=1;i<=n+2;i++)//直接循环到n+2行
	{
		for(int a=0;a<cnt;a++)//枚举第i行的形态 前面是循环行数和个数，后面两个循环的是策略，思想和完全背包类似
		{
			for(int b=0;b<cnt;b++)//枚举第i-1行的形态  
			{
				for(int c=0;c<cnt;c++)//枚举第i-2行的形态  
				{
					
					if(!(s[b] & s[a]) && !(s[a] & s[c]) && !(s[b] & s[c]) && (s[a] & g[i])==s[a] && (s[b] & g[i-1])==s[b])//传神的一步，第a个决策和第i行匹配
					{
						f[i&1][a][b]=max(f[i&1][a][b],f[i-1&1][b][c]+num[s[a]]);
					}	
				}
				
			}
		}
	}
	cout<<f[n+2&1][0][0]<<endl;
	return 0;
} 
