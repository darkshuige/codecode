#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100010;
int f[maxn];//阶乘
int g[maxn];//阶乘的逆元
int ksm(int a,int n,int p)
{
	int res=1;
	while(n)
	{
		if(n & 1) res=res*a%p;
		a=a*a%p;
		n>>=1;
	}
	return res;
}
void init(int p)
{
	g[0]=f[0]=1;
	for(int i=1;i<=p;i++)
	{
		f[i]=f[i-1]*i%p;
		g[i]=g[i-1]*ksm(i,p-2,p)%p;
	}
}
int getc(int n,int m,int p)
{
	if(n<m) return 0;
	return f[n]*g[m]*g[n-m]%p;//用快速幂求p以内的组合数，10^5之内的
}
int lucas(int n,int m,int p)
{
	if(m==0) return 1;//边界条件
	return lucas(n/p,m/p,p)*getc(n%p,m%p,p)%p;//递归调用lucas算法
}
signed main()
{
	jiasu;
	int t; cin>>t;
	while(t--)
	{
		int n,m,p; cin>>n>>m>>p;
		init(p);
		cout<<lucas(n+m,n,p)<<endl;
	}
	return 0;
}