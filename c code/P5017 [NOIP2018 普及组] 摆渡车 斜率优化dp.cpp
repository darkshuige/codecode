#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=4000005;
int f[maxn];//i时刻发车等待的最小值
int q[maxn],h,t;
int n,m;
int c[maxn],s[maxn];//c是i时刻人数的前缀和，t是i时刻等待时间的前缀和
double slope(int i,int j)//算第i个点和第j个点之间的斜率
{
	return (double)(f[i]+s[i]-f[j]-s[j])/
					(c[i]==c[j]?1e-9:c[i]-c[j]);
}
signed main()
{
	jiasu;
	cin>>n>>m;
	int last=0;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		c[x]++,s[x]+=x;
		last=max(last,x);
	}
	for(int i=1;i<=last+m;i++)
	{
		c[i]+=c[i-1];
		s[i]+=s[i-1];
	}
	for(int i=0;i<m;i++)
	 f[i]=i*c[i]-s[i];
	int ans=LLONG_MAX;
	h=1,t=0;
	for(int i=m;i<=m+last;i++)
	{
		while(h<t && slope(i-m,q[t])<=slope(q[t],q[t-1])) t--;
		q[++t]=i-m;
		while(h<t && slope(q[h+1],q[h])<=i) h++;
		int j=q[h];
		f[i]=f[j]+i*(c[i]-c[j])-(s[i]-s[j]);
		if(i>=last) ans=min(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}