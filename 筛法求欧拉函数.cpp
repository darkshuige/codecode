#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100000005;
const int mod=1000000007;
int prim[maxn],vis[maxn],phi[maxn];//phi表示欧拉函数
void init(int n)
{
	int cnt=1;
	for(int i=2;i<=n;i++)
	{
		if(vis[i]==0)
		{
			prim[cnt++]=i;
			phi[i]=i-1;
		} 
		for(int j=1;i*prim[j]<=n;j++)//越界中断
		{
			int m=i*prim[j];
			vis[m]=1;
			if(i%prim[j]==0)
			{
				phi[m]=phi[i]*prim[j];
				break;//整除中断
			}
			else
			 phi[m]=(prim[j]-1)*phi[i];
		}
	}
}
signed main()
{
	jiasu;
	int n,k;
	cin>>n>>k;
	init(n);
	while(k--)
	{
		int a;
		cin>>a;
		cout<<phi[a]<<endl;
	}
	return 0;
}