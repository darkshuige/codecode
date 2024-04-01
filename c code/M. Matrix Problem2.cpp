#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=600;
int n,L,R,a[200001];
unsigned long long seed;
unsigned long long xorshift64()
{
	unsigned long long x = seed;
	x^=x<<13;
	x^=x>>7;
	x^=x<<17;
	return seed=x;
}
int gen()
{
	return xorshift64() % (R-L+1)+L;
}
signed main()
{
	scanf("%d%d%d%llu",&n,&L,&R,&seed);
	for(int i=1;i<=n;i++)
	 a[i]=gen();
	
	return 0;
}