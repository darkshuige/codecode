#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=200;
const int mod=1000000007;
struct matrix
{
	int c[maxn][maxn];
	matrix(){memset(c,0,sizeof c);}
}a,res;
int n,k;
matrix mul(matrix a,matrix b)
{
	matrix t;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  for(int k=1;k<=n;k++)
}
void skm(matrix a,int k)
{
	for(int i=1;i<=n;i++) res.c[i][i]=1;
	while(k)
	{
		if(k & 1) res=mul(res,a);
		a=mul(a,a);
		k>>=1;
	}
}
signed main()
{
	jiasu;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  cin>>a.c[i][j];
	skm(a,k);
	return 0;
}