#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
int s[maxn],t[maxn],p[maxn];//速度 推迟时间 推迟时间
double sj[maxn];
int st[maxn],ed[maxn];
int cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	jiasu;
	int n,k,x,p0; cin>>n>>k>>x>>p0;//人数 延迟次数 距离 一开始的登记时间
	for(int i=1;i<=n;i++)
	 cin>>s[i];
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	 sj[i]=1.0*x/s[i];
	int ma=p0;
	for(int i=1;i<=k;i++) cin>>st[i];
	for(int i=1;i<=k;i++) cin>>ed[i];
	for(int i=1;i<=k;i++)
	 ma=max(ma,ed[i]-st[i]);
	int pos=0;
	for(int i=1;i<=n;i++)
	 if(ma>=sj[i])
	  pos=i;
	cout<<pos<<endl;
	return 0;
}