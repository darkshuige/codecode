#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
#define lc p<<1
#define rc p<<1|1 
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int mod=1000000007;
const int maxn=405;
int n,a[maxn][maxn*2];
int ksm(int a,int n)
{
	int res=1;
	while(n)
	{
		if(n & 1) res=(res*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return res;
}
bool gauss_jordan()
{
	for(int i=1;i<=n;i++) //枚举主元的行列
	{
		int r=i;
		for(int k=i;k<=n;k++)//找非0行
		{
			if(a[k][i])
			{
				r=k;
				break;
			}
		}	
		if(r!=i) swap(a[r],a[i]);//换行
		if(!a[i][i]) return 0;
	
		int x=ksm(a[i][i],mod-2);
		for(int k=1;k<=n;k++)
		{
			if(k==i) continue;
			int t=a[k][i]*x%mod;
			for(int j=i;j<=2*n;j++)
			 a[k][j]=((a[k][j]-t*a[i][j])%mod+mod)%mod;	
		}
		for(int j=1;j<=2*n;j++)//除以主元
		 a[i][j]=(a[i][j]*x%mod);
	}
	return 1;
}
signed main()
{
	jiasu;
	cin>>n;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  cin>>a[i][j],a[i][i+n]=1;
	if(gauss_jordan())
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=n+1;j<=2*n;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else
	 cout<<"No Solution"<<endl;
	return 0;
}