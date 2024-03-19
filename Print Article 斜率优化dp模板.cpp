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
int s[maxn];//前缀和
int q[maxn],h,t;
int n,m;
double slope(int i,int j)//算第i个点和第j个点之间的斜率
{
	return (double)(f[i]+s[i]*s[i]-f[j]-s[j]*s[j])/(s[i]==s[j]?1e-9:s[i]-s[j]);
}
deque<int>de;
signed main()
{
	jiasu;
	while(cin>>n>>m)
	{
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
			while(h<t && slope(q[h+1],q[h])<=2*s[i]) h++;
			int j=q[h];
			f[i]=f[j]+(s[i]-s[j])*(s[i]-s[j])+m;
		}
		cout<<f[n]<<endl;
	}
	return 0;
}