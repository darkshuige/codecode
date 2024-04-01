#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=20;
int n;
int m[maxn],r[maxn];
//O(nlogc)
//中国剩余定理 解决模数两两互质的线性同于方程组
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
int crt(int m[],int r[])
{
	int M=1,ans=0;
	for(int i=1;i<=n;i++) M*=m[i];//计算所有模的积
	for(int i=1;i<=n;i++)
	{
		int c=M/m[i],x,y; //计算每个i的c[i]
		exgcd(c,m[i],x,y);
		ans=(ans+r[i]*c*x%M)%M;//r是题目中给出的余数，这里x就是c的乘法逆元
	}
	return (ans%M+M)%M;//找最小正整数
}
signed main()
{
	jiasu;
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>m[i]>>r[i];
	cout<<crt(m,r)<<endl;
	return 0;
}