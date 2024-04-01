#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2000;
double f[maxn][maxn];//f[i][j]表示i个白j个黑拿到白的概率
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<maxn;i++)
	{
		f[i][0]=1;
		f[0][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]+=i*1.0/(i+j);
			if(j>=3)
			 f[i][j]+=f[i][j-3]*j*1.0/(i+j)*(j-1)*1.0/(i+j-1)*(j-2)*1.0/(i+j-2);
			if(j>=2 && i>=1)
			 f[i][j]+=f[i-1][j-2]*j*1.0/(i+j)*(j-1)*1.0/(i+j-1)*(i)*1.0/(i+j-2);
		}
	}
	cout<<fixed<<setprecision(9)<<f[n][m]<<endl;
	return 0;
} 
