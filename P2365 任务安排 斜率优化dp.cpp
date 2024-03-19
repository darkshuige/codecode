#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=5005;
int f[maxn];//fi 打印前i个的最小值
int q[maxn],h,t;
int n,s;
int c[maxn],tim[maxn];
double slope(int i,int j)//算第i个点和第j个点之间的斜率
{
	return (double)(f[i]-f[j])/(c[i]==c[j]?1e-9:c[i]-c[j]);
}
signed main()
{
	jiasu;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>tim[i]>>c[i];
		tim[i]+=tim[i-1];
		c[i]+=c[i-1];
	}
	h=1,t=0;
	for(int i=1;i<=n;i++)
	{
		while(h<t && slope(i-1,q[t])<=slope(q[t],q[t-1])) t--;
		q[++t]=i-1;
		while(h<t && slope(q[h+1],q[h])<=s+tim[i]) h++;
		int j=q[h];
		f[i]=f[j]+tim[i]*(c[i]-c[j])+s*(c[n]-c[j]);
	}
	cout<<f[n]<<endl;
	return 0;
}