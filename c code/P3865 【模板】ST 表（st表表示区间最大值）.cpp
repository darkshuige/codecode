#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=100005;
int f[maxn][22];
signed main()
{
	jiasu;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>f[i][0];
	for(int j=1;j<=20;j++)
	 for(int i=1;i+(1<<j)-1<=n;i++)
	  f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		int k=log2(r-l+1);
		cout<<max(f[l][k],f[r-(1<<k)+1][k])<<endl;
	}
	return 0;
}
