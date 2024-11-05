#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
#define INF 2147483647
using namespace std;
const int maxn=200005;
const int mod=998244353;
int a[maxn],b[maxn];
int ksm(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = res*a;
		a = a*a;
		b >>= 1;
	}
	return res;
}
void divide(int l,int r)
{
	if(l+1==r) return ;
	memcpy(b,a,sizeof b);
	int now=0;
	int mid=l+r>>1;
	for(int i=l;i<=r;i++)
	{
		if(i<=mid)
		{
			a[i]=b[(i-l)*2+l];
		}
		else
		{
			int mid=(r-l)>>1;
			a[i]=b[(i-l-mid)*2-1+l];
		}
		now++;
	}
	divide(l,mid);
	divide(mid+1,r);
	memcpy(b,a,sizeof a);
}
signed main()
{
	jiasu;
	int n,m; cin>>n>>m;
	for(int i=0;i<ksm(2,n);i++)
	 a[i]=i;
	divide(0,ksm(2,n)-1);
	for(int i=0;i<ksm(2,n);i++)
	 cout<<a[i]<<" ";
	return 0;
}
