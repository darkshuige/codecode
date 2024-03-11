#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
//数位dp的特点:求某个区间[l,r]内，满足某种性质的数的个数
//技巧1：类似前缀和思想，转化为f[r]-f[l-1]
//技巧2:从高位到低位填数，分类讨论
//模板：先对数集从高位到低位做预处理，再对数集从高位到低位做递推
const int maxn=34;
int a[maxn]; //每一位数都分离出来
int f[maxn][maxn];//f[i][j]表示在i个位置上放置j个1的组合数
int K,B;
void init()
{
	for(int i=0;i<maxn;i++) f[i][0]=1;
	for(int i=1;i<maxn;i++)//组合数
	 for(int j=1;j<=i;j++)
	  f[i][j]=f[i-1][j-1]+f[i-1][j];	
}
int dp(int n)
{
	if(!n) return 0;
	int cnt=0;
	while(n)
	{
		a[++cnt]=n%B;
		n/=B;
	}
	int res=0,last=0;        //last表示用掉了1的个数
	for(int i=cnt;i>=1;i--)  //枚举最高位的数
	{
		int now=a[i];			 //最高位的数字
		if(now)
		{
			res+=f[i-1][K-last];//取0的情况
			if(now>1)
			{
				if(K-last>=1)//原来大于1取1的情况
				 res+=f[i-1][K-last-1];
				break;//剪枝
			}
			else//固定最高位
			{
				last++;
				if(last>K) break;//剪枝
			}	
		}
		if(i==1 && last==K) res++;
	}
	return res;
}
signed main()
{
	jiasu;
	init();
	int l,r;
	cin>>l>>r>>K>>B;
	 cout<<dp(r)-dp(l-1)<<endl;	
	return 0;
} 
