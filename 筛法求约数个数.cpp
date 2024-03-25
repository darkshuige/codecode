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
int prim[maxn],vis[maxn];
int a[maxn],d[maxn];//a表示最小质因子的次数,d表示约数的个数
void init(int n)
{
	int cnt=1;
	d[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(vis[i]==0)
		{
			prim[cnt++]=i;
			a[i]=1; d[i]=2;
		} 
		for(int j=1;i*prim[j]<=n;j++)//越界中断
		{
			int m=i*prim[j];
			vis[m]=1;
			if(i%prim[j]==0)
			{
				a[m]=a[i]+1;
				d[m]=d[i]/a[m]*(a[m]+1);
				break;//整除中断
			}
			else
			{
				a[m]=1;
				d[m]=d[i]*2;
			}
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
		cout<<d[a]<<endl;
	}
	return 0;
}