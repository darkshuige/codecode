#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
using namespace std;
const int maxn=1000055;
int f[maxn],c[maxn];//f存容量为j时候的最大数量，c存方案数
signed main()
{
	jiasu;
	int n,m,w,v;
	cin>>n>>m;
	for(int i=1;i<=m;i++) f[i]=-inf//恰好装满，只要从预处理做手脚
	f[0]=0,c[0]=1;
	//这样预处理，方案数只有从间接或直接从0往上走才能增加
	//把f[i]处理成负无穷，这样只有从0往上走的时候才是正数，f[m]就是恰好装满的最大
	for(int i=1;i<=n;i++)
	{
		cin>>v>>w;
		for(int j=m;j>=v;j--)
		{
			if(f[j-v]+w>f[j])//拿第i个东西总价值更大
			{
				f[j]=f[j-v]+w;
				c[j]=c[j-v];//只是拿了一个i，方案数没有增加
			}
			else if(f[j]==f[j-v]+w)
			{
				c[j]=(c[j]+c[j-v])%mod;
			}
		}
	}
	cout<<c[m]<<endl;
	return 0;
} 
