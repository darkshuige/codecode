#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=500005;
int f[maxn];//fi 打印前i个的最小值
int q[maxn],h,t;
int n,l;
int s[maxn];
double slope(int i,int j)//算第i个点和第j个点之间的斜率
{
	return (double)(f[i]-f[j]+(s[i]+i)*(s[i]+i)-(s[j]+j)*(s[j]+j))/
					(s[i]+i==s[j]+j?1e-9:s[i]+i-s[j]-j);
}
signed main()
{
	jiasu;
	cin>>n>>l;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]+=s[i-1];
	}
	h=1,t=0;
	for(int i=1;i<=n;i++)
	{
		while(h<t && slope(i-1,q[t])<=slope(q[t],q[t-1])) t--;
		q[++t]=i-1;
		while(h<t && slope(q[h+1],q[h])<=2*(s[i]+i-l-1)) h++;
		int j=q[h];
		f[i]=f[j]+(i-(j+1)+s[i]-s[j]-l)*(i-(j+1)+s[i]-s[j]-l);
	}
	cout<<f[n]<<endl;
	return 0;
}