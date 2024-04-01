#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=1000005*3+6;
//扩展欧几里得算法
//求 ax+by=gcd(a,b)的特解 通过迭代
//求出特解就可以构造通解
//x=x0+ b/gcd(a,b)*k
//y=y0+ a/gcd(a,b)*k
//若c % gcd(a,b)==0 则有整数解，特解*c/gcd(a,b)
// (c/g*x0%(b/g)+b/g)%(b/g))最小解式子
int exgcd(int a,int b,int &x,int &y)//x y引用因为也要返回
{
	if(b==0)//原来的欧几里得算法，辗转相除法
	{
		x=1,y=0;
		return a;
	}
	int x1,y1,d;
	d=exgcd(b,a%b,x1,y1);
	x=y1,y=x1-a/b*y1; //返回之后，d x1 y1都有所更新
	return d;
}
signed main()
{
	jiasu;
	int x,y,m,n,l,x0,y0; cin>>x>>y>>m>>n>>l;
	int a=n-m,b=l,c=x-y;
	if(a<0) a=-a,c=-c;//最大公约数只对正数有效，b本来就是正数没干系
	int g=exgcd(a,b,x0,y0);
	if(c%g) cout<<"Impossible"<<endl;
	else cout<<(c/g*x0%(b/g)+b/g)%(b/g)<<endl;
	return 0;
}