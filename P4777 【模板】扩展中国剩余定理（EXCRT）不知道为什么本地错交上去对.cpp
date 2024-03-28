#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define ll __int128
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=100005;
ll n;
ll m[maxn],r[maxn];
//O(nlogm1)
//扩展中国剩余定理 模数不一定互质的线性同余方程组
ll exgcd(ll a,ll b,ll &x,ll &y)//x y引用因为也要返回
{
	if(b==0)//原来的欧几里得算法，辗转相除法
	{
		x=1,y=0;
		return a;
	}
	ll x1,y1,d;
	d=exgcd(b,a%b,x1,y1);
	x=y1,y=x1-a/b*y1; //返回之后，d x1 y1都有所更新
	return d;
}
ll excrt(ll m[],ll r[])//使用扩欧算法，n个同余方程合并n-1次
{
	ll m1,m2,r1,r2,p,q;
	m1=m[1],r1=r[1];
	for(int i=2;i<=n;i++)//合并
	{
		m2=m[i],r2=r[i];
		ll d=exgcd(m1,m2,p,q);
		if((r2-r1)%d) return -1;
		p=p*(r2-r1)/d;//特解
		p=(p%(m2/d)+m2/d)%(m2/d);
		r1=m1*p+r1;
		m1=m1*m2/d;
	}
	return (r1%m1+m1)%m1;
}
signed main()
{
	scanf("%lld", &n);
	for(int i=1;i<=n;i++)
	 scanf("%lld%lld", m+i, r+i);
	printf("%lld\n",excrt(m,r));
	return 0;
}