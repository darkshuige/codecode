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
const int maxn=12;
int a[maxn]; //每一位数都分离出来
int f[maxn][maxn];//f[i][j]表示i位数最高位为j的不降数的个数
void init()
{
	for(int i=0;i<maxn;i++) f[1][i]=1;
	for(int i=2;i<maxn;i++) //阶段：枚举位数 
	{
		for(int j=0;j<=9;j++) //状态：枚举最高位
		{
			for(int k=j;k<=9;k++) //决策：枚举次高位 
			{
				f[i][j]+=f[i-1][k];
			}
		}
	}
}
int dp(int n)
{
	if(!n) return 1;
	int cnt=0;
	while(n)
	{
		a[++cnt]=n%10;
		n/=10;
	}
	int res=0,last=0;        //last表示上一位的数字
	for(int i=cnt;i>=1;i--)  //枚举最高位的数
	{
		int now=a[i];			 //最高位的数字
		for(int j=last;j<now;j++)//枚举次高位能填入的数
		 res+=f[i][j];
		if(now<last) break;
		last=now;
		if(i==1) res++;
	}
	return res;
}
signed main()
{
	jiasu;
	init();
	int l,r;
	while(cin>>l>>r)
	 cout<<dp(r)-dp(l-1)<<endl;	
	return 0;
} 
