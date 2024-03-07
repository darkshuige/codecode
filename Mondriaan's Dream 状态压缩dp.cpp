#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=12;
const int maxm=(1<<maxn);
int f[maxn][maxm];//f[i][k]表示第i列用k这个决策的值，k用十进制表示二进制表示一整列的决策
bool st[maxm];//判断决策的合法
signed main()
{
	jiasu;
	int n,m;
	while(cin>>n>>m)
	{
		// 预处理：判断合并列的状态i是否合法 
	    // 合并列即两列状态合并之意，对应后面的st[j|k]      
	    // 如果合并列的某行是1表示横放，是0表示竖放 
	    // 如果合并列不存在连续的奇数个0，即为合法状态 
		if(n==0 && m==0) break;
		for(int i=0;i<(1<<n);i++)//枚举每一列的决策，有n行也就是n个数
		{
			st[i]=1;
			int cnt=0;//判断连续的0是否为偶数，偶数合法奇数不合法
			for(int j=0;j<n;j++)//用0表示竖放或者来自上一列 1表示横放并且通向下一列
			{
				if((i>>j) & 1)//横放
				{
					if(cnt & 1)
					{
						st[i]=0;
						break;
					}
				}
				else
				 cnt++;
			}
			if(cnt & 1) st[i]=0;
		}
		memset(f,0,sizeof f); f[0][0]=1;//第0列不放
		for(int i=1;i<=m;i++)//阶段：枚举列
		{
			for(int a=0;a<(1<<n);a++)//状态：枚举第i列的状态
			{
				for(int b=0;b<(1<<n);b++)////状态：枚举第i-1列的状态
				{
					if(!(a & b) && st[a | b]) //两列状态兼容：不出现重叠的1，不出现连续的奇数个0 
					{
						f[i][a]+=f[i-1][b];
					}
				}
			}
		}
		cout<<f[m][0]<<endl;//第m列也就是最后一列不放横着的
	}
	return 0;
} 
