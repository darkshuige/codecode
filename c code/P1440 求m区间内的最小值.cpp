#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define int long long
#define endl "\n"
using namespace std;
const int maxn=2000005;	
int f[maxn][22];
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>f[i][0];
	for(int j=1;j<=20;j++)
	 for(int i=1;i+(1<<j)-1<=n+m-1;i++)
	  f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	cout<<0<<endl;
	for(int i=1;i<=m-1;i++)
	{
		int l,r;
		l=1,r=i;
		int k=log2(r-l+1);
		cout<<min(f[l][k],f[r-(1<<k)+1][k])<<endl;
	}
	for(int i=m+1;i<=n;i++)
	{
		int l,r;
		l=i-m,r=i-1;
		int k=log2(r-l+1);
		cout<<min(f[l][k],f[r-(1<<k)+1][k])<<endl;
	}
	return 0;
}
