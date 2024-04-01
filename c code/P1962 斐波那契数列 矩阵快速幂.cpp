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
	int c[3][3];
	matrix(){memset(c,0,sizeof c);}
}a,res;
int n,k;
matrix mul(matrix a,matrix b)
{
	matrix t;
	for(int i=1;i<=2;i++)
	 for(int j=1;j<=2;j++)
	  for(int k=1;k<=2;k++)
	   t.c[i][j]=(t.c[i][j]+a.c[i][k]*b.c[k][j])%mod;
	return t;
}
void skm(int k)
{
	res.c[1][1]=1;res.c[1][2]=1;a.c[1][1]=1;a.c[1][2]=1;a.c[2][1]=1;
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
	cin>>n;
	if(n<=2)
	{
		cout<<1<<endl;
		return 0;
	}
	skm(n-2);
	cout<<res.c[1][1]<<endl;
	return 0;
}