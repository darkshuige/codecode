#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=300;
int f[maxn][maxn];//f[i][j]表示区间[i,j]构建二叉树所要的
int a[maxn],s[maxn];
int p[maxn][maxn];
signed main()
{
	jiasu;
	int n;
	while(cin>>n)
	{
		memset(s,0,sizeof s); memset(p,0,sizeof p);
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		memset(f,inf,sizeof f);//找最小值
		for(int i=1;i<=n;i++)//边界条件
		{
			p[i][i]=i;
			f[i][i]=0;
			f[i+1][i]=0;
			f[i][i-1]=0;
		}
		for(int len=2;len<=n;len++)//枚举长度
		{
			for(int i=1;i+len-1<=n;i++)//枚举左端点
			{
				int j=i+len-1;
				for(int k=p[i][j-1];k<=p[i+1][j];k++)//枚举决策
				{
					if(f[i][j]>f[i][k-1]+f[k+1][j]+s[j]-s[i-1]-a[k])
					{
						f[i][j]=f[i][k-1]+f[k+1][j]+s[j]-s[i-1]-a[k];
						p[i][j]=k;
					}
				}
			}
		}
		cout<<f[1][n]<<endl;
	}
	return 0;
} 
